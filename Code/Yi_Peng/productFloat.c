#include <stdio.h>
float sumFloat(float a, float b);



float main() {
    float float1, float2, sum;
    printf("Enter first float: ");
    scanf("%f", &float1); // read input to float 1
    printf("Enter second float: ");
    scanf("%f", &float2); // Read input into float2
    sum = sumFloat(float1, float2);
    printf("summation of %f * %f = %f\n", float1, float2, sum);
    return(0);
}

float sumFloat(float a, float b) {
    float sum = 0;
    sum = a * b;
    return sum;
}


