#include <stdio.h>  //program 3

/* Structure Definition */
typedef struct{
    int length;
    int width;
    int area;
}Rectangle;

/* Function Prototypes */
void input_rectangles(int n, Rectangle rects[n]);
void calculate_areas(int n, Rectangle rects[n]);
int find_max_index(int n, Rectangle rects[n]);
void display_areas(int n, Rectangle rects[n]);
void display_max(Rectangle rects[], int max_index);

int main()
{
    int n, index;

    printf("Enter number of rectangles: ");
    scanf("%d", &n);

    if(n<1)
    {
        printf("Invalid number of rectangles\n");
        return 0;
    }
    
    Rectangle rects[n];
    
   input_rectangles(  n,   rects);
   calculate_areas(  n,   rects);
   index = find_max_index(  n,   rects);
   display_areas(  n,   rects);
   display_max(  rects, index);

    return 0;
}

/* Function to input rectangle details */
void input_rectangles(int n, Rectangle rects[n])
{
   for(int i=0; i<n; i++){
        printf("Enter length of rectangle %d: ", i+1);
        scanf("%d", &rects[i].length);
        // write code

        printf("Enter width of rectangle %d: ", i+1);
        scanf("%d", &rects[i].width);
        // write code
   }
}
   

/* Function to calculate areas */
void calculate_areas(int n, Rectangle rects[n])
{
    for(int i=0; i<n; i++){
        rects[i].area = rects[i].length * rects[i].width;
    }
        // write code to compute area
}

/* Function to display all areas */
void display_areas(int n, Rectangle rects[n])
{
    printf("\nAreas of rectangles:\n");
    for(int i=0; i<n; i++){
        printf("Rectangle %d area = %d\n", i+1, rects[i].area);
    }
}

/* Function to find index of rectangle with maximum area */
int find_max_index(int n, Rectangle rects[n])
{
    int index=0, largest = rects[0].area;
    for(int i=1; i<n; i++){
        if(largest < rects[i].area){
            index = i;
            largest = rects[i].area;
        }
    }
    return index;
        // write condition to update max_index
   
}

/* Function to display rectangle with maximum area */
void display_max(Rectangle rects[], int index)
{
    printf("\nRectangle %d has the largest area = %d\n", index+1, rects[index].area);
}