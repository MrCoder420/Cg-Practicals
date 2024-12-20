#include <graphics.h>
#include <iostream>
using namespace std;

// Function for DDA line drawing algorithm
void drawLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));
    float xInc = dx / (float) steps;
    float yInc = dy / (float) steps;

    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++) {
        putpixel(x, y, WHITE);
        x += xInc;
        y += yInc;
    }
}

// Function for Bresenham's circle drawing algorithm
void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (y >= x) {
        putpixel(xc+x, yc+y, WHITE);
        putpixel(xc-x, yc+y, WHITE);
        putpixel(xc+x, yc-y, WHITE);
        putpixel(xc-x, yc-y, WHITE);
        putpixel(xc+y, yc+x, WHITE);
        putpixel(xc-y, yc+x, WHITE);
        putpixel(xc+y, yc-x, WHITE);
        putpixel(xc-y, yc-x, WHITE);
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
}

int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw patterns
    drawLine(50, 50, 200, 200);
    drawCircle(300, 300, 100);

    // Wait for user to close the window
    getch();
    closegraph();
    return 0;
}
