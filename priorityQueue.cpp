#include<iostream>
using namespace std;
//clearing the class
class Queue
{
	int *queue;
	int size;
	int front;
	int rear;
	public:
		Queue();
		void enQue(int);
		void deQue();
		void display();
		void performOperations();
		~Queue();
		
};
Queue::Queue()
{
	cout<<"Enter the size of queue: ";
	cin>>size;
	queue = new int[size];
	front = rear = -1;
}
void Queue::enQue(int data)
{
	if(rear == size -1)
	{
		cout<<"Queue full/overflow"<<endl;
		return ;
	}
	else if(rear == -1 && front == -1)
	{
		rear = front = 0;
		queue[rear] = data;
	}
	else
	{
		int pos = rear;
		while(pos>=front)
		{
			if(data>queue[pos])
			{
				queue[pos+1] = queue[pos];
				pos--;
			}
			else
				break;
		}
		queue[pos+1] = data;
		rear = rear + 1;
	}
	
}
void Queue::deQue()
{
	int item;
	if(front == -1 && rear == -1)
	{
		cout<<"Queue Empty/underflow"<<endl;
		return ;
	}
	else if(front == rear)
	{
		item = queue[front];
		front = rear = -1;
	}
	else 
	{
		item = queue[front];
		front = front + 1;
	}
	cout<<item<<" is dequeued"<<endl;
}
void Queue::display()
{
	if(front == -1 && rear == -1)
	{
		cout<<"Queue empty";
		return;
	}
	cout<<endl<<endl<<"Queue: ";
	for(int i = front;i<=rear;i++)
	{
		cout<<queue[i]<<" ";
	}
	cout<<endl<<endl;
}
void Queue::performOperations()
{
	cout<<endl;
	cout<<"Enter 1 to enqueue"<<endl;
	cout<<"Enter 2 to dequeue"<<endl;
	cout<<"Enter 3 to display"<<endl;
	cout<<"Enter 4 to exit   "<<endl;
	cout<<endl;
	cout<<"Enter your choice: ";
	int choice;
	cin>>choice;
	//check the cases
	switch(choice)
	{
		case 1:
			{
				int data;
				cout<<"Enter value: ";
				cin>>data;
				this->enQue(data);
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
				cout<<"Thnks Dear"<<endl;
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
Queue::~Queue()
{
	delete [] queue;
}
int main()
{
	Queue queue;
	queue.performOperations();
	return 0;
}
