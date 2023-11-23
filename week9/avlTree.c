#include <stdio.h>
#include <stdlib.h>
#include "week9.h"
#ifndef __avl_tree__
typedef struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t avl_t;
#endif

node_t *createNode(int v){
    node_t *tmp;
    tmp = (node_t*)malloc(sizeof(node_t));
    tmp->height = 0;
    tmp->data = v;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

avl_t* rotate_left(avl_t *t){
    avl_t *tmp = t->right;
    t->right = tmp->left;
    tmp->left = t;
    t->height -= 2;
    return tmp;
}

avl_t* rotate_right(avl_t *t){
    avl_t *tmp = t->left;
    t->left = tmp->right;
    tmp->right = t;
    t->height -= 2;
    return tmp;
}

avl_t* rotate_left_right(avl_t *t){
    t->left = rotate_left(t->left);
    t = rotate_right(t);
    return t;
}

avl_t* rotate_right_left(avl_t *t){
    t->right = rotate_right(t->right);
    t = rotate_left(t);
    return t;
}

avl_t *insert(avl_t *t,int v){
    int left_h,right_h;
    node_t *newnode = createNode(v);
    if (t==NULL){
        t =newnode;
    }
    else if (v > t->data){
        t->right = insert(t->right, v);
        if(t->left == NULL){
            left_h = -1;
            }else
            left_h = t->left->height;
        if(t->right == NULL){
            right_h = -1;
            }else 
            right_h = t->right->height;
        t->height = (left_h > right_h ? left_h : right_h) + 1;
        if(right_h - left_h == 2){
            if(v > t->right->data){
                t = rotate_left(t);
                } else
                t = rotate_right_left(t);
        }
        
    }
    else if (v < t->data){
        t->left = insert(t->left, v);
        if(t->left == NULL){
            left_h = -1;
            }else 
            left_h = t->left->height;
        if(t->right == NULL){
            right_h = -1;
            }else 
            right_h = t->right->height;
        t->height = (left_h > right_h ? left_h : right_h) + 1;
        if(left_h - right_h == 2){
            if(v < t->left->data){
                t = rotate_right(t);
                } else
                t = rotate_left_right(t);
        }
    }
    if(t->left == NULL){
        left_h = -1;
        }else 
        left_h = t->left->height;
    if(t->right == NULL){
        right_h = -1;
        } else 
        right_h = t->right->height;
    if(left_h > right_h){
        t->height = left_h + 1;
    }
    else{
        t->height = right_h + 1;
    }
    return t;
    
}

avl_t* delete(avl_t *t,int v){
    int lh,rh,llh,lrh,rlh,rrh;
    if(t==NULL){
        return t;
    }
    else if(v < t->data){
        t->left = delete(t->left, v);
        if(t->left == NULL){
            lh = -1;
        } else{
            lh = t->left->height;
        }
        if(t->right == NULL){
            rh = -1;
        } else{
            rh = t->right->height;
        }
        t->height = (lh > rh ? lh : rh) + 1;
        if(rh - lh == 2){
            if(t->right->left == NULL){
                rlh = -1;
            } else{
                rlh = t->right->left->height;
            } 
            if(t->right->right == NULL){
               rrh = -1; 
            } else{
                rrh = t->right->right->height;
            }
            if(rlh > rrh){
                t = rotate_right_left(t);
            } else{
                t = rotate_left(t);
            }
        }
    }
    else if(v > t->data){
        t->right = delete(t->right, v);
        if(t->left == NULL){
           lh = -1; 
        } else{
            lh = t->left->height;
        } 
        if(t->right == NULL){
           rh = -1; 
        } else{
            rh = t->right->height;
        } 
        t->height = (lh > rh ? lh : rh) + 1;
        if(lh - rh == 2){
            if(t->left->left == NULL){
                llh = -1;
            } else{
                llh = t->left->left->height;
            } 
            if(t->left->right == NULL){
                lrh = -1;
            } else{
                lrh = t->left->right->height;
            } 
            if(lrh > llh){
                t = rotate_left_right(t);
            } else{
                t = rotate_right(t);
            }
        }
    }
    else{
        if(t->left==NULL && t->right==NULL){
            free(t);
            t = NULL;
            return t;
        }
        else if(t->left==NULL){
            avl_t *tmp = t;
            t = t->right;
            free(tmp);
        }
        else if(t->right==NULL){
            avl_t *tmp = t;
            t = t->left;
            free(tmp);
        }
        else{
            avl_t *tmp = t->right;
            while(tmp->left!=NULL){
                tmp = tmp->left;
            }
            t->data = tmp->data;
            t->right = delete(t->right, tmp->data);
            if(t->left == NULL){
                lh = -1;
            } else {
                lh = t->left->height;
            }
            if(t->right == NULL){
               rh = -1; 
            } else{
                rh = t->right->height;
            } 
            t->height = (lh > rh ? lh : rh) + 1;
            if(lh - rh == 2){
                if(t->left->left == NULL){
                   llh = -1; 
                } else{
                    llh = t->left->left->height;
                } 
                if(t->left->right == NULL){
                  lrh = -1;  
                } else {
                    lrh = t->left->right->height;
                } 
                if(lrh > llh){
                    t = rotate_left_right(t);
                } else{
                    t = rotate_right(t);
                }
            }
        }
    }
    if(t->left == NULL){
        lh = -1;
    } else{
        lh = t->left->height;
    } 
    if(t->right == NULL){
       rh = -1; 
    } else{
        rh = t->right->height;
    } 
    if(lh > rh){
        t->height = lh + 1;
    } else{
        t->height = rh + 1;
    }
    return t;
}


int main(void) {
    avl_t *t = NULL;
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
                print_tree(t);
                break;
        }
    }
    return 0;
}