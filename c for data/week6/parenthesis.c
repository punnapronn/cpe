#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node *next;
} node_t;
typedef node_t stack_t;
char top(stack_t *hs){
    if (hs == NULL){
        return '\0';
    }
    return hs->data;
}
stack_t* pop(stack_t *hs){
    stack_t *temp = hs;
    if (hs == NULL){
        return hs;
    }
    hs = hs->next;
    free(temp);
    return hs;
}
stack_t* push(stack_t *hs,char x){
    stack_t *temp = (stack_t*)malloc(sizeof(stack_t));
    temp->data = x;
    temp->next = hs;
    return temp;
}
void show(stack_t* head){
    if (head == NULL){
        printf("\n");
        return;
    }
    while(head != NULL){
        printf("%c ",head->data);
        head = head->next;
    }
    printf("\n");
}
int main(void) {
    int n;
    scanf("%d\n",&n);
    if (n%2 != 0){
        printf("%d\n",0);
        return 0;
    }
    stack_t *head = NULL;
    char *str1 = (char *)malloc(n * sizeof(char));
    for (int i = 0;i<n;i++){
        char m;
        scanf("%c",&m);
        if (top(head) == '(' && m == ')'){
            head = pop(head);
        }
        else if (top(head) == '[' && m == ']'){
            head =  pop(head);
        }
        else if (top(head) == '{' && m == '}'){
            head =  pop(head);
        }
        else{
            head = push(head,m);
        }
    }
    if(head != NULL){
        printf("0\n");
    }
    else{
        printf("1\n");
    }
    
}