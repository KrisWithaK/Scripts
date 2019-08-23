
#include "problem18.h"

void VectorToGraph(std::vector<std::vector<int>> rows, int height, int index, Node* curr, int endHeight){

    // THIS IS WHERE THE PROBLEM IS

    // set value
    curr->value = 0;

    // set left
    Edge* leftSideE = new Edge;
    Node* leftSideN = new Node;
    curr->left = leftSideE;
    leftSideE->next = leftSideN;

    // set right
    Edge* rightSideE = new Edge;
    Node* rightSideN = new Node;
    curr->right = rightSideE;
    rightSideE->next = rightSideN;

    // set weights
    leftSideE->weight = rows[height + 1][index];
    rightSideE->weight = rows[height + 1][index];

    // end condition
    if(height > endHeight){

        // set values for last nodes
        rightSideE->next->value = 0;
        leftSideE->next->value = 0;

        // nullptr to leaf nodes
        rightSideE->next->left = nullptr;
        rightSideE->next->right = nullptr;
        leftSideE->next->left = nullptr;
        leftSideE->next->right = nullptr;

        return;
    }

    // recursive calls
    VectorToGraph(rows, height + 1, index, leftSideE->next, endHeight);
    VectorToGraph(rows, height + 1, index + 1, rightSideE->next, endHeight);
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

        char lastC = ' ';
        vectorOfLines.push_back(std::vector<int>());

        for(char& c : str){
            if(lastC == ' '){
                vectorOfLines[index].push_back(int(c + *(&c + 1)));
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

int main(){

    std::cout << "works" << std::endl;

    int longestPathLength = 0;

    std::cout << longestPathLength << std::endl;

    // problem details
    Node GRAPH;
    std::vector<std::vector<int>> ROWS_OF_TRIANGLE;
    const int TREE_HEIGHT = 30;
    const int START_HEIGHT = -1;
    const int START_INDEX = 0;
    const std::string FILE_NAME = "problem18Triangle.txt";

    std::cout << longestPathLength << std::endl;

    // text to vector
    TextToVector(FILE_NAME, ROWS_OF_TRIANGLE);

    std::cout << FILE_NAME << std::endl;

    // tree setup
    VectorToGraph(ROWS_OF_TRIANGLE, START_HEIGHT, START_INDEX, &GRAPH, TREE_HEIGHT);

    std::cout << "vectorToGraph" << std::endl;

    /*

    // dijekstra's algo for longest path
    longestPathLength = dijekstraAlgo(&GRAPH);

    // deconstruct graph
    removeGraph(START_HEIGHT, START_INDEX, &GRAPH, TREE_HEIGHT);

    std::cout << longestPathLength << std::endl; */
}
