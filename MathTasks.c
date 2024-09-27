#include <stdio.h> 
#include <math.h> 
 
#define PI 3.14159265358979323846 
 
double calculate_z1(double a) { 
    double term1 = cos(3.0 / 8.0 * PI - a / 4.0); 
    double term2 = cos(11.0 * PI / 8.0 + a / 4.0); 
     
    return pow(term1, 2) - pow(term2, 2); 
} 
 
double calculate_z2(double a) { 
    return pow(sqrt(2), sin(a / 2)); 
} 
 
int main() { 
    double a; 
     
    printf("Enter the value of a (in radians): "); 
    scanf("%lf", &a); 
     
    double result_z1 = calculate_z1(a); 
    double result_z2 = calculate_z2(a); 
     
    printf("z1 = %.6f\n", result_z1); 
    printf("z2 = %.6f\n", result_z2); 
     
    return 0; 
}