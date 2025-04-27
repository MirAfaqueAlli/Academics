#include <stdio.h>
int binarySearch(int arr[], int low, int high, int target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] > target)
        {
            high = mid - 1;
        }
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 3, 5, 7, 10, 11, 14, 16, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    printf("Enter element to search: ");
    scanf("%d", &target);
    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
        printf("Element not found.\n");

    return 0;
}