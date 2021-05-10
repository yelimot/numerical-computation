// 250201075 Yasar Polatli

#include<stdio.h>
#include<math.h>

int main(){

// ABCDEFGHI is student number.
char c[] = "250201075";

float A = c[0]- '0';
float B = c[1]- '0';
float C = c[2]- '0';
float D = c[3]- '0';
float E = c[4]- '0';
float F = c[5]- '0';
float G = c[6]- '0';
float H = c[7]- '0';
float I = c[8]- '0';

// i. Write down the coordinates of the points P0 = (A, B), P1 = (H, I), and P2 = (C, D).
printf("Coordinates of the points:\n");
printf("P0 = (%f, %f), P1 = (%f, %f), P2 = (%f, %f) \n\n", A, B, H, I, C, D);

// ii. Write down the coefficients a0, a1, and a2 of the second degree polynomial interpolating the points P0, P1, and P2 using a method of your choice.
if (A == H || A == C || H == C){
    printf("WARNING! THIS ID REQUIRES DIVISION BY ZERO. \n\n");
}
else{
// Computations of coefficients one by one and total sum calculated at the end.
float a0 =  B / ((A-H)*(A-C));
float a1 =  I / ((H-A)*(H-C));
float a2 =  D / ((C-A)*(C-H));

float b0 = -(H+C)*B / ((A-H)*(A-C));
float b1 = -(A+C)*I / ((H-A)*(H-C));
float b2 = -(A+H)*D / ((C-A)*(C-H));

float c0 =  (H*C)*B / ((A-H)*(A-C));
float c1 =  (A*C)*I / ((H-A)*(H-C));
float c2 =  (A*H)*D / ((C-A)*(C-H));

float aTotal = a0 + a1 + a2;
float bTotal = b0 + b1 + b2;
float cTotal = c0 + c1 + c2;

printf("Polynomial with according to coefficients: %fx^2 + %fx + %f \n", aTotal, bTotal, cTotal);
printf("a0: %f\na1: %f\na2: %f\n\n",aTotal, bTotal, cTotal);
}

// iii. If we set the end points as P0 and P1, and set both control points as the mid-point in the line segment [P0, P1].
// P0 = (A, B), P1 = (H, I)
// x1=A   y1=B    x4=H    y4=I  x2and3=midpointX    y2and3=midpointY

// Control point coordinates.
float midpointX = (A+H)/2; 
float midpointY = (B+I)/2;

float bx, cx, dx, by, cy, dy;
bx = 3*(midpointX - A);
cx = 3*(midpointX - midpointX) - bx;
dx = H - A - bx - cx;

by = 3*(midpointY - B);
cy = 3*(midpointY - midpointY) - by;
dy = I - B - by - cy;

printf("Equations of the curve:\n");
printf("x(t) = %f + %ft + %ft^2 + %ft^3\n", A, bx, cx, dx);
printf("y(t) = %f + %ft + %ft^2 + %ft^3\n", B, by, cy, dy);
return 0;
}