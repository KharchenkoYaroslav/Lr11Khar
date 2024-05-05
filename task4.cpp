#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream file("output2.txt", ios::out);

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string str = "";

    file.seekp(80, ios::beg);

    file << "Text";

    file.close();

    return 0;
}