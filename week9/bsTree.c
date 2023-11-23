#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t bst_t;

node_t *createNode(int v){
    node_t *tmp;
    tmp = (node_t*)malloc(sizeof(node_t));
    tmp->data = v;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

bst_t *insert(bst_t *t ,int v){
    node_t *newnode = createNode(v);
    if (t==NULL){
        return newnode;
    }
    if (v > t->data){
        if (t->right==NULL){
            t->right=newnode;
        } else{
            insert(t->right,v);
        }
    }
    if (v < t->data){
        if (t->left==NULL){
            t->left=newnode;
        } else{
            insert(t->left,v);
        }
    }
    return t;
}

int find(bst_t *t,int v){
    if (t==NULL){
        return 0;
    }
    if (v == t->data){
        return 1;
    } else{
        if (t->right==NULL && t->left==NULL){
            return 0;
        }
        if (v < t->data){
            return find(t->left,v);
        }
        if (v > t->data){
            return find(t->right,v);
        }
    }
}

int find_min(bst_t *t){
    if (t->left==NULL)
    return t->data;
    else
    find_min(t->left);
}

int find_max(bst_t *t){
    if (t->right==NULL)
    return t->data;
    else
    find_max(t->right);
}

node_t *findpos(bst_t *t,int v){
    if (t == NULL){
        return t;
    }
    if (v == t->data){
        return t;
    } else{
        if (t->right==NULL && t->left==NULL){
            return NULL;
        }
        if (v < t->data){
            return findpos(t->left,v);
        }
        if (v > t->data){
            return findpos(t->right,v);
        }
    }
}
/*
node_t *findparent(bst_t *t,int child){
    if(child == t->data){
        return NULL;
    }
    if(child < t->data){
        if (child == t->left->data){
            return t;
        } else{
            return findparent(t->left,child);
        }
    } else{
        if (child == t->right->data){
            return t;
        } else{
            return findparent(t->right,child);
        }
    }
}*/

node_t *findminOFright(bst_t *t){
    return findpos(t,find_min(t->right));
}

bst_t *delete(bst_t *t,int v){
    if (t==NULL){
        return NULL;
    }
    if (v > t->data) {
        t->right = delete(t->right, v);
    } else if (v < t->data) {
        t->left = delete(t->left, v);
    }else{
        if (t->left == NULL) {
            bst_t* temp = t->right;
            free(t);
            return temp;
        } else if (t->right == NULL) {
            bst_t* temp = t->left;
            free(t);
            return temp;
        }
        bst_t* minNode = findminOFright(t);
        t->data = minNode->data;
        t->right = delete(t->right, minNode->data);
    }
    return t;
}
    

int main(void) {
    bst_t *t = NULL;
    int n, i;
    int command, data;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch (command) {
            case 1:
                scanf("%d", &data);
                t = insert(t, data);
                break;
            case 2:
                scanf("%d", &data);
                t = delete(t, data);
                break;
            case 3:
                scanf("%d", &data);
                printf("%d\n", find(t, data));
                break;
            case 4:
                printf("%d\n", find_min(t));
                break;
            case 5:
                printf("%d\n", find_max(t));
                break;
        }    
    }
    return 0;
}