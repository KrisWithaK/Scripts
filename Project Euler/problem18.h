#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

struct Edge;

struct Node{
    int value;
    Edge* left;
    Edge* right;
};

struct Edge{
    int weight;
    Node* next;

};
