// 250201075 Yasar Polatli

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* int_decimal_to_binary(double number){
    char binary[50];
    int n = floor(number);
    binary[0] = '\0';

    // Divides n by two and adds remaining integer to the string untill n is equal to 0
    for(int i=50; n != 0; i--) {
        if ((n % 2) == 0) strcat(binary, "0");
        else {
            // Last digit won't be added due to easier mantissa implementation.
            if(n/2 != 0) strcat(binary, "1");
        }
        n = n/2;
    }

    // Integers added to the string in the reverse order so we have to reverse the string before return.
    strrev(binary);
    char *type = malloc(60);
    strncpy(type, binary, 59);
    return(type);
}

char* float_decimal_to_binary(double number) {
    char binary[75];
    binary[0] = '\0';
    int n = ceil(number * 1000); 
    n = n-1000*floor(n/1000); // Last three digit

    for(int i=0; i < 75; i++) {
        n *= 2;
        if (n < 1000) strcat(binary, "0");
        else {
            strcat(binary, "1");
            n = n-1000*floor(n/1000); // Last three digit
        }
    }

    char *type = malloc(75);
    strncpy(type, binary, 74);
    return(type);
}

char* decimal_to_binary(double number) {
    char binary[126];
    binary[0] = '\0';
    strcat(binary, "1");
    strcat(binary, int_decimal_to_binary(number));
    strcat(binary, ".");
    strcat(binary, float_decimal_to_binary(number));

    binary[65] = '\0';
    char *type = malloc(70);
    strncpy(type, binary, 69);
    return(type);
}

char* round_down(char* binary) {
    binary[52] = '\0';
    char *type = malloc(60);
    strncpy(type, binary, 59);
    return(type);
}

char* round_up(char* binary) {
    // Adds 1 to the 52nd bit.
    for(int i=52; i>0; i--) {
        if(binary[i] == '0') {
            binary[i] = '1';
            break;
        }
        binary[i] = '0';
    }
    binary[52] = '\0';
    char *type = malloc(60);
    strncpy(type, binary, 59);
    return(type);
}

// Checks if there any zero after 53rd bit.
bool is_full_zero(char* binary) {
    for(int i=54; i<strlen(binary); i++) {
        if (binary[i] == '1') return false;
    }
    return true;
}

char* mantissa(double number) {
    char binary[150];

    strcat(binary, int_decimal_to_binary(number));
    strcat(binary, float_decimal_to_binary(number));

    char *type = malloc(150);
    strncpy(type, binary, 149);
    
    if(binary[52] == '0') {
        return round_down(type);
    }
    else {
        if (is_full_zero) {
            if (binary[52] == '1') {
                return round_up(type);
            }
            else {
                return round_down(type);
            }
        }
        else {
            return round_up(type);
        }
    }
}

int main() {
    char* number = "250201075"; // Student number
    printf("Student number is %s\n", number);

    int _num = 3 + 10*(number[8] - '0') + 100*(number[7] - '0') + 1000*(number[6] - '0') + 10000*(number[5] - '0');
    double num = ((double) _num/1000); // Y
    printf("Y = %lf\n\n", num);

    printf("Mantissa: %s\n", mantissa(ceilf(num * 1000.0) / 1000.0));
    printf("Decimal -> Binary: %s\n", decimal_to_binary(ceilf(num * 1000.0) / 1000.0));
    return 0;
}