#ifndef AUTOMATA_H_INCLUDED
#define AUTOMATA_H_INCLUDED

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <stack>
using namespace std;

class Automat {
    set<char> Q, S, F, G;
    char q0, Z0;
    ///struct for transition edges
    struct transition {
        char initState, wRead, sRead, destState;
        string sWrite;
        };
    vector<transition> d;
    stack <char> st;

public:
    //typedef transition trans;
    friend istream& operator>>(istream& file, Automat& object);
    bool eval(string w);
    void showCurrentStack(ostream& out) const;
};

#endif // AUTOMATA_H_INCLUDED



