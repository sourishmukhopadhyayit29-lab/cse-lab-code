#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int original[MAX];
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
    for (i = 0; i < n; i++) {
        sprintf(prompt, "Enter element %d: ", i + 1);
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
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void resetArray() {
    int i;
    for (i = 0; i < n; i++) arr[i] = original[i];
    printf("Array reset to original order.\n");
}

int partition(int low, int high) {
    int pivot = arr[high];
    int i = low - 1, j, temp;
    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int low, int high) {
    int p;
    if (low < high) {
        p = partition(low, high);
        quickSort(low, p - 1);
        quickSort(p + 1, high);
    }
}

void merge(int low, int mid, int high) {
    int temp[MAX];
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= high) temp[k++] = arr[j++];
    for (i = 0; i < k; i++) arr[low + i] = temp[i];
}

void mergeSort(int low, int high) {
    int mid;
    if (low < high) {
        mid = low + (high - low) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

void countingPass(int exp) {
    int output[MAX];
    int count[10] = {0};
    int i;
    for (i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++) count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort() {
    int i, min = arr[0], max, exp;
    for (i = 1; i < n; i++)
        if (arr[i] < min) min = arr[i];
    for (i = 0; i < n; i++) arr[i] -= min;
    max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    for (exp = 1; max / exp > 0; exp *= 10) countingPass(exp);
    for (i = 0; i < n; i++) arr[i] += min;
}

int main() {
    int choice;
    do {
        printf("\n===== SORTING MENU =====\n");
        printf("1. Enter array\n");
        printf("2. Display array\n");
        printf("3. Quick Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Radix Sort\n");
        printf("6. Reset array to original order\n");
        printf("0. Exit\n");
        choice = readInt("Enter your choice: ");
        if (choice >= 3 && choice <= 6 && n == 0) {
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
                quickSort(0, n - 1);
                printf("Sorted using Quick Sort.\n");
                displayArray();
                break;
            case 4:
                mergeSort(0, n - 1);
                printf("Sorted using Merge Sort.\n");
                displayArray();
                break;
            case 5:
                radixSort();
                printf("Sorted using Radix Sort.\n");
                displayArray();
                break;
            case 6:
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
