#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX + 1];
int original[MAX + 1];
int n = 0;

int readInt(const char *prompt) {
    int x, ch;
    printf("%s", prompt);
    while (scanf("%d", &x) != 1) {
        while ((ch = getchar()) != '\n' && ch != EOF);
        if (ch == EOF) exit(0);
        printf("Invalid input. %s", prompt);
    }
    return x;
}

void inputArray() {
    int i, count;
    char prompt[40];
    count = readInt("Enter number of elements (max 100): ");
    if (count < 1 || count > MAX) {
        printf("Invalid size.\n");
        return;
    }
    n = count;
    for (i = 1; i <= n; i++) {
        sprintf(prompt, "Enter element %d: ", i);
        arr[i] = readInt(prompt);
        original[i] = arr[i];
    }
    printf("Array stored.\n");
}

void displayArray() {
    int i;
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array: ");
    for (i = 1; i <= n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void resetArray() {
    int i;
    for (i = 1; i <= n; i++) arr[i] = original[i];
    printf("Array reset to original order.\n");
}

int isSorted() {
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] > arr[i + 1]) return 0;
    return 1;
}

void binarySearch(int key) {
    int low = 1, high = n, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            printf("%d found at position %d.\n", key, mid);
            return;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("%d not found in the array.\n", key);
}

void modifiedBubbleSort() {
    int i, j, temp, swapped, passes = 0;
    for (i = 1; i < n; i++) {
        swapped = 0;
        for (j = 1; j <= n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        passes++;
        if (!swapped) break;
    }
    printf("Sorted using Modified Bubble Sort (%d pass(es)).\n", passes);
}

void insertionSortSentinel() {
    int i, j;
    for (i = 2; i <= n; i++) {
        arr[0] = arr[i];
        j = i - 1;
        while (arr[j] > arr[0]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = arr[0];
    }
    printf("Sorted using Insertion Sort with Sentinel.\n");
}

void shellSort() {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap + 1; i <= n; i++) {
            temp = arr[i];
            for (j = i; j > gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    printf("Sorted using Shell Sort.\n");
}

int main() {
    int choice, key;
    do {
        printf("\n===== SEARCH AND SORT MENU =====\n");
        printf("1. Enter array\n");
        printf("2. Display array\n");
        printf("3. Binary Search\n");
        printf("4. Modified Bubble Sort\n");
        printf("5. Insertion Sort using Sentinel\n");
        printf("6. Shell Sort\n");
        printf("7. Reset array to original order\n");
        printf("0. Exit\n");
        choice = readInt("Enter your choice: ");
        if (choice >= 3 && choice <= 7 && n == 0) {
            printf("Enter the array first.\n");
            continue;
        }
        switch (choice) {
            case 1:
                inputArray();
                break;
            case 2:
                displayArray();
                break;
            case 3:
                if (!isSorted()) {
                    printf("Array is not sorted. Sort it first (options 4 to 6).\n");
                    break;
                }
                key = readInt("Enter element to search: ");
                binarySearch(key);
                break;
            case 4:
                modifiedBubbleSort();
                displayArray();
                break;
            case 5:
                insertionSortSentinel();
                displayArray();
                break;
            case 6:
                shellSort();
                displayArray();
                break;
            case 7:
                resetArray();
                displayArray();
                break;
            case 0:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}
