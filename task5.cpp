#include <iostream>

using namespace std;

class Num
{
protected:
    int num;
public:
    Num(int n): num(n){};

    virtual void shownum(){
        cout << "Number: " << num << endl;
    }
};

class outhex: public Num
{
public:
    outhex(int n): Num(n){};

    void shownum(){
        cout << "Number in hex: " << hex << num << endl;
    }
};

class outoct: public Num
{
public:
    outoct(int n): Num(n){};

    void shownum(){
        cout << "Number in oct: " << oct << num << endl;
    }
};



int main()
{
    Num obj1 = Num(10);
    outhex obj2 = outhex(10);
    outoct obj3 = outoct(10);

    obj1.shownum();
    obj2.shownum();
    obj3.shownum();
    
    return 0;
}