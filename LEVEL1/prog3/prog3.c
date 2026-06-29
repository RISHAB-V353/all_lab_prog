#include<stdio.h>

typedef struct{
    int length, width, area;
}Rectangles;

void input(Rectangles rects[], int n);
void calcarea(Rectangles rects[], int n);
int maxarea(Rectangles rects[], int n);
void output(Rectangles rects[], int n);

int main(){
    int n;

    printf("Enter the number of Rectangles: ");
    scanf("%d", &n);

    if(n<1){
        printf("Invalid number of rectangles!");
        return 0;
    }

    Rectangles rects[n];

    input(rects, n);
    calcarea(rects, n);
    int mindex = maxarea(rects, n);
    output(rects, mindex);

    return 0;

}

void input(Rectangles rects[], int n){
    printf("Enter the details: \n");
    for(int i=0; i<n; i++){
        printf("Enter length of rectangle%d: ", i+1);
        scanf("%d", &rects[i].length);
        printf("Enter width of rectangle%d: ", i+1);
        scanf("%d", &rects[i].width);
    }
}

void calcarea(Rectangles rects[], int n){
    for(int i=0; i<n; i++){
        rects[i].area = rects[i].length * rects[i].width;
    }
}

int maxarea(Rectangles rects[], int n){
    int index=0, largest = rects[0].area;
    for(int i=1; i<n; i++){
        if(largest < rects[i].area){
            largest = rects[i].area;
            index = i;
        }
    }

    return index;
}

void output(Rectangles rects[], int n){
    printf("The largest area is: %d of rectangle %d\n", rects[n].area, n+1);
}