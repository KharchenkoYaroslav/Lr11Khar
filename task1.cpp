#include <iostream>
#include <iomanip>
using namespace std;

ostream &SCUP(ostream &stream){
    stream << uppercase << scientific;
    return stream;
}


int main()
{
    cout << SCUP << 123.456 << endl;

    return 0;
}