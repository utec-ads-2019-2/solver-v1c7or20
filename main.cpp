#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

int main(){
    string postfixed = topost();
    stack<string> done;
    int place= 0;
    cout<<postfixed<<endl;
    makevector(done,postfixed);
    Node* arbol = new Node(done);
    cout<<arbol->execute(arbol->maps)<<endl;
    return 0;
}

/*
  Suma-Resta-Multiplicacion-Division
-Potencia-Parentesis*/