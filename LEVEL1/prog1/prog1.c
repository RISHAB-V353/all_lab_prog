// program Maximum value in an array
#include<stdio.h>

void input(int arr[], int n);
int maxxer(int arr[], int n);
void output(int arr[], int n);

int main(){
    int n;

    printf("Enter number of elements: ");
    if(scanf("%d", &n) != 1 || n < 1){
        printf("Invalid size!");
        return 0;
    }

    int arr[n];

    input(arr, n);
    int mindex = maxxer(arr, n);
    output(arr, mindex);

    return 0;

}

void input(int arr[], int n){
    printf("Enter elements in the array: \n");
    for(int i=0; i<n; i++){
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

int maxxer(int arr[], int n){
    int largest = arr[0], index=0;
    for(int i=0; i<n; i++){
        if(largest < arr[i]){
            largest = arr[i];
            index = i;
        }
    }
    return index;
}

void output(int arr[], int n){
    printf("The largest values in the array is %d at index %d", arr[n], n+1);
}