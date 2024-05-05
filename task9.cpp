#include <iostream>
#include <cstdlib> 
using namespace std;

class list
{
public:
    list *head; // pointer to start of list
    list *tail; // pointer to end of list
    list *next; // pointer to next item 
    int num; // value to be stored
    list() { head = tail = next = NULL; }
    virtual ~list() {} 
    virtual void store(int i) = 0;
    virtual int retrieve() = 0;
    void operator+(int i);
    int operator-();
};

// Create a queue type list:
class queue : public list
{
public:
    void store(int i);
    int retrieve();
};

void queue::store(int i)
{
    list *item;
    item = new queue;
    if (!item)
    {
        cout << "Allocation error.\n";
        exit(1);
    }
    item->num = i;
    // put on end of list:
    if (tail){
        tail->next = item;
    }
    tail = item;
    item->next = NULL;
    if (!head){
        head = tail;
    }
}

int queue::retrieve()
{
    int i;
    list *p;
    if (!head)
    {
        cout << "List empty.\n";
        return 0;
    }
   
    // remove from start of list
    i = head->num;
    p = head;
    head = head->next;
    delete p;
    return i;
}

// Create a stack type list:
class stack : public list
{
public:
    void store(int i);
    int retrieve();
};

void stack::store(int i)
{
    list *item;
    item = new stack;
    if (!item)
    {
        cout << "Allocation error.\n";
        exit(1);
    }
    item->num = i;
    // put on front of list
    // for stack like operation
    if (head){
        item->next = head;
    }
    head = item;
    if (!tail){
        tail = head;
    }
}

int stack::retrieve()
{
    int i;
    list *p;
    if (!head)
    {
        cout << "List empty.\n";
        return 0;
    }
    // remove from start of list:
    i = head->num;
    p = head;
    head = head->next;
    delete p;
    return i;
}

void list::operator+(int i)
{
    store(i);
}

int list::operator-()
{
    return retrieve();
}

int main()
{
    list *p;
    // demonstrate queue:
    queue q_ob;
    p = &q_ob; // point to queue
    *p + 1;
    *p + 2;
    *p + 3;
    cout << "Queue: ";
    cout << -(*p);
    cout << -(*p);
    cout << -(*p);
    cout << '\n';
    // demonstrate stack:
    stack s_ob;
    p = &s_ob; // point to stack
    *p + 1;
    *p + 2;
    *p + 3;
    cout << "Stack: ";
    cout << -(*p);
    cout << -(*p);
    cout << -(*p);
    cout << '\n';
    return 0;
}