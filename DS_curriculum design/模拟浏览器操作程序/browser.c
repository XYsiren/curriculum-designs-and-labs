#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 70
#define MAX_STACK_SIZE 100

typedef struct {
    char url[MAX_URL_LENGTH + 1];
} WebPage;

typedef struct {
    WebPage data[MAX_STACK_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

int isStackEmpty(Stack *stack) {
    return (stack->top == -1);
}

int isStackFull(Stack *stack) {
    return (stack->top == MAX_STACK_SIZE - 1);
}

void push(Stack *stack, WebPage page) {
    if (!isStackFull(stack)) {
        stack->data[++(stack->top)] = page;
    }
}

WebPage pop(Stack *stack) {
    WebPage emptyPage = {""};
    if (!isStackEmpty(stack)) {
        return stack->data[(stack->top)--];
    }
    return emptyPage;
}

int main() {
    Stack backStack, forwardStack;
    initializeStack(&backStack);
    initializeStack(&forwardStack);
    WebPage currentPage = {"http://www.acm.org/"};

    char command[10];
    while (strcmp(command, "QUIT") != 0) {
        scanf("%s", command);
        if (strcmp(command, "BACK") == 0) {
            push(&forwardStack, currentPage);
            currentPage = pop(&backStack);
            if (strcmp(currentPage.url, "") == 0) {
                printf("Ignored\n");
                currentPage = pop(&forwardStack);
                //currentPage = pop(&backStack);
            } else {
                printf("%s\n", currentPage.url);
            }
        } else if (strcmp(command, "FORWARD") == 0) {
            push(&backStack, currentPage);
            currentPage = pop(&forwardStack);
            if (strcmp(currentPage.url, "") == 0) {
                printf("Ignored\n");
                currentPage = pop(&forwardStack);
            } else {
                printf("%s\n", currentPage.url);
            }
        } else if (strcmp(command, "VISIT") == 0) {
            push(&backStack, currentPage);
            initializeStack(&forwardStack);
            scanf("%s", currentPage.url);
            printf("%s\n", currentPage.url);
        }
    }

    return 0;
}

