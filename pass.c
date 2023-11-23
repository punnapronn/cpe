#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char data;
    struct node *next;
} node_t;
typedef node_t stack_t;
stack_t* push(stack_t *hs,char x){
    stack_t *temp = (stack_t*)malloc(sizeof(stack_t));
    temp->data = x;
    temp->next = hs;
    return temp;
}
int main(void) {
    stack_t *head = NULL;
    while(1){
        char m;
        scanf("%c",&m);
        if (m == 'x'){
            break;
        }
        head = push(head,m);
    }
    while(1){
        char m;
        scanf("%c",&m);
        if (head == NULL && m != 'y'){
            printf("0\n");
            return 0;
        }
        if (m == 'y' && head == NULL){
        printf("1\n");
            break;
        }
        if (m != head->data){
            printf("0\n");
            return 0;
        } 
        head = head->next;
    }
    return 0;
}