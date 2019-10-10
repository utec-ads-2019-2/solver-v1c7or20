//
// Created by Usuario on 26/09/2019.
//

#include <stack>
#include <string>
#include <iostream>

using namespace std;

bool isOperator(char character) {
    return character == '+' || character == '-' || character == '*' || character == '/' || character == '^';
}

bool isOperand(char character) {
    return !isOperator(character) && character != '(' && character != ')';
}

int compareOperators(char op1, char op2) {
    if ((op1 == '*' || op1 == '/' || op1 == '^') && (op2 == '+' || op2 == '-')) { return -1; }
    else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/' || op2 == '^')) { return 1; }
    return 0;
}

string topost(){
    stack<char> opStack;
    string postFixString = "";
    char input[100];
    cout << "Enter an expression: ";
    cin >> input;
    char *cPtr = input;
    while (*cPtr != '\0') {
        if (isOperand(*cPtr)) { postFixString += *cPtr; }
        else if (isOperator(*cPtr)) {
            while (!opStack.empty() && opStack.top() != '(' && compareOperators(opStack.top(),*cPtr) <= 0) {
                postFixString += opStack.top();
                opStack.pop();
            }
            postFixString += ' ';
            opStack.push(*cPtr);
        }
        else if (*cPtr == '(') { opStack.push(*cPtr);}
        else if (*cPtr == ')') {
            while (!opStack.empty()) {
                if (opStack.top() == '(') { opStack.pop(); break; }
                postFixString += opStack.top();
                opStack.pop();
            }
        }
        cPtr++;
    }
    while (!opStack.empty()) {
        postFixString += opStack.top();
        postFixString += ' ';
        opStack.pop();
    }
    return postFixString;
}

void makevector(stack<string> &str, string chain){
    string adder="";
    for (int i = 0; i < chain.size(); i++) {
        if (isOperand(chain[i]) and chain[i] != ' ') {
            adder += chain[i];
        }else if ((chain[i] == ' ' or isOperator(chain[i])) and !adder.empty()){
            str.push(adder);
            adder ="";
        } if (isOperator(chain[i])){
            adder += chain[i];
            str.push(adder);
            adder = "";
        }
    }
}

bool isVariable(char A){
    return (A>='A' and A<='Z');
}

double doOperator(char operador, double l ,double r){
    switch (operador){
        case '+':
            return (l+r);
        case '-':
            return (r-l);
        case '*':
            return (l*r);
        case '/':
            return (r/l);
        case '^':
            return pow(r,l);
    }
    throw out_of_range("Not recognizable operator");
}