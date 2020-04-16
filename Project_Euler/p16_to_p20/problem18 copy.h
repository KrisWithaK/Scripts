#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

struct Edge;

struct Node{
    Node* prev_left = nullptr;
    Node* prev_right = nullptr;
    int value = 0;
    Edge* left = nullptr;
    Edge* right = nullptr;
};

struct Edge{
    int weight = 0;
    Node* next = nullptr;

};
