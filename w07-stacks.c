#include <stdio.h>
#include <stdlib.h>
#define ERR_NONE 0
#define ERR_OVER 1
#define ERR_UNDER 2

typedef struct StackElement {
    int data;
    struct StackElement* below;
} StackElement;

typedef struct Stack {
    StackElement* top;
    int ERR;
} Stack;

StackElement* new_stack_element(int value, StackElement* below) {
    StackElement* e = malloc(sizeof(StackElement));
    e->data = value;
    e->below = below;
    return e;
}

Stack* new_stack() {
    Stack* s = malloc(sizeof(Stack));
    s->top = NULL;
    s->ERR = ERR_NONE;
    return s;
}


void print_stack(Stack* stack) {
    if (stack == NULL) {
        printf("Uninitialised\n");
    }
    StackElement* curr = stack->top;
    printf("[");
    while(curr != NULL) {
        printf("(%d, %p)", curr->data, curr->below);
        if (curr->below!= NULL) {
            printf(", ");
        }
        curr = curr->below;
    }
    printf("]\n");
}

const char* check_error(Stack* stack) {
    switch (stack->ERR) {
    case ERR_NONE: return "No error";
    case ERR_UNDER: return "Underflow";
    case ERR_OVER: return "Overflow";
    default: return "ERROR";
    }
}



void push(Stack* stack, int value) {
   StackElement* e = new_stack_element(value, stack->top);
    stack->top = e;
}

int peek(Stack* stack) {
    int v = stack->top->data;
    return v;
}

int pop(Stack* stack) {
    int v = stack->top->data;
    stack->top = stack->top->below;
    return v;
}


int main()
{
    int result;
    Stack* stack = new_stack();
    // should print []
    print_stack(stack);
    push(stack, 14);
    print_stack(stack);
    push(stack, 1);
    print_stack(stack);

    int value = peek(stack);
    printf("Peeked: %d\n", value);

    // start popping the stack
    result = pop(stack);
    printf("Popped: %d\t%s\n", result, check_error(stack));
    print_stack(stack);
    result = pop(stack);
    printf("Popped: %d\t%s\n", result, check_error(stack));
    print_stack(stack);
    result = pop(stack);
    printf("Popped: %d\t%s (should contain error!)\n", result, check_error(stack));
    print_stack(stack);

    return 0;
}
