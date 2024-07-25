/*
LET'S START WITH THE MERGE SORT
*/
#include <iostream>
#define N 5
using namespace std;
void merge(int[], int, int);
void mergeSort(int[], int, int);
void display(int[], int);
int main()
{
    int array[N] = {40, 23, 21, 1, 2};
    display(array, N);
    mergeSort(array, 0, N - 1);
    display(array, N);
    return 0;
}
void merge(int array[], int lb, int ub)
{
    int mid = lb + (ub - lb) / 2; // finding the mid
    int len1 = mid - lb + 1;
    int len2 = ub - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    int k = lb;
    for (int i = 0; i < len1; i++)
        first[i] = array[k++];
    k = mid + 1;
    for (int i = 0; i < len2; i++)
        second[i] = array[k++];
    // merge the arrays now
    int idx1 = 0, idx2 = 0;
    k = lb;
    while (idx1 < len1 && idx2 < len2)
    {
        if (first[idx1] < second[idx2])
        {
            array[k++] = first[idx1++];
        }
        else
        {
            array[k++] = second[idx2++];
        }
    }
    while (idx1 < len1)
        array[k++] = first[idx1++];
    while (idx2 < len1)
        array[k++] = first[idx2++];
    delete[] first;
    delete[] second;
}
void mergeSort(int array[], int lb, int ub)
{
    if (lb >= ub)
        return;
    int mid = lb + (ub - lb) / 2;
    mergeSort(array, lb, mid);
    cout << "HI M"
         << " ";
    mergeSort(array, mid + 1, ub);
    cout << "HI "
         << " ";
    merge(array, lb, ub);
}
void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}