
// iv. Find MAXimum element in an array using recursion
#include <stdio.h>
#define MAX 100
#define MAXIMUM(a, b) (a > b ? a : b)
int greatEle(int arr[MAX], int num)
{
    if (num == 1)
        return arr[0];
    return MAXIMUM(greatEle(arr, num - 1), arr[num - 1]);
}

int main()
{

    int num, arr[MAX];

    printf("\n Enter the number of elements: \n");
    scanf("%d", &num);
    printf(" Enter elements : \n");
    for (int i = 0; i < num; i++)
        scanf("%d", &arr[i]);
    printf(" Greatest Element in the array = %d \n", greatEle(arr, num));
    return 0;
}