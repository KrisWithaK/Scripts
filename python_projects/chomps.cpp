
// Board.h
#include <iostream>
#include <vector>

#define ROWS 4
#define COLS 4

// 2D point
struct Point2D{
    int x = 0;
    int y = 0;

    // from game x,y to computer index x,y
    Point2D transformToComp(){
        this->x = this->x-1;
        this->y = ROWS-this->y;
    }
    Point2D transformToGame(){
        x = x + 1;
        y = ROWS - y;
    }

    bool operator!=(const Point2D& rhs){
        return rhs.x != this->x || rhs.y != this->y;
    }
    bool operator==(const Point2D& rhs){
        return rhs.x == this->x && rhs.y == this->y;
    }
};


// Board.h
class Board{

    bool board[COLS][ROWS];


public:
    Board();
    int makeMoveGamePts(int x, int y);
    int makeMoveGamePts(Point2D pt);
    int makeMoveCompPts(int x, int y);
    int makeMoveGamePts(Point2D pt);
    void printBoard();
    void reset();

};


// Board.cpp
Board::Board(){

    for(int i = 0; i < COLS; i++){
        for(int j = 0; j < ROWS; j++){
            board[i][j] = 1;
        }
    }

}

int Board::makeMoveGamePts(int x, int y){
    Point2D comp_index = Point2D{x,y}.transformToComp();

    if(comp_index.x >= COLS || comp_index.y >= ROWS || comp_index.x < 0 || comp_index.y < 0 || board[comp_index.x][comp_index.y] == 0){
        return -1;
    }
    else{
        int startX = comp_index.x;
        int startY = comp_index.y;
        for( ; startX < COLS && board[startX][startY] == 1; startX++){
            for( ; startY >= 0 && board[startX][startY] == 1; startY--){
                board[startX][startY] = 0;
            }
            startY = comp_index.y;
        }
        return 1;
    }

}

int Board::makeMoveGamePts(Point2D pt){
    return makeMoveGamePts(pt.x, pt.y);
}
int Board::makeMoveCompPts(int x, int y){
    return makeMoveCompPts(Point2D{x,y});
}
int Board::makeMoveCompPts(Point2D pt){
    pt.transformToGame();
    return makeMoveGamePts(pt);
}

void Board::printBoard(){
    for(int y = 0; y < COLS; y++){
        for(int x = 0; x < ROWS; x++){

            std::cout << " | " << board[x][y];
            
            if(x == COLS-1){
                std::cout << " |";
            }
        }
        std::cout << "\n";
    }
}

void Board::reset(){
    for(int i = 0; i < COLS; i++){
        for(int j = 0; j < ROWS; j++){
            board[i][j] = 1;
        }
    }
}


// Player.h
class Player{

    std::vector<Point2D> moves;

public:

    Point2D findMove(Board brd);
    void reset();
};

// Player.cpp
Point2D Player::findMove(Board brd){

}
void Player::reset(){
    moves.clear();
}


// GameTree.h
class GameTree{
    static Board START_BOARD;

    struct Edge;
    struct Node{
        Board brd;
        std::vector<Edge*> actions;
    };
    struct Edge{
        int weight = 0;
        Point2D move;
        Node* next;
    };

    Node* HEAD;
    void makeTree(Node* head);
    
public:
    GameTree();
};

// GameTree.cpp
GameTree::GameTree(){
    HEAD = &Node{START_BOARD,std::vector<Edge*>};
    makeTree(HEAD);
}

void GameTree::makeTree(Node* head){
    for(int x = 0; x < COLS; x++){
        for(int y = 0; y < ROWS; y++){
            if(board[0][0] == 1){
                if(x != 0 && y != ROWS-1){
                    head->actions.push_back(&Edge{0,Point2D{x,y}.transformToGame(),&Node{head->brd.makeMoveCompPts(x,y)}});
                }
            }
        }
    }
    for(int i = 0; i < head->actions.size(); i++){
        makeTree(head->actions[i]->next);
    }
    
}


// main function
int main(){ 


    Board brd;
    Player player1;
    Player player2;
    int winner = 0;

    for(int i = 0; i < 1500; i++){
        while( true ){
            if(player1.findMove(brd) == Point2D{1,1}){
                winner = 2;
            }
            brd.makeMove(player1.findMove(brd).x, player1.findMove(brd).y);
            if(player2.findMove(brd) == Point2D{1,1}){
                winner = 1;
            }
        }


        // if player2 wins
        if(winner == 2){

        }


        // if player 1 wins
        if(winner == 1){

        }




        player1.reset();
        player2.reset();
        brd.reset();
    }





}