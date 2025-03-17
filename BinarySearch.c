#include <stdio.h>
//This is the prohgram using function.


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
    //This Program is Explained in classroom.


    // int n;
    // printf("Enter the number of elements of the array: ");
    // scanf("%d", &n);
    // int arr[n];
    // printf("Enter the elements(In a sorted manner): \n");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }
    // int target, found = 0;
    // printf("Enter the element you want to search: ");
    // scanf("%d", &target);
    // int low = 0, high = n - 1;
    // while (low <= high)
    // {
    //     int mid = (low + high) / 2;
    //     if (arr[mid] == target)
    //     {
    //         printf("Element found at index: %d", mid);
    //         found = 1;
    //         break;
    //     }
    //     else if (arr[mid] < target)
    //         low = mid + 1;
    //     else
    //         high = mid - 1;
    // }
    // // int result = BinarySearch(arr, n, target);
    // if (!found)
    //     printf("Element not found");
    
    //This is given for lab reecord

    
    int a[100], n, ele, low, mid, high, f = 0;
    printf("Enter how many elements(Max100): ");
    scanf("%d", &n);
    printf("Enter elements of array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter element to search: ");
    scanf("%d", &ele);
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (a[j]> a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1]= temp;
            }            
        }        
    }
    low = 0, high = n-1;
    while (low<=high)
    {
        mid = (low+high)/2;
        if (ele<a[mid])
            high = mid-1;
        else if(ele>a[mid])
            low = mid+1;
        else{
            printf("Element found.\n");
            f = 1;
            break;
        }     
    }
    if (f==0)
        printf("Element not found.\n");
    return 0;
}