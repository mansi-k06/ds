#include <stdio.h>

void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    float marks[n];
    printf("Enter percentage of students:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &marks[i]);

    bubbleSort(marks, n);
    printf("Top five scores:\n");
    for (int i = n - 1; i >= n - 5 && i >= 0; i--)
        printf("%.2f\n", marks[i]);
}
