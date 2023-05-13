#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10

 typedef struct {
    int data[STACK_SIZE];
    int top;
} ; struct Stack

void initStack(struct *stack) {
    stack->top = -1;
}

int isStackEmpty(struct* stack) {
    return stack->top == -1;
}

int isStackFull(struct* stack) {
    return stack->top == STACK_SIZE - 1;
}

void push(struct* stack, int value) {
    if (isStackFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }

    stack->data[++stack->top] = value;
}

int pop(struct * stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }

    return stack->data[stack->top--];
}

void generateRandomNumbersToFile(const char* filename, int count) {
    struct stack;
    initstack(&stack);

    srand(time(NULL));

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        int num = rand() % 100;  // Generate a random number between 0 and 99
        push(&stack, num);
    }

    while (!isStackEmpty(&stack)) {
        int num = pop(&stack);
        fprintf(file, "%d\n", num);
    }

    fclose(file);
}

int main() {
    const char* filename = "mahati.txt";
    int count = 10;
    int user,value;
    printf("enter the choice,1 for push and 0 for pop\n");
    scanf("%d",&user);



    generateRandomNumbersToFile(filename, count);
    printf("Random numbers generated and stored in %s.\n", filename);

    return 0;
}
