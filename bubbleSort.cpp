#include <iostream>
using namespace std;
void display(int[], int);
void sort(int[], int);
int main()
{
    int size = 5;
    int array[size] = {15, 50, 402, 44, 102};
    display(array, size);
    sort(array, size);
    display(array, size);
    return 0;
}
void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
// bubble sort
void sort(int array[], int size)
{
    int temp, flag;
    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                flag = 1;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        if (flag == 0)
            break;
    }
}