#include<iostream>
using namespace std;

int islands(int[5][5]);
void searchIslands(int*, int*);

int main()
{
    int arr[5][5] =
    {
        {1, 1, 0, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };
    cout << islands(arr);
    return 0;
}

int islands(int arr[5][5])
{
    int count = 0;
    int* ptr;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            ptr = &arr[i][j];
            if(arr[i][j] == 1) {
                searchIslands(ptr, &arr[0][0]);
                count++;
            }
        }
    }

    return count;
}

void searchIslands(int* ptr, int* head)
{
    *ptr = 0;
    // Not on the left boundary
    if((ptr - head) % 5 != 0)
    {
        ptr--;
        if(*ptr == 1)
            searchIslands(ptr, head);
        else
            ptr++;
    }
    // Not on the bottom boundary
    if((ptr - head) < 20)
    {
        ptr += 5;
        if(*ptr == 1)
            searchIslands(ptr, head);
        else
            ptr -= 5;
    }
    // Not on the right boundary
    if((ptr - head) % 5 != 4)
    {
        ptr++;
        if(*ptr == 1)
            searchIslands(ptr, head);
        else
            ptr--;
    }
    // Not on the top boundary
    /* Handle this case
    1 1 0 1
    0 1 1 1
    */
}