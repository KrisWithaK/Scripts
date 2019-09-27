

#include <iostream>




int main(){

    int longestStartNum = 0;
    int longestLength = 0;

    for(int currNum = 999999; currNum > 1; currNum--){

        long num = currNum;
        int length = 0;

        while(num > 1){
            if(num % 2 == 0){
                num = num / 2;
            }
            else if(num % 2 == 1){
                num = 3*num + 1;
            }
            length++;
        }

        if (length > longestLength){
            longestStartNum = currNum;
            longestLength = length;
        }
    }

    std::cout << longestStartNum << "\n" << longestLength << std::endl;
}