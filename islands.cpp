#include<iostream>
using namespace std;

int islands(int*);
bool findNextOne(int*, int*);

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
    cout << islands(&arr[0][0]);
    return 0;
}

int islands(int* ptr)
{
    int* temp = ptr;
    int count = 0;
    while(findNextOne(ptr, temp))
    {
        *ptr = 0;
        if((ptr - temp) % 5 != 0) {
            if(*(ptr--) == 1)
                *ptr = 0;
            else
                ptr++;
        }
        if((ptr - temp) % 5 != 4) {
            if(*(ptr++) == 1)
                *ptr = 0;
            else
                ptr--;
        }
        if(ptr - temp >= 5) {
            if(*(ptr -= 5) == 1)
                *ptr = 0;
            else
                ptr += 5;
        }
        if(!(ptr - temp < 25 && ptr - temp >= 20)) {
            if(*(ptr += 5) == 1)
                *ptr = 0;
            else
                ptr -= 5;
        }
        count++;
    }
    return count;
}

bool findNextOne(int* ptr, int* head)
{
    if(*ptr == 1)
        return true;
    while(ptr < head + 25)
    {
        if(*ptr == 1)
            return true;
        ptr++;
    }
    return false;
}