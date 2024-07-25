#include<iostream>
using namespace std;
void display(int[],int);
void linearSearch(int[],int,int);
int randomInsertion(int[],int);
int randomDeletion(int[],int);
int main()
{
	int s = 6;
	int array[s] = {1,2,3,4,5,6};
	display(array,s);
	cout<<"Enter the item you wana search => ";
	int item;
	cin>>item;
	linearSearch(array,s,item);
	s = randomInsertion(array,s);
	display(array,s);
	s = randomDeletion(array,s);
	display(array,s);
	return 0;
}
void linearSearch(int array[],int size,int item)
{
	int flag = 0;
	for(int i = 0;i<size;i++)
	{
		if(array[i] == item)
		{
			flag = 1;
			break;
		}
	}
	if(flag)
		cout<<"Element exist in array"<<endl;
	else
		cout<<"Element not exist in array"<<endl;
}
int randomInsertion(int array[],int size)
{
	int item,pos;
	cout<<"Enter the position at which you wana insert item => ";
	cin>>pos;
	cout<<"Enter the item you wana insert ";
	cin>>item;
	for(int i = (size-1);i>=(pos-1);i--)
	{
		array[i+1] = array[i];
	}
	array[pos-1] = item;
	size = size + 1;
	return size;
}
int randomDeletion(int array[],int size)
{
	int pos;
	cout<<"Enter the item position you wana delete => ";
	cin>>pos;
	for(int i = (pos-1);i<size;i++)
	{
		array[i] = array[i+1];
	}
	size = size-1;
	return size;
}
void display(int array[],int size)
{
	for(int i = 0;i<size;i++)
	{
		cout<<"Element at index "<<i<<" => "<<array[i]<<endl;
	}
}

