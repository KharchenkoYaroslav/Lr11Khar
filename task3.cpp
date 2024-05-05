#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("original.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string word;

    cout << "Enter word: ";
    cin >> word;

    int wordCount = 0;

    string pretendant;
    
    while (file >> pretendant) {
        if (pretendant == word){
            wordCount++;
        }
    }

    cout << "Word count: " << wordCount << endl;

    file.close();

    return 0;
}