#include <stdio.h>
#include<math.h>
int main() {
    int n;
    
    printf("Enter number of terms: ");
    scanf("%d", &n);

    int a = 0, b = 1, next;

    printf("Fibonacci Series:\n");

    for(int i = 0; i < n; i++) {
        if(i == 0)
            printf("%d ", a);
        else if(i == 1)
            printf("%d ", b);
        else {
            next = a + b;
            printf("%d ", next);
            a = b;
            b = next;
        }
    }

    return 0;
}
