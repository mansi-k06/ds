#include <stdio.h>

void selectionSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        float temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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

    selectionSort(marks, n);
    printf("Top five scores:\n");
    for (int i = n - 1; i >= n - 5 && i >= 0; i--)
        printf("%.2f\n", marks[i]);
}
