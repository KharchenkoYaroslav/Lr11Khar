#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream source("original.txt");
    ofstream dest("output.txt");

    if (!source || !dest) {
        cout << "Error opening files!" << endl;
        return 1;
    }

    char c;

    source.unsetf(ios::skipws);

    while (!source.eof()){
        source >> c;
        if(!source.eof()){
            if(c == '\t'){
            dest << "    ";
            continue;
        }
        dest << c;
        }
    }

    source.close();
    dest.close();

    return 0;
}