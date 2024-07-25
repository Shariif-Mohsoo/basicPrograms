#include<iostream>
using namespace std;
class circularQueue
{
    int *queue;
    int size;
    int front;
    int rear;
    public:
    circularQueue();
    void enQue(int);
    void deQue();
    void display();
    void peek();
    void performOperations();
    ~circularQueue();
};
//let's beging with the function definitions of class
circularQueue::circularQueue()
{
    cout<<"Enter the size of queue: ";
    cin>>size;
    queue = new int[size];
    front = rear = -1;
}
void circularQueue::enQue(int data)
{
    if(((rear + 1) % size) == front)
    {
        cout<<"Overflow"<<endl;
    }
    else if(rear == -1 && front == -1)
    {
        rear = front = 0;
        queue[rear] = data;
    }
    else
    {
        rear = (rear + 1) % size;
        queue[rear] = data;
    }
}
void circularQueue::deQue()
{
    if(rear == -1 && front ==-1)
    {
        cout<<"Underflow"<<endl;
    }
    else if(front == rear)
    {
        cout<<queue[front]<<" is deQueued"<<endl;
        front = rear = -1;
    }
    else 
    {
        cout<<queue[front]<<" is deQueued"<<endl;
        front = (front + 1)%size;
    }
}
void circularQueue::peek()
{
    if(rear == -1 && front == -1)
        cout<<"Empty Queue"<<endl;
    else 
        cout<<queue[front]<<" is at top"<<endl;
}
void circularQueue::display()
{
    if(rear == -1 && front == -1)
        cout<<"Empty Queue"<<endl;
    else
    {
        int i = front;
        cout<<"Queue: ";
        while(i != rear)
        {
            cout<<queue[i]<<" ";
            i = (i + 1) % size;
        }
        cout<<queue[i];
        cout<<endl;
    }
}
void circularQueue::performOperations()
{
    int choice;
    cout<<"|======================================================|"<<endl;
    cout<<"                 Enter 1 to enqueue data                "<<endl;
    cout<<"                 Enter 2 to dequeue data                "<<endl;
    cout<<"                 Enter 3 to display data                "<<endl;
    cout<<"                 Enter 4 to display  top                "<<endl;
    cout<<"                 Enter 5 to exit form it                "<<endl;
    cout<<"|======================================================|"<<endl;
    cout<<"\n\tEnter your choice: ";
    cin>>choice;
    //lets check the choice
    switch(choice)
    {
        case 1:
        {
            int item;
            cout<<"Enter input: ";
            cin>>item;
            this->enQue(item);
            break;
        }
        case 2:
        {
            this->deQue();
            break;
        }
        case 3:
        {
            this->display();
            break;
        }
        case 4:
        {
            this->peek();
            break;
        }    
        case 5:
        {
            cout<<"\n\t\tThnks Dear"<<endl;
            exit(0);
        }
        default:
        {
            cout<<"Invalid Input"<<endl;
            this->performOperations();
        }
    }
    this->performOperations();
}
circularQueue::~circularQueue()
{
    delete [] queue;
}
//main function
int main()
{
    circularQueue queue;
    queue.performOperations();
    return 0;
}

