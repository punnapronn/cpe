#include <stdio.h>
#include <stdlib.h>
#include "week8.h"
#ifndef __bin_tree__
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    } node_t;
typedef node_t tree_t;
#endif


typedef struct list{
    int v;
    struct list *next;
}list;
list *createlist(int val){
    list *temp = (list*)malloc(sizeof(list));
    temp->v = val;
    temp->next = NULL;
    return temp;
}
list *push(list *head,int val){
    list* temp = createlist(val);
    if (head == NULL){
        head = temp;
        return head;
    }
    list *curr = head;
    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
void show(list* head){
    while (head != NULL){
        printf("%d ",head->v);
        head = head->next;
    }
    printf("\n");
}

list *headpre = NULL;
void preorder(tree_t *t){
    if (t == NULL)
        return;
    headpre = push(headpre,t->data);
    preorder(t->left);
    preorder(t->right);
}
void print_preorder(tree_t *t){
    preorder(t);
    show(headpre);
}

list *headpost = NULL;
void postorder(tree_t *t){
    if (t == NULL){
        return;
    }
    postorder(t->left);
    postorder(t->right);
    headpost = push(headpost,t->data);
}
void print_postorder(tree_t *t){
    postorder(t);
    show(headpost);
}

list *headin = NULL;
void inorder(tree_t *t){
    if (t == NULL){
        return;
    }
    inorder(t->left);
    headin = push(headin,t->data);
    inorder(t->right);
}
void print_inorder(tree_t *t){
    inorder(t);
    show(headin);
}

int main(void) {
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d %d %d", &parent, &child,&branch);
        t = attach(t, parent, child, branch);
    }
    print_preorder(t);
    print_postorder(t);
    print_inorder(t);
    return 0;
}