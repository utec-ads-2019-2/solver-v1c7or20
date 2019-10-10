//
// Created by Usuario on 25/09/2019.
//
#ifndef SOLVER_V1C7OR20_NODE_H
#define SOLVER_V1C7OR20_NODE_H

#include <stack>
#include <string>
#include <cmath>
#include "functions.cpp"
#include <map>

using namespace std;

class Node {
    string data ;
    Node *left;
    Node *right;
public:
    map<char ,double >* maps{};

    Node();

    explicit Node(stack<string> &str);

    double execute(map<char , double > *mapa){
        double r, l;
        char rig= right->data[0];
        char lef= left->data[0];
            if (isOperator(rig) and isOperator(lef)){
                r = right->execute(mapa);
                l = left->execute(mapa);
            } else
                if (isOperator(lef)){
                l = left->execute(mapa);
                if (isVariable(rig)){
                    if ((mapa->find(rig) == mapa->end())){
                        cout<<"Enter variable "<< rig<<endl;
                        cin>>r;
                        mapa->insert(pair<char, double >(rig,r));
                    }else
                        r = mapa->operator[](rig);
                }else {
                    r = atof((right->data).c_str());
                }
            }else if(isOperator(rig)){
                r = right->execute(mapa);
                if (isVariable(lef)  ){
                    if ((mapa->find(lef) == mapa->end())){
                        cout<<"Enter variable "<< left->data<<endl;
                        cin>>l;
                        mapa->insert(pair<char, double >(lef,l));
                    }else
                        l = mapa->operator[](lef);

                }else {
                    l = atof((left->data).c_str());
                }
            }else {
                if (isVariable(lef) ){
                    if ((mapa->find(lef) == mapa->end())){
                        cout<<"Enter variable "<< left->data<<endl;
                        cin>>l;
                        mapa->insert(pair<char, double >(lef,l));
                    }else
                        l = mapa->operator[](lef);
                }else {
                    l = atof((left->data).c_str());
                }
                if (isVariable(rig)){
                    if ((mapa->find(rig) == mapa->end())){
                        cout<<"Enter variable "<< right->data<<endl;
                        cin>>r;
                        mapa->insert(pair<char, double >(rig,r));
                    }else
                        r = mapa->operator[](rig);
                }else {
                    r = atof((right->data).c_str());
                }
            }
        return  doOperator(this->data[0],l,r);
    }

    void killSelf() {
        if(left != nullptr){
            left->killSelf();
        }
        if(right != nullptr){
            right->killSelf();
        }
        delete this;
    }

};

Node::Node() {
    data = "" ;
    left = nullptr;
    right= nullptr;
}

Node::Node(stack<string> &str) {
    this->data = str.top();
    str.pop();
    if(isOperator(this->data.at(0)) and  !str.empty()){
        left = new Node(str);
        right = new Node(str);
    }
    maps= new map<char , double >;
}


#endif //SOLVER_V1C7OR20_NODE_H
