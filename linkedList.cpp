#include <iostream>
using namespace std;
class node
{
    // public:
    int data;
    node *next;
    friend class linkedList;
};
// linked list
class linkedList
{
    node *head;
    node *temp;
    node *newNode;

public:
    void createList();
    void display();
    void insertAtBegin();
    void insertAtEnd();
    void insertAtMid();
};
void linkedList::createList()
{
    cout << "Hello World" << endl;
    cout << "Hello World" << endl;
    cout << "Hello World" << endl;
    cout << "Hello World" << endl;
    cout << "Hello World" << endl;
}
// function definitions
int main()
{
    linkedList l;
    l.createList();
    cout << "hello" << endl;
    cout << "hello" << endl;
    cout << "hello" << endl;
    cout << "hello" << endl;
    return 0;
}
