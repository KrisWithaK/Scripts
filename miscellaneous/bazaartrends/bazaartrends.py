from matplotlib import pyplot as plt
import pandas as pd
import numpy as np
import json
import requests
import tkinter as tk
from tkinter import ttk
import matplotlib as mp
mp.use("TkAgg")
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2Tk
from matplotlib.figure import Figure
import matplotlib.animation as animation
from matplotlib import style
import datetime


LARGE_FONT = ("Verdana", 12)
NORM_FONT = ("Verdana", 10)
SMALL_FONT = ("Verdana", 8)
style.use("ggplot")



#funds = 0
#basis = 0
#sell_price = 0
#profit = 0



productsList = requests.get('https://api.hypixel.net/skyblock/bazaar/products?key=b57e1b71-4f08-4c9d-aa7d-1f4211bbf31c').json()['productIds']
productsList.sort()
products = {}
for i in range(len(productsList)):
    products[i] = productsList[i]


    

class BazaarApp(tk.Tk):
    def __init__(self, *args, **kwargs):
        self.root = tk.Tk.__init__(self, *args, **kwargs)

        self.resampleSize = "15Min"
        self.dataPace = "1d"
        self.DateCounter = 9000
        self.candleWidth = 0.008
        self.topIndicator = "none"
        self.bottomIndicator = "none"
        self.middleIndicator = "none"
        self.EMAs = []
        self.SMAs = []

        icon = tk.PhotoImage(file = "appIcon.png")
        self.iconphoto(False, icon)
        tk.Tk.wm_title(self, "Bazaar Trends")

        container = tk.Frame(self)
        container.pack(side="top", fill="both", expand=True)
        container.grid_rowconfigure(0, weight=1)
        container.grid_columnconfigure(0, weight=1)

        menubar = tk.Menu(container)
        filemenu = tk.Menu(menubar, tearoff=0)
        filemenu.add_command(label="Save Settings", command = lambda: self.popupmsg("Not Supported Just Yet!"))
        filemenu.add_separator()
        filemenu.add_command(label="Exit", command=quit)
        menubar.add_cascade(label="File", menu=filemenu)

        
        dataTF = tk.Menu(menubar, tearoff=1)
        dataTF.add_command(label = "Tick", command=lambda: self.changeTimeFrame('tick'))
        dataTF.add_command(label = "1 Day", command=lambda: self.changeTimeFrame('1d'))
        dataTF.add_command(label = "3 Day", command=lambda: self.changeTimeFrame('3d'))
        dataTF.add_command(label = "1 Week", command=lambda: self.changeTimeFrame('7d'))

        menubar.add_cascade(label = "Data Time Frame", menu = dataTF)
        OHLCI = tk.Menu(menubar, tearoff=1)
        OHLCI.add_command(label = "Tick", command=lambda: self.changeSampleSize('tick'))
        OHLCI.add_command(label = "1 Minute", command=lambda: self.changeSampleSize('1Min', 0.0005))
        OHLCI.add_command(label = "5 Minute", command=lambda: self.changeSampleSize('5Min', 0.003))
        OHLCI.add_command(label = "15 Minute", command=lambda: self.changeSampleSize('15Min', 0.008))
        OHLCI.add_command(label = "30 Minute", command=lambda: self.changeSampleSize('30Min', 0.016))
        OHLCI.add_command(label = "1 Hour", command=lambda: self.changeSampleSize('1H', 0.032))
        OHLCI.add_command(label = "3 Hour", command=lambda: self.changeSampleSize('3H', 0.096))
        menubar.add_cascade(label="OHLC Interval", menu=OHLCI)






        topIndi = tk.Menu(menubar, tearoff=1)
        topIndi.add_command(label="None", command= lambda: self.addTopIndicator('none'))
        topIndi.add_command(label="RSI", command= lambda: self.addTopIndicator('none'))
        topIndi.add_command(label="MACD", command= lambda: self.addTopIndicator('none'))

        menubar.add_cascade(label="Top Indicator", menu=topIndi)


        mainI = tk.Menu(menubar, tearoff=1)
        mainI.add_command(label="None", command= lambda: self.addMiddleIndicator('none'))
        mainI.add_command(label="SMA", command= lambda: self.addMiddleIndicator('none'))
        mainI.add_command(label="EMA", command= lambda: self.addMiddleIndicator('none'))

        menubar.add_cascade(label="Main/middle Indicator", menu=mainI)


        bottomI = tk.Menu(menubar, tearoff=1)
        bottomI.add_command(label="None", command= lambda: self.addBottomIndicator('none'))
        bottomI.add_command(label="RSI", command= lambda: self.addBottomIndicator('none'))
        bottomI.add_command(label="MACD", command= lambda: self.addBottomIndicator('none'))

        menubar.add_cascade(label="Bottom Indicator", menu=bottomI)











        tk.Tk.config(self, menu=menubar)

        self.frames = {}

        frame = StartPage(container, self)
        self.frames[StartPage] = frame
        frame.grid(row=0, column = 0, sticky="nsew")

        frame = CommodityTrends(container, self)
        self.frames[CommodityTrends] = frame
        frame.grid(row=0, column = 0, sticky="nsew")


        self.show_frame(StartPage)



    #def addTopIndicator(self):



    def changeTimeFrame(self, tf):
        if(tf == "7d" and self.resampleSize == "1Min"):
            self.popupmsg("Too much data, choose smaller time frame or higher OHLC interval")
        else:
            self.dataPace = tf
            self.DateCounter = 9000

    def changeSampleSize(self, size, width):
        if(self.dataPace == "7d" and self.resampleSize == "1Min"):
            self.popupmsg("Too much data, choose smaller time frame or higher OHLC interval")
        elif(self.dataPace == "tick"):
            self.popupmsg("You're currently viewing tick data, not OHLC")
        else:
            self.resampleSize = size
            self.DateCounter = 9000
            self.candleWidth = width

    def show_frame(self, cont, COMMODITY_ID=-1):
        if(COMMODITY_ID != -1):
            self.frames[cont].render(ID=COMMODITY_ID)

        frame = self.frames[cont]
        frame.tkraise()

    def popupmsg(self, msg):
        popup = tk.Tk()

        popup.wm_title("!")
        label = ttk.Label(popup, text=msg, font=NORM_FONT)
        label.pack(side="top", fill="x", pady=10)
        b1 = ttk.Button(popup, text="Okay", command = popup.destroy)
        b1.pack()
        popup.mainloop()


        



class StartPage(tk.Frame):

    def __init__(self, parent, controller):
        root = tk.Frame.__init__(self,parent)
        label = tk.Label(self, text="Commodity List", font=LARGE_FONT)
        label.grid(pady=10,padx=10,columnspan=5)

        label = tk.Label(self, text="Profitibility Calculator", font=LARGE_FONT)
        label.grid(pady=10,padx=20,row=0, column=5)


        









        
        buttons = []
        for key in products:
            buttons.append( ttk.Button(self, text=products[key], command= lambda ID=key: controller.show_frame(CommodityTrends, COMMODITY_ID = ID ) ) )

        row = 1
        for i in range(len(buttons)):

            if(i > 5*row-1):
                row += 1
                buttons[i].grid(row=row, column=i-(row-1)*5)
            elif(i > 4):
                buttons[i].grid(row=row, column=i-(row-1)*5)
            else:
                buttons[i].grid(row=row, column=i)


                
            





class CommodityTrends(tk.Frame):
    

    def __init__(self, parent, controller):
        self.COMMODITY_ID = -1
        tk.Frame.__init__(self, parent)

        self.button1 = ttk.Button(self, text="Back to Commodity List", command= lambda: self.returnToHome(parent, controller)  )
        self.button1.pack()

        self.title = tk.Label(self, text="PLACEHOLDER", font=LARGE_FONT)
        

        self.api_data = "https://api.hypixel.net/skyblock/bazaar/product?key=b57e1b71-4f08-4c9d-aa7d-1f4211bbf31c&productId="


        self.f = Figure()
        self.a = self.f.add_subplot(111)

        self.canvas = FigureCanvasTkAgg(self.f, self)

        self.toolbar = NavigationToolbar2Tk(self.canvas, self)
        self.toolbar.update()

        self.canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=True)
        self.canvas._tkcanvas.pack(side=tk.BOTTOM, fill=tk.BOTH, expand=True)


        self.refreshTime = 120000   # refereshes every 2 minutes


        
    def refresh(self):
        if(self.COMMODITY_ID != -1):
            self.animate()



    def animate(self):

        if(self.COMMODITY_ID != -1):
            datalink = self.api_data+products[self.COMMODITY_ID]
            data_raw = requests.get(datalink).json()['product_info']

            buy_summary = pd.DataFrame(data_raw['buy_summary'])
            sell_summary = pd.DataFrame(data_raw['sell_summary'])
            quick_status = data_raw['quick_status']
            week_historic = pd.DataFrame(data_raw['week_historic'])
            week_historic['buyPrice'] = week_historic["sellCoins"]/week_historic["sellVolume"]
            week_historic['sellPrice'] = week_historic["buyCoins"]/week_historic["buyVolume"]

            week_historic['date'] = pd.to_datetime(week_historic['timestamp'],unit='ms')


                
            self.a.clear()
            self.a.plot_date(week_historic['date'],week_historic['buyPrice'],"#00A3E0", label="Instant Buy Price")
            self.a.plot_date(week_historic['date'],week_historic['sellPrice'], "#183A54", label="Instant Sell Price")
            
            self.a.set_title("Week's History\nLatest Sell Price: " + str(round(quick_status['sellPrice'],2)) + "     Latest Buy Price: " + str(round(quick_status['buyPrice'],2)))
            self.a.legend(bbox_to_anchor=(0,1.08,1,.102), loc=3, ncol=2, borderaxespad=0)
            

            self.canvas.draw()
            self.after(self.refreshTime, self.refresh)


        
    def render(self,ID):
        self.COMMODITY_ID = ID

        self.title.destroy()
        self.title = tk.Label(self, text=products[self.COMMODITY_ID], font=LARGE_FONT)
        self.title.pack(pady=10,padx=10,side=tk.TOP)
        self.animate()



    def returnToHome(self, parent, controller):
        self.COMMODITY_ID = -1
        controller.show_frame(StartPage)



app = BazaarApp()
app.geometry("1280x720")
app.mainloop()







