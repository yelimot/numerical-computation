// 250201075 Yasar Polatli

#include <stdio.h>

double max(double x, double y) {
    if (x > y) return x;
    return y;
}

void print_matrix(float matrix[3][3]) {
    for(int i=2; i >= 0; i--) {
        printf("");
        for(int j=0; j < 3; j++) {
            printf("%10lf ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void factorization() {
    float A[3][3];
    char* number = "250201075"; // Student number
    printf("Student number is %s\n\n", number);

    A[2][0] = number[0] - '0';
    A[1][0] = number[1] - '0';
    A[0][0] = number[2] - '0';
    A[2][1] = number[3] - '0';
    A[1][1] = (number[4] - '0') + 0.5;
    A[0][1] = number[5] - '0';
    A[2][2] = number[6] - '0';
    A[1][2] = number[7] - '0';
    A[0][2] = number[8] - '0';

    float L[3][3] = {{0,0,1}, {0,1,0}, {1,0,0}};
    float U[3][3];
    float sub;

    // Copy A matrix into the U matrix
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            U[i][j] = A[i][j];
        }
    }

    float s = U[1][0] / U[2][0];
    L[1][0] = s;

    // Subtruct Row 2 from Row 1
    for(int i=0; i<3; i++) {
        U[1][i] -= U[2][i] * s;
    }

    s = U[0][0] / U[2][0];
    L[0][0] = s;

    // Subtruct Row 3 from Row 1
    for(int i=0; i<3; i++) {
        U[0][i] -= U[2][i] * s;
    }

    // Subtruct Row 3 from Row 2
    s = U[0][1] / U[1][1];
    L[0][1] = s;

    for(int i=0; i<3; i++) {
        U[0][i] -= U[1][i] * s;
    }

    // Find c
    double c1 = 5 / L[2][0];
    double c2 = (12 - c1 * L[1][0]) / L[1][1];
    double c3 = (18  - c2 * L[0][1] - c1 * L[0][0]) / L[0][2];

    // Find x
    double x3 = c3 / U[0][2];
    double x2 = (c2 - x3 * U[1][2]) / U[1][1];
    double x1 = (c1 - x2 * U[2][1] - x3 * U[2][2]) / U[2][0];

    // Find ||[5, 12, 18] - A.[1, 1, 1]||
    double a1 = 5.0 - (A[2][0] + A[2][1] + A[2][2]);
    double a2 = 12.0 - (A[1][0] + A[1][1] + A[1][2]);
    double a3 = 18.0 - (A[0][0] + A[0][1] + A[0][2]);

    double relative_backward_error = max(max(a1, a2), a3) / max(max(5, 12), 18);
    double relative_forward_error = max(max((5 - 1), (12 - 1)), (18 - 1)) / max(max(5, 12), 18);
    double error_magnification = relative_forward_error / relative_backward_error;

    // Print matrices
    printf("A = \n");
    print_matrix(A);
    printf("L = \n");
    print_matrix(L);
    printf("U = \n");
    print_matrix(U);

    printf("c1 : %lf\n", c1);
    printf("c2 : %lf\n", c2);
    printf("c3 : %lf\n\n", c3);

    printf("x1 : %lf\n", x1);
    printf("x2 : %lf\n", x2);
    printf("x3 : %lf\n", x3);

    printf("\nRelative backward error: %lf\n", relative_backward_error);
    printf("Relative forward error: %lf\n", relative_forward_error);
    printf("Error Magnification Factor: %lf\n", error_magnification);
}

int main() {
    factorization();
    return 0;
}