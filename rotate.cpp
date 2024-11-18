#include<iostream>
using namespace std;

void swap(int *a, int *b, int *c, int *d)
{
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = *d;
    *d = temp;
}

void print(int* start)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
            cout << *(start + 4 * i + j) << "\t";
        cout << "\n";
    }
}

void rotate(int *arr, int size)
{
    for(int i = 0; i < size / 2; i++)
        for(int j = 0; j < size / 2; j++) 
        {
            swap(
                arr + i*size + j, 
                arr + j*size + (3-i),
                arr + (3-i)*size + (3-j),
                arr + (3-j)*size + i
                );
            cout << "Step " << (size/2) * i + j + 1 <<  ":\n";
            print(arr);
            cout << "\n";
        }
}

int main()
{
    int array[4][4] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Initial Matrix:\n";
    
    print(&array[0][0]);
    
    cout << "\n";

    rotate(&array[0][0], 4);

    cout << "Final Output:\n";

    print(&array[0][0]);
    
    return 0;
}
