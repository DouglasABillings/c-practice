#include <stdio.h>

void printArray(int * arr, int n)
{
    for(int i = 0; i < n; i++)
        printf("%i%s", arr[i], i == n - 1 ? "\n" : " ");
}

void quicksort(int * arr, int n)
{
    if(n < 2)
        return;

    int l, r, p, t;
    p = arr[n / 2];

    for(l = 0, r = n - 1;; l++, r--)
    {
        while(arr[l] < p)
            l++;
        while(arr[r] > p)
            r--;
        if(l >= r)
            break;
        t = arr[l]; arr[l] = arr[r]; arr[r] = t;
    }

    quicksort(arr, l);
    quicksort(arr + l, n - l);
}

int main()
{
    int arr[] = { 10, 5, 3, 2, 1, 9, 8, 6, 7, 4 };
    int n = 10;

    printArray(arr, n);
    quicksort(arr, n);
    printArray(arr, n);

    return 0;
}
