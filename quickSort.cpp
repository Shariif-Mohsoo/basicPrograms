#include <iostream>
using namespace std;
void display(int[], int);
void swap(int &, int &);
int partition(int[], int, int);
void quickSort(int[], int, int);
int main()
{
    int size = 7;
    int array[size] = {10, 15, 1, 2, 9, 16, 11};
    display(array, size);
    quickSort(array, 0, size - 1);
    display(array, size);
    return 0;
}
void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int partition(int array[], int lb, int ub)
{
    int start = lb, end = ub;
    int pivot = array[lb];
    while (start <= end)
    {
        while (array[start] <= pivot)
            start++;
        while (array[end] > pivot)
            end--;
        if (start < end)
            swap(array[start], array[end]);
    }
    swap(array[lb], array[end]);
    return end;
}
void quickSort(int array[], int lb, int ub)
{
    if (lb >= ub)
        return;
    int loc = partition(array, lb, ub);
    quickSort(array, lb, loc - 1);
    quickSort(array, loc + 1, ub);
}