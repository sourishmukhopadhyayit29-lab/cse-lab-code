
2. Write a recursive function to calculate the GCD (greatest common divisor) / HCF (Highest common
factor) of two numbers.
  
#include <stdio.h>

// Recursive function to find GCD
int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("GCD = %d\n", gcd(num1, num2));

    return 0;
}
