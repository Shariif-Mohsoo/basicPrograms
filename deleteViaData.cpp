#include<iostream>
using namespace std;
void deleteByData(int);
void createList();
void display();
class node
{
	public:
	int data;
	node *next;
}*head,*temp,*newNode;
int main()
{
	createList();
	display();
	int item;
	cout<<"Enter the data you wana delete => ";
	cin>>item;
	deleteByData(item);
	display();
	return 0;
}
void createList()
{
	head = 0;
	int choice = 1;
	while(choice)
	{
		newNode = new node;
		cout<<"Enter the data => ";
		cin>>newNode->data;
		newNode->next = 0;
		if(head == 0)
			head = temp = newNode;
		else 
		{
			temp->next = newNode;
			temp = newNode;
		}
		cout<<"To contine press 1 else 0 ";
		cin>>choice;
	}
}
void display()
{
	temp = head;
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
void deleteByData(int data)
{
	if(head == 0)
	{
		cout<<"Empty List"<<endl;
	}
	else if(head->data == data)
	{
		temp = head;
		cout<<head->data<<" is deleted "<<endl;
		head = head->next;
		delete temp;
	}
	else
	{
		node *preNode;
		temp = head;
		int flag = 0;
		while(temp->next != 0)
		{
			preNode = temp;
			temp = temp->next;
			if(temp->data == data)
			{	
				cout<<temp->data<<" is deleted "<<endl;
				preNode->next = temp->next;
				temp->next = 0;
				delete(temp);
				flag = 1;
				break;
			}
		}
		if(!flag)
			cout<<"Element not found"<<endl;
		
	}
}
