#include <stdio.h>

int bruteForceSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {4, 2, 7, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int index = bruteForceSearch(arr, n, target);
    if (index != -1)
        printf("Target element found at index %d\n", index);
    else
        printf("Target element not found\n");

    return 0;
}


