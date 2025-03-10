#include <stdio.h>
// int BinarySearch(int arr[], int size, int target)
// {
//     int low = 0, high = size - 1;
//     while (low <= high)
//     {
//         int mid = (low + high) / 2;
//         if (arr[mid] == target)
//             return mid;
//         else if (arr[mid] < target)
//             low = mid + 1;
//         else
//             high = mid - 1;
//     }
//     return -1;
// }

int main()
{
    int n;
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements(In a sorted manner): \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int target, found = 0;
    printf("Enter the element you want to search: ");
    scanf("%d", &target);
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            printf("Element found at index: %d", mid);
            found = 1;
            break;
        }
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    // int result = BinarySearch(arr, n, target);
    if (!found)
        printf("Element not found");
    return 0;
}