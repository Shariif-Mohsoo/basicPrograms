#include<iostream>
using namespace std;
class playWithArray
{
	int *array;
	int size,item;
	public:
		playWithArray();
		void getData();
		void display();
		void linearSearch();
		void bubbleSort();
		void insertionSort();
		void selectionSort();
		void binarySearch();
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
		cout<<"First "<<i+1<<" item of an array => ";
		cin>>array[i];
	}
	cout<<endl;
}
void playWithArray::linearSearch()
{
	int flag=0;
	cout<<"\t\tHere we will the item which you wana search"<<endl;
	cout<<"\nEnter the item => ";
	cin>>item;
	for(int i = 0;i<size;i++)
	{
		if(array[i] == item)
		{
			flag = 1;
			break;
		}
	}
	if(flag)
		cout<<"\nItem exist in an array"<<endl;
	else	
		cout<<"\nItem doesn't exist in an array"<<endl;
}
void playWithArray::bubbleSort()
{
	cout<<"\nArray Sort Via Bubble Sort"<<endl;
	bool isSwapped;
	int temp;
	for(int i = 0;i<size-1;i++)
	{
		isSwapped = false;
		for(int j = 0;j<size-1-i;j++)
		{
			if(array[j]>array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				isSwapped = true;
			}
		}
		if(!isSwapped)
			break;
	}
}
void playWithArray::binarySearch()
{
	cout<<"\t\tHere we will see the item which you wana search"<<endl;
	cout<<"\nEnter the item => ";
	cin>>item;
	int lb,ub,mid;
	lb = 0;
	ub = size-1;
	while(lb<=ub)
	{
		mid = lb + (ub-lb)/2;
		if(array[mid] == item)
		{
			cout<<"\nElement exist in an array"<<endl;
			break;
		}
		else if(array[mid]>item)
			ub = mid-1;
		else 
			lb = mid+1;
	}
	if(lb>ub)
		cout<<"\nElement not exist"<<endl;
}
void playWithArray::display()
{
	cout<<"\nYour Array"<<endl;
	for(int i = 0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
void playWithArray::insertionSort()
{
	cout<<"\nInsertion Sort is applied"<<endl;
	int temp;
	int j;
	for(int i = 1;i<size;i++)
	{
		temp = array[i];
		j = i-1;
		while(j>=0&&array[j]>temp)
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = temp;
	}
}
void playWithArray::selectionSort()
{
	cout<<"\nApplying the selection sort"<<endl;
	int min,temp;
	for(int i = 0;i<size-1;i++)
	{
		min = i;
		for(int j = i+1;j<size;j++)
		{
			if(array[j]<array[min])
			min = j;
		}
		if(min!=i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
}
playWithArray::~playWithArray()
{
	cout<<"\n\t\tArray's story end"<<endl;
	delete [] array;
}
int main()
{
	playWithArray obj;
	obj.getData();
	obj.display();
	obj.linearSearch();
	obj.bubbleSort();
	obj.display();
	obj.insertionSort();
	obj.display();
	obj.selectionSort();
	obj.display();
	obj.binarySearch();
	return 0;
}
