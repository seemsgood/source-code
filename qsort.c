#include <stdio.h>

int sort(int *a, int left, int right);

int main(void)
{
    int a[] = {5,2,1,4,5};

    sort(a, 0, 4);

    for(int i = 0; i < 5; i++)
        printf("%d\n", a[i]);
}

int sort(int *a, int left, int right)
{
    if (left >= right)
        return;
    int i = left;
    int j = right;
    int key = a[left];
    while (i < j)
    {
        while (i < j && key <= a[j])
            j--;
        a[i] = a[j];
        while (i < j && key >= a[i])
            i++;
        a[j] = a[i];
    }
    a[i] = key;
    sort(a, left, i - 1);
    sort(a, i + 1, right);
}
