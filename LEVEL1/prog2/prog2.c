#include <stdio.h> //program 2

/* Structure Definition */
typedef struct {
    int length;
    int width;
    int area;
} Rectangle;

/* Function Prototypes */
void input(Rectangle *rect);
int calculate_area(Rectangle rect);
int compare_areas(Rectangle r[]);
void output(int result, Rectangle r[]);

int main() {
    int n = 3;
    Rectangle r[n];
    int result;

    for(int i = 0; i < n; i++) {
        printf("Enter details of Rectangle %d\n", i + 1);
        input(&r[i]);   // pass address
    }

    /* Calculate areas */
    for(int i = 0; i < n; i++) {
        r[i].area = calculate_area(r[i]);
    }

    /* Compare areas */
    result = compare_areas(r);

    /* Output result */
    output(result, r);

    return 0;
}

/* Function to read rectangle details */
void input(Rectangle *rect) {

    printf("Enter length: ");
    scanf("%d", &rect->length);

    printf("Enter width: ");
    scanf("%d", &rect->width);
}

/* Function to calculate area */
int calculate_area(Rectangle rect) {
    return rect.length * rect.width;
}

/* Function to compare areas */
int compare_areas(Rectangle r[]) {

    if (r[0].area > r[1].area && r[0].area > r[2].area)
        return 1;
    else if (r[1].area > r[0].area && r[1].area > r[2].area)
        return 2;
    else if (r[2].area > r[0].area && r[2].area > r[1].area)
        return 3;
    else if (r[0].area == r[1].area && r[0].area > r[2].area)
        return 12;
    else if (r[0].area == r[2].area && r[0].area > r[1].area)
        return 13;
    else if (r[1].area == r[2].area && r[1].area > r[0].area)
        return 23;
    else
        return 123;
}

/* Function to display result */
void output(int result, Rectangle r[]) {

    printf("\nResult:\n");

    if(result == 1)
        printf("Rectangle 1 has the largest area = %d\n", r[0].area);

    else if(result == 2)
        printf("Rectangle 2 has the largest area = %d\n", r[1].area);

    else if(result == 3)
        printf("Rectangle 3 has the largest area = %d\n", r[2].area);

    else if(result == 12)
        printf("Rectangle 1 and Rectangle 2 have the largest equal area = %d\n", r[0].area);

    else if(result == 13)
        printf("Rectangle 1 and Rectangle 3 have the largest equal area = %d\n", r[0].area);

    else if(result == 23)
        printf("Rectangle 2 and Rectangle 3 have the largest equal area = %d\n", r[1].area);

    else
        printf("All three rectangles have the same area = %d\n", r[0].area);
}