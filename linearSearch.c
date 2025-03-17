#include<stdio.h>
//Given for lab record.
int main(){
    int a[100], n, i, ele, flag = 0;
    printf("Enter how many elements(Max 100): ");
    scanf("%d",&n);
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the element to search: ");
    scanf("%d",&ele);
    for (int i = 0; i < n; i++)
    {
        if (a[i]==ele)
        {
            printf("Element found at index %d\n", i);
            flag = 1;
            break;
        }
    }
    if (flag==0)
        printf("Element not found.\n");
    return 0;
}