//
// Created by Usuario on 25/09/2019.
//

#ifndef SOLVER_V1C7OR20_NODE_H
#define SOLVER_V1C7OR20_NODE_H

#include <string>
#include "functions.cpp"

using namespace std;

class Node{
private:
    string data;
    Node* right;
    Node* left;
public:
    Node(){
        data = "";
        right = nullptr;
        left = nullptr;
    }

    Node(string data){
        this->data = data;
    }

    void make_node(string data, int &place){
        right = new Node(data);
        if (isOperator(data.at(place))){
        }
    }

    void execute(){

    }

};
#endif //SOLVER_V1C7OR20_NODE_H
