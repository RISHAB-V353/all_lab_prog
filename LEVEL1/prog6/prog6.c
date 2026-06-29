#include <stdio.h> //program Integer array using dynamic memory allocation.

#include <stdlib.h>

/* Function Prototypes */
int* create_array(int n);
void initialize_array(int *arr, int n);
void print_array(int *arr, int n);
void delete_array(int **arr);

int main()
{
    int n;
    int *arr = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid size\n");
        return 1;
    }

    /* Allocate memory */
    arr = create_array(n);
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    /* Initialize array */
    initialize_array(arr, n);

    /* Print array */
    printf("\nArray elements:\n");
    print_array(arr, n);

    /* Delete array */
    delete_array(&arr);

    return 0;
}

/* Function to allocate memory */
int* create_array(int n)
{
    int *arr = (int*) malloc(n * sizeof(int));
    return arr;  // returns base address of array
}

/* Function to initialize array */
void initialize_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
}

/* Function to print array */
void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Function to delete array */
void delete_array(int **arr)
{
    free(*arr);      // free memory
    *arr = NULL;     // avoid dangling pointer
}