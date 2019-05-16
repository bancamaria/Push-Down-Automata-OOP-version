#include <iostream>
#include <fstream>
#include <string>
#include "automata.h"
using namespace std;
ifstream f("file.txt");

int main() {
    Automat A;
    f >> A;
    string w;
    f >> w;

    if(A.eval(w))
        cout << "Accepted word!";
    else
        cout << "Rejected word!";

    return 0;
}
