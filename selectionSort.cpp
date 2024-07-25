#include<iostream>
#define N 5
using namespace std;
void display(int [],int);
void sort(int[],int);
void swap(int&,int&);
int main()
{
	int array[N] = {20,10,5,25,15};
	display(array,N);
	sort(array,N);
	display(array,N);
	return 0;
}
void display(int array[],int size)
{
	for(int i = 0;i<size;i++)
	cout<<array[i]<<" ";
	cout<<endl;
}
void swap(int &x,int &y)
{
	//x = 10,y = 20
	x = x + y;//x = 10 + 20//30
	y = x - y;//y = 30 - 20//10
	x = x - y;//x = 30 - 10//20
}
void sort(int array[],int n)
{
	int min;
	for(int i = 0;i<n-1;i++)
	{
		min = i;
		for(int j = i+1;j<n;j++)
		{
			if(array[j]<array[min])
			min = j;
		}
		if(array[min]!=array[i])
		swap(array[min],array[i]);
	}
}
