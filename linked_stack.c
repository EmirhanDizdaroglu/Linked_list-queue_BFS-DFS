#include "linked_stack.h"
#include <stdlib.h>
#include <stdio.h>

LINKED_STACK linked_stack_create() {
    LINKED_STACK stack = (LINKED_STACK)malloc(sizeof(LINKED_STACK_t));
    if (stack == NULL) {
        perror("Failed to create stack");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    stack->count = 0;
    return stack;
}

void linked_stack_destroy(LINKED_STACK stack) {
    if (stack == NULL) return;
    while (!linked_stack_is_empty(stack)) {
        linked_stack_pop(stack);
    }
    free(stack);
}

void linked_stack_push(LINKED_STACK stack, void *data) {
    if (stack == NULL) return;
    LINKED_STACK_NODE newNode = (LINKED_STACK_NODE)malloc(sizeof(LINKED_STACK_NODE_t));
    if (newNode == NULL) {
        perror("Failed to push data");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->count++;
}

void *linked_stack_pop(LINKED_STACK stack) {
    if (stack == NULL || stack->top == NULL) return NULL;
    LINKED_STACK_NODE node = stack->top;
    void *data = node->data;
    stack->top = node->next;
    free(node);
    stack->count--;
    return data;
}

void *linked_stack_top(LINKED_STACK stack) {
    if (stack == NULL || stack->top == NULL) return NULL;
    return stack->top->data;
}

int linked_stack_is_empty(LINKED_STACK stack) {
    return stack == NULL || stack->top == NULL;
}

int linked_stack_size(LINKED_STACK stack) {
    if (stack == NULL) return 0;
    return stack->count;
}
