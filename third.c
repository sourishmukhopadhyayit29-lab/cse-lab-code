#include <stdio.h>
#include <math.h>
// Function to calculate factorial
long long factorial(int n) {
    long long fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n, attempts = 0;
    float x, sum = 1, term;
    
    // Input validation (max 5 attempts)
    while(attempts < 5) {
        printf("Enter value of n (<10): ");
        scanf("%d", &n);
        
        if(n > 0 && n < 10)
            break;
        else {
            printf("Invalid input!\n");
            attempts++;
        }
    }

    if(attempts == 5) {
        printf("Too many invalid attempts.\n");
        return 0;
    }

    printf("Enter value of x: ");
    scanf("%f", &x);

    // Series calculation
    for(int i = 1; i < n; i++) {
        int power = i;
        int fact_term = 2*i + 1;
        
        term = pow(x, power) / factorial(fact_term);
        
        if(i % 2 == 1)
            sum -= term;
        else
            sum += term;
    }

    printf("Sum = %f\n", sum);
    return 0;
}
