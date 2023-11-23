#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node_t;
typedef node_t queue;
void show(node_t*);
queue *head;
queue *tail;
void empty(queue *hq){
    if (hq == NULL){
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue is not empty.\n");
    }
}
void size(queue *hq){
    queue *temp = hq;
    int cnt = 0;
    while (temp != NULL){
        temp = temp->next;
        cnt++;
    }
    printf("%d\n",cnt);
}
queue *enqueue(queue *hq,int x){
    queue *temp = (queue*)malloc(sizeof(queue));
    temp->data = x;
    if (hq == NULL){
        head = tail = temp;
        return temp;
    }
    tail->next = temp;
    tail = temp;
    return hq;
}
queue *dequeue(queue *hq){
    if (hq == NULL){
        printf("Queue is empty.\n");
        return hq;
    }
    queue *temp = hq;
    int v = hq->data;
    printf("%d\n",v);
    hq = hq->next;
    free(temp);
    return hq;
}
int main(void) {
    queue *q = NULL;
    int n, i, command, value;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch(command) {
            case 1:
                scanf("%d", &value);
                q = enqueue(q, value);
                break;
            case 2:
                q = dequeue(q);
                break;
            case 3:
                show(q);
                break;
            case 4:
                empty(q);
                break;
            case 5:
                size(q);
                break;
    }
}
return 0;
}
void show(node_t* head){
    if (head == NULL){
        printf("Queue is empty.\n");
        return;
    }
    while(head->next != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("%d\n",head->data);
}