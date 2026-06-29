#include <stdio.h>  //program 1

/* Function Prototypes */
void input(int n, int arr[n]);
int find_max_index(int n, int arr[n]);
void output(int arr[], int index);

int main()
{
    int n, index;
    printf("Enter number of elements: ");

    if(scanf("%d", &n) != 1 ||n<1)
    {
        printf("Invalid array size\n");
        return 0;
    }
    
    int arr[n];
    
    input(n, arr);
    index = find_max_index(n, arr);
    output(arr, index);

    return 0;
}

/* Function to read array elements */
void input(int n, int arr[n])
{
    for(int i=0; i<n; i++){
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
}

/* Function to find index of maximum element */
int find_max_index(int n, int arr[n])
{
    int index = 0, largest = arr[0];
    for(int i=1; i<n; i++){
        if(largest < arr[i]){
            largest = arr[i];
            index = i;
        }
    }
    return index;
    
}

/* Function to display result */
void output(int arr[], int index)
{
    printf("Maximum value = %d\n",arr[index] );
    printf("Index of maximum value = %d\n", index);
}