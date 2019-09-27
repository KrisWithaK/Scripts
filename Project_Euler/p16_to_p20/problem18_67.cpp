
#include "problem18.h"

void VectorToGraph(std::vector<std::vector<int>> rows, int height, int index, Node* curr, int endHeight){

    // set value
    curr->value = 0;

    // set left
    if(curr->left == nullptr){
        Edge* leftSideE = new Edge;
        curr->left = leftSideE;

        if(curr->prev_left != nullptr && curr->prev_left->left->next != nullptr && curr->prev_left->left->next->right->next != nullptr){
            leftSideE->next = curr->prev_left->left->next->right->next;
            leftSideE->next->prev_right = curr;
        }
        else{
            Node* leftSideN = new Node;
            leftSideE->next = leftSideN;
            leftSideE->next->prev_right = curr;
        }

        // set weight
        leftSideE->weight = rows[height + 1][index];
    }
    
    
    // set right
    if(curr->right == nullptr){
        Edge* rightSideE = new Edge;
        Node* rightSideN = new Node;
        curr->right = rightSideE;
        rightSideE->next = rightSideN;
        rightSideN->prev_left = curr;

        // set weight
        rightSideE->weight = rows[height + 1][index];
    }
    
    // end condition
    if(height + 1 >= endHeight - 1){

        // set values for last nodes
        curr->right->next->value = 0;
        curr->left->next->value = 0;

        // nullptr to leaf nodes
        curr->right->next->left = nullptr;
        curr->right->next->right = nullptr;
        curr->left->next->left = nullptr;
        curr->left->next->right = nullptr;

        return;
    }

    // recursive calls
    if(curr->left->next->left == nullptr){
        VectorToGraph(rows, height + 1, index, curr->left->next, endHeight);
    }
    if(curr->right->next->left == nullptr){
        VectorToGraph(rows, height + 1, index + 1, curr->right->next, endHeight);
    }  
}

bool TextToVector(std::string file, std::vector<std::vector<int>>& vectorOfLines){

    std::ifstream in(file.c_str());

    if(!in){
        std::cerr << "Cannot open file: " << file << std::endl;
        return false;
    }

    std::string str;
    int index = 0;

    while(std::getline(in, str)){

        vectorOfLines.push_back(std::vector<int>());
        char lastC = ' ';

        for(char& c : str){
            if(lastC == ' '){
                vectorOfLines[index].push_back( std::stoi ( std::string(1, c)  +  std::string(1, *(&c + 1)), nullptr, 10 ) );
            }
            lastC = c;
        }
        index++;
    }
    in.close();
    return true;

}

void removeGraph(int height, int index, Node* curr, int endHeight){
    // end condition
    if(curr->left == nullptr && curr->right == nullptr){
        delete curr;

        return;
    }

    // recursive call left
    if(curr->left->next != nullptr){
        removeGraph(height + 1, index, curr->left->next, endHeight);
    }
    // delete edge as you go up
    delete curr->left;

    if(curr->right->next != nullptr){
        removeGraph(height + 1, index + 1, curr->right->next, endHeight);
    }
    // delete edge as you go up
    delete curr->right;

    // remove node
    delete curr;
}

int dijekstraAlgo(Node* graph){


    std::vector<Node*> discoveredNodes;
    std::vector<int> possiblePathLengths;


    discoveredNodes.push_back(graph);

    while(discoveredNodes.size() > 0){

        // check if leaf node
        if(discoveredNodes[0]->left == nullptr && discoveredNodes[0]->right == nullptr){
            possiblePathLengths.push_back(discoveredNodes[0]->value);
        }

        if(discoveredNodes[0]->left != nullptr && discoveredNodes[0]->right != nullptr){

        
            // step 1: node discovery
            if(std::find(discoveredNodes.begin(), discoveredNodes.end(), discoveredNodes[0]->left->next) == discoveredNodes.end()){
                discoveredNodes.push_back(discoveredNodes[0]->left->next);
            }
            if(std::find(discoveredNodes.begin(), discoveredNodes.end(), discoveredNodes[0]->right->next) == discoveredNodes.end()){
                discoveredNodes.push_back(discoveredNodes[0]->right->next);
            }

            // step 2: add longest paths to nodes
            if(discoveredNodes[0]->left->next->value < discoveredNodes[0]->left->weight + discoveredNodes[0]->value){
                discoveredNodes[0]->left->next->value = discoveredNodes[0]->left->weight + discoveredNodes[0]->value;
            }
            if(discoveredNodes[0]->right->next->value < discoveredNodes[0]->right->weight + discoveredNodes[0]->value){
                discoveredNodes[0]->right->next->value = discoveredNodes[0]->right->weight + discoveredNodes[0]->value;
            }
        }

        // step 3: remove node that was just used
        discoveredNodes.erase(discoveredNodes.begin());
    }

    int largest = 0;

    for(int i : possiblePathLengths){
        if(i > largest){
            largest = i;
        }
    }

    return largest;


}



void printVect(std::vector<std::vector<int>> vector){


    for(int i = 0; i < vector.size(); i++){
        for(int j = 0; j < vector[i].size(); j++){
            std::cout << vector[i][j] << " ";
        }
        std::cout << std::endl;
    }


}



int main(){

    int longestPathLength = 0;

    // problem details
    Node GRAPH;
    std::vector<std::vector<int>> ROWS_OF_TRIANGLE;
    const int TREE_HEIGHT = 100;
    const int START_HEIGHT = -1;
    const int START_INDEX = 0;
    const std::string FILE_NAME = "p067_triangle.txt";

    // text to vector
    TextToVector(FILE_NAME, ROWS_OF_TRIANGLE);

    // tree setup
    VectorToGraph(ROWS_OF_TRIANGLE, START_HEIGHT, START_INDEX, &GRAPH, TREE_HEIGHT);

    // dijekstra's algo for longest path
    longestPathLength = dijekstraAlgo(&GRAPH);

    // deconstruct graph
   // removeGraph(START_HEIGHT, START_INDEX, &GRAPH, TREE_HEIGHT);

    std::cout << longestPathLength << std::endl; 
}
