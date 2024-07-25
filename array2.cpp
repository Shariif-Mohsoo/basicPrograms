#include<iostream>
using namespace std;
class playWithArray
{
	int *array;
	int size,pos,item;
	public:
		playWithArray();
		void getData();
		void display();
		void insertFast();
		void deleteFast();
		void insertSlow();
		void deleteSlow();
		~playWithArray();
};
playWithArray::playWithArray()
{
	cout<<"Enter the size of an array => ";
	cin>>size;
	array = new int[size];
}
void playWithArray::getData()
{
	for(int i = 0;i<size;i++)
	{
		cout<<"Enter item number "<<i+1<<" => ";
		cin>>array[i];
	}
	cout<<endl;
}
void playWithArray::insertFast()
{
	int pos,item;
	if(pos<=0||pos>size) 
	{
		cout<<"Bro or sister invalid position try again"<<endl;
		insertFast();
	}
	cout<<"Enter position where you wana insert => ";
	cin>>pos;
	cout<<"Enter the item => ";
	cin>>item;
	array[size] = array[pos-1];
	array[pos-1] = item;
	size++;
}
void playWithArray::deleteFast()
{
	cout<<"Enter the position from where you wana delete: ";
	cin>>pos;
	if(pos<=0||pos>size) 
	{
		cout<<"Bro or sister invalid position try again"<<endl;
		insertFast();
	}
	item = array[pos-1];
	cout<<item<<" is deleted"<<endl;
	array[pos-1] = array[size-1];
	size--;
}
void playWithArray::insertSlow()
{
	cout<<"Enter the position from where you wana insert: ";
	cin>>pos;
	cout<<"Enter the item => ";
	cin>>item;
	if(pos<=0||pos>size) 
	{
		cout<<"Bro or sister invalid position try again"<<endl;
		insertFast();
	}
	for(int i = (size-1);i>=(pos-1);i--)
	{
		array[i+1] = array[i];	
	}	
	array[pos-1] = item;
	size++;
}
void playWithArray::deleteSlow()
{
	cout<<"Enter the position from where you wana delete: ";
	cin>>pos;
	if(pos<=0||pos>size) 
	{
		cout<<"Bro or sister invalid position try again"<<endl;
		insertFast();
	}
	item = array[pos-1];
	cout<<item<<" is deleted"<<endl;
	for(int i = (pos-1);i<(size-1);i++)
		array[i] = array[i+1];	
	size--;
}
void playWithArray::display()
{
	for(int i = 0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
playWithArray::~playWithArray()
{
	cout<<"Story End's Dear "<<endl;
	delete [] array;
}
//main function
int main()
{
	playWithArray obj;
	obj.getData();
	obj.display();
//	obj.insertFast();//best if array is unsorted
	obj.insertSlow();
	obj.display();
//	obj.deleteFast();//best if array is unsorted
	obj.deleteSlow();
	obj.display();
	return 0;
}
