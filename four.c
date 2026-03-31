#include <stdio.h>
#include<math.h>
int main() {
    int amount;

    printf("Enter amount: ");
    scanf("%d", &amount);

    int notes[] = {100, 50, 10, 5, 2, 1};
    int count;

    printf("Minimum notes required:\n");

    for(int i = 0; i < 6; i++) {
        if(amount >= notes[i]) {
            count = amount / notes[i];
            printf("%d x %d\n", notes[i], count);
            amount = amount % notes[i];
        }
    }

    return 0;
}
