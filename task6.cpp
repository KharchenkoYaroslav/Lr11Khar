#include <iostream>
#include <iomanip>

using namespace std;

class Dist
{
protected:
    double dist;
public:
    Dist(int mile): dist(mile){};

    virtual void trav_time(){
        cout << "Trevel time = " << setprecision(4) << dist / 60 << " hours" << endl;
    }
};

class Metric: public Dist
{
public:
    Metric(int km): Dist(km){};

    void trav_time(){
        cout << "Trevel time = " << setprecision(4) << dist / 100 << " hours" << endl;
    }
};


int main()
{
    Dist obj1 = Dist(50);
    Metric obj2 = Metric(50);

    obj1.trav_time();
    obj2.trav_time();
    
    return 0;
}