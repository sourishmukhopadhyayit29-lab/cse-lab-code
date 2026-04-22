Day6: Function & Recursion

Lab Assignment

1. Write a menu-driven program to, 
a) Calculate the factorial of a given number,
b) Check whether the number is prime or not,
c) Check whether the number is a palindrome or not.
Use different functions for each of the above tasks and call the functions from main using switch statement.


  #include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    int i, fact = 1;
    for(i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to check prime
int isPrime(int n) {
    int i;
    if(n <= 1)
        return 0;

    for(i = 2; i <= n/2; i++) {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

// Function to check palindrome
int isPalindrome(int n) {
    int original = n, reversed = 0, remainder;

    while(n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    return (original == reversed);
}

int main() {
    int choice, num;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Factorial\n");
        printf("2. Prime Check\n");
        printf("3. Palindrome Check\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 3) {
            printf("Enter a number: ");
            scanf("%d", &num);
        }

        switch(choice) {
            case 1:
                printf("Factorial = %d\n", factorial(num));
                break;

            case 2:
                if(isPrime(num))
                    printf("Prime number\n");
                else
                    printf("Not a prime number\n");
                break;

            case 3:
                if(isPalindrome(num))
                    printf("Palindrome number\n");
                else
                    printf("Not a palindrome\n");
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 4);

    return 0;
}
