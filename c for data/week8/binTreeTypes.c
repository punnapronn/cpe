#include <stdio.h>
#include <stdlib.h>
#include "week8.h"
#include <math.h>
#ifndef __bin_tree__
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    } node_t;
typedef node_t tree_t;
#endif

int node(tree_t *t){
    if (t==NULL){
        return 0;
    }
    return 1 + node(t->left)+node(t->right);
}

int height(tree_t *t) {
    if (t==NULL) {
        return -1;
    }
    return (height(t->left)>height(t->right))? height(t->left)+1:height(t->right)+1 ;
}

int is_full(tree_t *t){
    if (t->left==NULL && t->right==NULL)
    return 1;
    if ((t->left!=NULL && t->right==NULL) ||  (t->left==NULL && t->right!=NULL))
    return 0;
    if (t->left!=NULL && t->right!=NULL)
    return is_full(t->left)&&is_full(t->right);
}

int is_perfect(tree_t *t){
    int h=height(t);
    int n=node(t);
    return (n==pow(2,h+1)-1)? 1:0;
}

int comp(tree_t *t,int idx,int node){
    if (t == NULL)
        return 1;
    if (idx >= node)
        return 0;
    if (comp(t->left, 2*idx+1, node) && comp(t->right, 2*idx+2, node))
        return 1;
    return 0;
}

int is_complete(tree_t *t){
    int n= node(t);
    return comp(t,0,n);
}

int degenerate(tree_t *t,int x){
    if (t->left == NULL && t->right == NULL){
        return 1;
    }
    if (t->left != NULL && t->right != NULL){
        return (x!=1)?1:0;
    }
    int a=0,b=0;
    if (t->left != NULL){
        a = degenerate(t->left,x+1);
    }
    if (t->right != NULL){
        b = degenerate(t->right,x+1);
    }
    if (a ^ b){
        return 1;
    }
    return 0;
}

int is_degenerate(tree_t *t){
    return degenerate(t,1);
}

int skewedL(tree_t *t) {
    if (t == NULL || (t->left == NULL && t->right == NULL)) {
        return 1;
    }
    if (t->right != NULL) {
        return 0;
    }
    return skewedL(t->left) && skewedL(t->right);
}
int skewedR(tree_t* t) {
    if (t == NULL || (t->left == NULL && t->right == NULL)) {
        return 1; 
    }
    if (t->left != NULL) {
        return 0;
    }
    return skewedR(t->left) && skewedR(t->right);
}
int is_skewed(tree_t *t){
    return skewedL(t)&&skewedR(t);
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
        printf("%d %d %d %d %d\n", is_full(t),
        is_perfect(t), is_complete(t),
        is_degenerate(t), is_skewed(t));
        return 0;
}