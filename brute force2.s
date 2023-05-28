#include <stdio.h>

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char* str, int left, int right) {
    if (left == right) {
        printf("%s\n", str);
    } else {
        for (int i = left; i <= right; i++) {
            swap((str + left), (str + i));
            permute(str, left + 1, right);
            swap((str + left), (str + i));
        }
    }
}

int main() {
    char str[] = "ABC";
    int n = sizeof(str) / sizeof(str[0]) - 1;

    printf("Permutations:\n");
    permute(str, 0, n - 1);

    return 0;
}
