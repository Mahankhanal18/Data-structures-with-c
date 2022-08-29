#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, noOfElements;
    int *arr;
    printf("Number of elements in array: ");
    scanf("%d", &noOfElements);
    // Creating the array
    arr = (int *)malloc(noOfElements * sizeof(int));
    if (arr == NULL)
    {
        printf("ERROR: MEMORY ALLOCATION FAIL\n");
        return 1;
    }
    // Entering the elements in the array
    printf("Enter %d elements\n", noOfElements);
    for (i = 0; i < noOfElements; ++i)
    {
        scanf("%d", &arr[i]);
    }
    // reading values of array
    printf("Array elements are:\n");
    for (i = 0; i < noOfElements; i++)
    {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}
