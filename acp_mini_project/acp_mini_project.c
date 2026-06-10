#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_OBJECTS 100

typedef enum {
    LINE,
    RECTANGLE,
    CIRCLE,
    TRIANGLE
} ShapeType;

typedef struct {
    ShapeType type;
    int x1, y1, x2, y2, x3, y3;
    int r;
} Object;

char canvas[HEIGHT][WIDTH];

Object objects[MAX_OBJECTS];
int objectCount = 0;

Object undoObjects[MAX_OBJECTS];
int undoCount = 0;

void clearCanvas() {
    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            canvas[i][j] = '_';
}

void putPixel(int x, int y) {
    if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
        canvas[y][x] = '*';
}

void displayCanvas() {
    printf("\n");
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++)
            printf("%c", canvas[i][j]);
        printf("\n");
    }
}

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while(1) {
        putPixel(x1, y1);

        if(x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if(e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if(e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void drawRectangle(int x1, int y1, int x2, int y2) {
    if(x1 > x2) { int t = x1; x1 = x2; x2 = t; }
    if(y1 > y2) { int t = y1; y1 = y2; y2 = t; }

    for(int x = x1; x <= x2; x++) {
        putPixel(x, y1);
        putPixel(x, y2);
    }

    for(int y = y1; y <= y2; y++) {
        putPixel(x1, y);
        putPixel(x2, y);
    }
}

void drawCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    while(y >= x) {
        putPixel(xc + x, yc + y);
        putPixel(xc - x, yc + y);
        putPixel(xc + x, yc - y);
        putPixel(xc - x, yc - y);

        putPixel(xc + y, yc + x);
        putPixel(xc - y, yc + x);
        putPixel(xc + y, yc - x);
        putPixel(xc - y, yc - x);

        x++;

        if(d > 0) {
            y--;
            d += 4 * (x - y) + 10;
        } else {
            d += 4 * x + 6;
        }
    }
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}

void saveState() {
    undoCount = objectCount;

    for(int i = 0; i < objectCount; i++)
        undoObjects[i] = objects[i];
}

void redrawCanvas() {
    clearCanvas();

    for(int i = 0; i < objectCount; i++) {
        switch(objects[i].type) {

            case LINE:
                drawLine(objects[i].x1, objects[i].y1,
                         objects[i].x2, objects[i].y2);
                break;

            case RECTANGLE:
                drawRectangle(objects[i].x1, objects[i].y1,
                              objects[i].x2, objects[i].y2);
                break;

            case CIRCLE:
                drawCircle(objects[i].x1, objects[i].y1,
                           objects[i].r);
                break;

            case TRIANGLE:
                drawTriangle(objects[i].x1, objects[i].y1,
                             objects[i].x2, objects[i].y2,
                             objects[i].x3, objects[i].y3);
                break;
        }
    }
}

void addObject(Object obj) {
    if(objectCount >= MAX_OBJECTS) {
        printf("Object limit reached.\n");
        return;
    }

    saveState();

    objects[objectCount++] = obj;
    redrawCanvas();
}

void listObjects() {
    if(objectCount == 0) {
        printf("\nNo objects present.\n");
        return;
    }

    printf("\nObject Information:\n");

    for(int i = 0; i < objectCount; i++) {
        printf("%d. ", i + 1);

        switch(objects[i].type) {

            case LINE:
                printf("Line (%d,%d)->(%d,%d)\n",
                       objects[i].x1, objects[i].y1,
                       objects[i].x2, objects[i].y2);
                break;

            case RECTANGLE:
                printf("Rectangle (%d,%d)->(%d,%d)\n",
                       objects[i].x1, objects[i].y1,
                       objects[i].x2, objects[i].y2);
                break;

            case CIRCLE:
                printf("Circle Center=(%d,%d) Radius=%d\n",
                       objects[i].x1, objects[i].y1,
                       objects[i].r);
                break;

            case TRIANGLE:
                printf("Triangle (%d,%d) (%d,%d) (%d,%d)\n",
                       objects[i].x1, objects[i].y1,
                       objects[i].x2, objects[i].y2,
                       objects[i].x3, objects[i].y3);
                break;
        }
    }
}

void deleteObject(int index) {
    if(index < 0 || index >= objectCount) {
        printf("Invalid object.\n");
        return;
    }

    saveState();

    for(int i = index; i < objectCount - 1; i++)
        objects[i] = objects[i + 1];

    objectCount--;
    redrawCanvas();
}

void moveObject(int index) {
    if(index < 0 || index >= objectCount)
        return;

    int dx, dy;

    printf("Enter dx dy: ");
    scanf("%d%d", &dx, &dy);

    saveState();

    objects[index].x1 += dx;
    objects[index].y1 += dy;
    objects[index].x2 += dx;
    objects[index].y2 += dy;
    objects[index].x3 += dx;
    objects[index].y3 += dy;

    redrawCanvas();
}

void resizeObject(int index) {
    if(index < 0 || index >= objectCount)
        return;

    saveState();

    switch(objects[index].type) {

        case LINE:
            printf("New x1 y1 x2 y2: ");
            scanf("%d%d%d%d",
                  &objects[index].x1,
                  &objects[index].y1,
                  &objects[index].x2,
                  &objects[index].y2);
            break;

        case RECTANGLE:
            printf("New x1 y1 x2 y2: ");
            scanf("%d%d%d%d",
                  &objects[index].x1,
                  &objects[index].y1,
                  &objects[index].x2,
                  &objects[index].y2);
            break;

        case CIRCLE:
            printf("New radius: ");
            scanf("%d", &objects[index].r);
            break;

        case TRIANGLE:
            printf("New x1 y1 x2 y2 x3 y3: ");
            scanf("%d%d%d%d%d%d",
                  &objects[index].x1,
                  &objects[index].y1,
                  &objects[index].x2,
                  &objects[index].y2,
                  &objects[index].x3,
                  &objects[index].y3);
            break;
    }

    redrawCanvas();
}

void undoLast() {
    objectCount = undoCount;

    for(int i = 0; i < undoCount; i++)
        objects[i] = undoObjects[i];

    redrawCanvas();
}

int main() {
    int choice, n;
    Object obj;

    clearCanvas();

    while(1) {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Add Line\n");
        printf("2. Add Rectangle\n");
        printf("3. Add Circle\n");
        printf("4. Add Triangle\n");
        printf("5. Delete Object\n");
        printf("6. Move Object\n");
        printf("7. Resize Object\n");
        printf("8. Object Information\n");
        printf("9. Display Canvas\n");
        printf("10. Undo\n");
        printf("0. Exit\n");
        printf("Choice: ");

        scanf("%d", &choice);

        switch(choice) {

            case 1:
                obj.type = LINE;
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",
                      &obj.x1,&obj.y1,
                      &obj.x2,&obj.y2);
                addObject(obj);
                break;

            case 2:
                obj.type = RECTANGLE;
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",
                      &obj.x1,&obj.y1,
                      &obj.x2,&obj.y2);
                addObject(obj);
                break;

            case 3:
                obj.type = CIRCLE;
                printf("Enter center x y radius: ");
                scanf("%d%d%d",
                      &obj.x1,&obj.y1,&obj.r);
                addObject(obj);
                break;

            case 4:
                obj.type = TRIANGLE;
                printf("Enter x1 y1 x2 y2 x3 y3: ");
                scanf("%d%d%d%d%d%d",
                      &obj.x1,&obj.y1,
                      &obj.x2,&obj.y2,
                      &obj.x3,&obj.y3);
                addObject(obj);
                break;

            case 5:
                listObjects();
                printf("Object number: ");
                scanf("%d",&n);
                deleteObject(n - 1);
                break;

            case 6:
                listObjects();
                printf("Object number: ");
                scanf("%d",&n);
                moveObject(n - 1);
                break;

            case 7:
                listObjects();
                printf("Object number: ");
                scanf("%d",&n);
                resizeObject(n - 1);
                break;

            case 8:
                listObjects();
                break;

            case 9:
                displayCanvas();
                break;

            case 10:
                undoLast();
                printf("Undo completed.\n");
                break;

            case 0:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}