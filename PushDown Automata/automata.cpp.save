#include "automata.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

istream& operator>>(istream& file, Automat& object) {
    int n;
    ///reading the states q0, q1, ...
    file >> n;
    for(int i = 0; i < n; i++) {
        char state;
        file >> state;
        object.Q.insert(state);
    }

    ///reading the letters
    file >> n;
    for(int i = 0; i < n; i++) {
        char letter;
        file >> letter;
        object.S.insert(letter);
    }

    ///reading the stack alphabet
    file >> n;
    for(int i = 0; i < n; i++) {
        char letter;
        file >> letter;
        object.G.insert(letter);
    }

    ///reading the transitions
    file >> n;
    for(int i = 0; i < n; i++) {
        Automat::transition newTrans;
        file >> newTrans.initState >> newTrans.wRead >> newTrans.sRead >> newTrans.sWrite >> newTrans.destState;
        object.d.push_back(newTrans);
    }

    ///reading initial and final states and Z0
    file >> object.q0 >> object.Z0;
    file >> n;
    for (int i = 0; i < n; i++){
        char state;
        file >> state;
        object.F.insert(state);
    }
    return file;
}

bool Automat::eval(string w) {
    map<char, set<stack<char> > > currentConfigurations;    ///activating the set of current states
    stack<char> auxStack;                                   ///activating q0 and Z0
    auxStack.push(Z0);                                      ///initial stack has Z0 as value and first state is q0
    currentConfigurations[q0].insert(auxStack);

    ///current letter
    for(string::iterator letter = w.begin(); letter != w.end()  &&  !currentConfigurations.empty(); letter++){
        ///each transition
        for(map<char, set<stack<char> > >::iterator configuration = currentConfigurations.begin(); configuration != currentConfigurations.end(); configuration++){
            cout<<configuration->first<<":\n";

            for(set<stack<char> >::iterator stackk = configuration->second.begin(); stackk != configuration->second.end(); stackk++){
                stack<char> cs = *stackk;
                while(!cs.empty()){
                    cout<<cs.top()<<' ';
                    cs.pop();
                    }
                cout<<"\n";
            }
        }

        ///the set of next configurations to be activated
        map<char, set<stack<char> > > nextConfigurations;
        ///activated configuration to be evaluated
        for(map<char, set<stack<char> > >::iterator configuration = currentConfigurations.begin(); configuration != currentConfigurations.end(); configuration++){
            for(vector<Automat::transition>::iterator trans = d.begin(); trans != d.end(); trans++){
                if(trans->initState == configuration->first && (trans->wRead == '-' || trans->wRead == *letter)){
                    for(set<stack<char> >::iterator stackk = configuration->second.begin(); stackk != configuration->second.end(); stackk++){
                        if(stackk->top() == trans->sRead){
                            stack<char> newStack = *stackk;
                            newStack.pop();
                            if(trans->sWrite[0] != '-')
                                for(string::reverse_iterator sLetter = trans->sWrite.rbegin(); sLetter != trans->sWrite.rend(); sLetter++)
                                    newStack.push(*sLetter);
                            nextConfigurations[trans->destState].insert(newStack);
                        }
                    }
                }
            }
        }
        ///activating the next states
        currentConfigurations = nextConfigurations;
    }

///searching for final states through the set of activated sets (in the end)
for(map<char, set<stack<char> > >::iterator configuration = currentConfigurations.begin(); configuration != currentConfigurations.end(); configuration++)
    if(F.find(configuration->first) != F.end()) return true;
return false;
}

///displaying the final stack
void Automat::showCurrentStack(ostream& out) const{
	stack<char> stackCopy = st;
    while(!stackCopy.empty()){
        out<<stackCopy.top();
        stackCopy.pop();
    }
}
