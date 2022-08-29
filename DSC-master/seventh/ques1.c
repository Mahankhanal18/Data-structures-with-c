// 1.Tower of hanoi program using recursion
#include <stdio.h>
void towerOfHanoi(int numberOfDisks, char fromPos, char toPos, char bridgePosition)
{
    if (numberOfDisks == 1)
    {
        printf("\n Move disk 1 from  %c to  %c", fromPos, toPos);
        return;
    }
    towerOfHanoi(numberOfDisks - 1, fromPos, bridgePosition, toPos);
    printf("\n Move disk %d from  %c to  %c", numberOfDisks, fromPos, toPos);
    towerOfHanoi(numberOfDisks - 1, bridgePosition, toPos, fromPos);
}
int main()
{
    int numberOfDisks;
    printf("Number of Disks: ");
    scanf("%d", &numberOfDisks);
    printf("The sequence :\n");
    towerOfHanoi(numberOfDisks, 'A', 'B', 'C');
    return 0;
}