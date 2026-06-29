#include<stdio.h>

void input(int arr[], int n);
void swap(int arr1[], int arr2[], int n);
void output(int arr1[], int arr2[], int n);

int main(){
    int n;

    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    if(n<1){
        printf("Invalid Size!");
        return 0;
    }

    int arr1[n], arr2[n];
    
    printf("Enter elements in array1: \n");
    input(arr1, n);

    printf("Enter elements in array2: \n");
    input(arr2, n);

    swap(arr1, arr2, n);

    output(arr1, arr2, n);

    return 0;
}

void input(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void swap(int arr1[], int arr2[], int n){
    int temp[n];
    for(int i=0; i<n; i++){
        temp[i] = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp[i];
    }
}

void output(int arr1[], int arr2[], int n){
    printf("After swapping....\n");
    printf("Elements of array1: \n");
    for(int i=0; i<n; i++){
        printf("Element %d: %d\n", i+1, arr1[i]);
    }
    printf("Elements of array2: \n");
    for(int i=0; i<n; i++){
        printf("Element %d: %d\n", i+1, arr2[i]);
    }
}