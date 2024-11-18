#include<iostream>
#include<cmath>
using namespace std;

int comb(int n, int r)
{
    if(n == r - 1 || r == 1)
        return n;
    else if(n == r || r == 0)
        return 1;
    return comb(n - 1, r) + comb(n - 1, r - 1);
}

int findPath(int arr[4][4], int rows, int cols)
{
    char path[/*rows + cols - 2*/6];
    //int /*numberOfPaths*/ = comb(/*rows + cols - 2*/6, ((rows > cols) ? cols - 1 : rows - 1));
    int sumInPath[/*numberOfPaths*/20] = {0};
    int count = 0;
    for(int i = 0; i < /*rows + cols - 2*/6; i++) {
        for(int j = i + 1; j < /*rows + cols - 2*/6
; j++) {
            for(int k = j + 1; k < /*rows + cols - 2*/6
    ; k++) {
                path[i] = 'r';
                path[j] = 'r';
                path[k] = 'r';
                for(int l = 0; l < /*rows + cols - 2*/6
        ; l++)
                    if(path[l] != 'r')
                        path[l] = 'd';
                int *ptr = &arr[0][0];
                for(int i = 0; i < /*rows + cols - 2*/6; i++) {
                    if(path[i] == 'r') {
                        sumInPath[count] += *ptr;
                        ptr++;
                    }
                    else if(path[i] == 'd') {
                        sumInPath[count] += *ptr;
                        ptr += cols;
                    }
                }
                count++;
            }
        }
    }
    int shortestPathValue = sumInPath[0];
    for(int i = 1; i < /*numberOfPaths*/20; i++) {
        cout << sumInPath[i] << "\n";
        if(shortestPathValue > sumInPath[i])
            shortestPathValue = sumInPath[i];
    }
    return shortestPathValue;
}

int main()
{
    int arr[4][4] = {
        {1, 3, 5, 8},
        {4, 2, 1, 7},
        {4, 3, 2, 3},
        {5, 6, 1, 4}
    };

    cout << "The value of the sum in the shortest path is " << findPath(arr, 4, 4);
}