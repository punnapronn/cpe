#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int freq;
    char word[20];
    struct node *left_child;
    struct node *right_child;
} node_t;
typedef node_t tree_t;

tree_t *init_tree(int f,char *w){
    tree_t *tree = (tree_t*)malloc(sizeof(tree_t));
    tree->freq = f;
    strcpy(tree->word,w);
    tree->left_child = NULL;
    tree->right_child = NULL;
    return tree;
}

tree_t *merge_tree(tree_t *t1,tree_t *t2){
    tree_t *tree = (tree_t*)malloc(sizeof(tree_t));
    tree->freq = t1->freq + t2->freq;
    tree->left_child = t1;
    tree->right_child = t2;
    return tree;
}

typedef struct heap {
    tree_t **data;
    int last_index;
} heap_t;

heap_t *init_heap(int n){
    n++;
    heap_t *heap = (heap_t*)malloc(sizeof(heap_t));
    heap->data = (tree_t**)malloc(sizeof(tree_t*)*n);
    heap->last_index = 0;
    return heap;
}

void swap(tree_t **a,tree_t **b){
    tree_t *temp = *a;
    *a = *b;
    *b = temp;
}

void insert(heap_t *h,tree_t *t){
    h->last_index++;
    h->data[h->last_index] = t;
    int i = h->last_index;
    while(i > 1){
        if(h->data[i]->freq < h->data[i/2]->freq){
            swap(&h->data[i],&h->data[i/2]);
            i /= 2;
        }
        else break;
    }
}

tree_t *delmin(heap_t *h){
    tree_t *tree = h->data[1];
    h->data[1] = h->data[h->last_index];
    h->last_index--;
    h->last_index = (h->last_index < 0) ? 0 : h->last_index;
    int i = 1;
    while(i*2 <= h->last_index){
        if(h->data[i]->freq > h->data[i*2]->freq || h->data[i]->freq > h->data[i*2+1]->freq){
            if(h->data[i*2]->freq <= h->data[i*2+1]->freq){
                swap(&h->data[i],&h->data[i*2]);
                i *= 2;
            }
            else{
                swap(&h->data[i],&h->data[i*2+1]);
                i = i*2+1;
            }
        }
        else break;
    }
    return tree;
}

char code[100];
void print_huffman(tree_t *t,int c){
    if(t->left_child == NULL && t->right_child == NULL){
        printf("%s: ",t->word);
        for(int i=0;i<c;i++) printf("%c",code[i]);
        printf("\n");
    }
    else{
        code[c] = '0';
        print_huffman(t->left_child,c+1);
        code[c] = '1';
        print_huffman(t->right_child,c+1);
    }
}

int main(){
    int i,n,f;
    char word[20];
    scanf("%d",&n);
    heap_t *min_heap = init_heap(n);
    for(i=0;i<n;i++){
        scanf(" %s %d",word,&f);
        tree_t *tree = init_tree(f,word);
        insert(min_heap,tree);
    }
    while(min_heap->last_index > 1){
        tree_t *tree1 = delmin(min_heap);
        tree_t *tree2 = delmin(min_heap);
        tree_t *tree = merge_tree(tree1,tree2);
        insert(min_heap,tree);
    }
    print_huffman(min_heap->data[1],0);
    return 0;
}