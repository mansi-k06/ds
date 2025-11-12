#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, key;
    printf("Enter number of students: ");
    scanf("%d", &n);

    int roll[n];
    printf("Enter roll numbers (sorted):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &roll[i]);

    printf("Enter roll number to search: ");
    scanf("%d", &key);

    int result = binarySearch(roll, n, key);
    if (result == -1)
        printf("Student not found.\n");
    else
        printf("Student attended training program (found at index %d).\n", result);
}
