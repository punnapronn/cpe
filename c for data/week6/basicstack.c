#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node_t;
typedef node_t stack;
void size(stack *hs){
    node_t *temp = hs;
    int cnt = 0;
    while (temp != NULL){
        temp = temp->next;
        cnt++;
    }
    printf("%d\n",cnt);
}
void empty(stack *hs){
    if (hs == NULL){
        printf("Stack is empty.\n");
    }
    else {
        printf("Stack is not empty.\n");
    }
}
void show(node_t*);
void top(stack *hs){
    if (hs == NULL){
        printf("Stack is empty.\n");
        return;
    }
    printf("%d\n",hs->data);
}
stack* pop(stack *hs){
    stack *temp = hs;
    if (hs == NULL){
        return hs;
    }
    hs = hs->next;
    free(temp);
    return hs;
}
stack* push(stack *hs,int x){
    stack *temp = (stack*)malloc(sizeof(stack));
    temp->data = x;
    temp->next = hs;
    return temp;
}
int main(void) {
    stack *s = NULL;
    int n, i, command, value;
    scanf("%d", &n);
        for (i=0; i<n; i++) {
            scanf("%d", &command);
            switch(command) {
            case 1:
                scanf("%d", &value);
                s = push(s, value);
                break;
            case 2:
                top(s);
                break;
            case 3:
                s = pop(s);
                break;
            case 4:
                empty(s);
                break;
            case 5:
                size(s);
            break;
        }
    }
    return 0;
}
void show(node_t* head){
    if (head == NULL){
        printf("\n");
        return;
    }
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}