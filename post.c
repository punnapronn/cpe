#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    float data;
    struct node *next;
} node_t;
typedef node_t stack;
void show(node_t*);
float top(stack *hs){
    if (hs == NULL){
        printf("Stack is empty.\n");
        return 0.00;
    }
    return hs->data;
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
stack* push(stack *hs,float x){
    stack *temp = (stack*)malloc(sizeof(stack));
    temp->data = x;
    temp->next = hs;
    return temp;
}
int main(void) {
    stack *head = NULL;
    int n;
    scanf("%d\n",&n);
    for (int i = 0;i<n;i++){
        char m;
        scanf("%c",&m);
        if (m == '+'){
            float a = top(head);
            head = pop(head);
            float b = top(head);
            head = pop(head);
            head = push(head,b+a);
        }
        else if (m == '-'){
            float a = top(head);
            head = pop(head);
            float b = top(head);
            head = pop(head);
            head = push(head,b-a);
        }
        else if (m == '*'){
            float a = top(head);
            head = pop(head);
            float b = top(head);
            head = pop(head);
            head = push(head,b*a);
            // printf("%f\n",b*a);
        }
        else if (m == '/'){
            float a = top(head);
            head = pop(head);
            float b = top(head);
            head = pop(head);
            head = push(head,b/a);
            // printf("%f\n",b/a);
        }
        else{
            int temp = m-'0';
            head = push(head,(float) temp);
        }
    }
    show(head);
    return 0;
}
void show(node_t* head){
    if (head == NULL){
        printf("\n");
        return;
    }
    while(head != NULL){
        printf("%.2f ",head->data);
        head = head->next;
    }
    printf("\n");
}