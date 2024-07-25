#include <iostream>
using namespace std;
void display(int[], int);
void sort(int[], int);
int main()
{
    int size = 5;
    int array[size] = {90, 80, 70, 60, 50};
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
void sort(int array[], int size)
{
    int temp, j;
    for (int i = 1; i < size; i++)
    {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}