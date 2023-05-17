#include <stdio.h>
#define MAX_SIZE 10

typedef struct
{
    int data[MAX_SIZE];
    int top;
}   Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, int element) {
    if (isFull(s))
    {
        printf("Stack is full\n");
    }
    else
    {
        s->data[++(s->top)] = element;
        printf("Pushed element: %d\n", element);
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else
    {
        int poppedElement = s->data[(s->top)--];
        return poppedElement;
    }
}

int main() {
    Stack stack;
    initialize(&stack);


    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    int popped1 = pop(&stack);
    if (popped1 != -1)
    {
        printf("Popped element: %d\n", popped1);
    }

    int popped2 = pop(&stack);
    if (popped2 != -1)
    {
        printf("Popped element: %d\n", popped2);
    }

    return 0;
}
