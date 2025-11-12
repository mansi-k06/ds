#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int n, key;
    printf("Enter number of students: ");
    scanf("%d", &n);

    int roll[n];
    printf("Enter roll numbers:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &roll[i]);

    printf("Enter roll number to search: ");
    scanf("%d", &key);

    int result = linearSearch(roll, n, key);
    if (result == -1)
        printf("Student not found.\n");
    else
        printf("Student attended training program (found at index %d).\n", result);
}
