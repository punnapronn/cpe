#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int value,dep;
    struct node *next_sibling;
    struct node *first_child;
    struct node *parent;
    struct node *last_child;
    struct node *prev_sibling;
} node_t;
typedef node_t tree_t;

typedef struct stack{
    int data,len;
    struct stack *next;
} stack_t;

stack_t *push(stack_t *head,int value){
    stack_t *temp = (stack_t *)malloc(sizeof(stack_t));
    temp->data = value;
    if (head == NULL){
        temp->len = 1;
        return temp;
    }
    temp->next = head;
    temp->len = head->len + 1;
    head = temp;
    return head;
}

node_t *createnode(int v){
    node_t *n = (node_t *)malloc(sizeof(node_t));
    n -> value = v;
    n -> next_sibling = NULL;
    n -> prev_sibling = NULL;
    n -> first_child = NULL;
    n -> last_child = NULL;
    n -> parent = NULL;
    return n;
}

node_t *position(node_t *node,int v){
    if (node == NULL || node -> value == v){
        return node;
    }
    node_t *pos = position(node -> first_child,v);
    if(pos != NULL){
        return pos;
    }
    else{
        return position(node -> next_sibling,v);
    }
    
}
node_t *attach(node_t *node,int v_parent,int value){
    if (v_parent==-1){
        node_t *newnode = createnode(value);
        newnode -> dep = 0;
        return newnode;
    } 
    if (node -> value == v_parent){
        node_t *newnode = createnode(value);
        newnode -> dep = node -> dep +1;
        newnode -> parent= node;
        if (node -> first_child == NULL) {
            node -> first_child = newnode;
            node -> last_child = newnode;
        } else{
            node -> last_child -> next_sibling = newnode;
            newnode -> prev_sibling = node -> last_child;
            node -> last_child = newnode;
        }
        return node;
    }
    if (node -> first_child != NULL){
        attach(node -> first_child,v_parent,value);
    }
    if (node -> next_sibling != NULL){
        attach(node -> next_sibling,v_parent,value);
    }
    return node;
}

node_t *detach(node_t *node,int value){
    if (node -> value == value){
        if(node -> prev_sibling != NULL){
            node -> prev_sibling -> next_sibling = node -> next_sibling;
        }else{
            if (node -> next_sibling != NULL){
                node -> parent -> first_child = node -> next_sibling;
            } else{
                node -> parent -> first_child = node -> parent -> last_child = NULL;
            }
        }
        return node;
    }
    if (node -> first_child != NULL){
        detach(node -> first_child,value);
    }
    if (node -> next_sibling != NULL){
        detach(node -> next_sibling,value);
    }
    return node;
}

int search(node_t *node,int v){
    if (position(node,v) != NULL){
        return 1;
    }
    return 0;
}

int degree(node_t *node,int v_parent){
    if (node -> value == v_parent){
        node_t *now = node ->first_child;
        int count=0;
        while (now != NULL){
            count++;
            now = now -> next_sibling;
        }
        return count;
    }
    if (node -> first_child != NULL){
        int c = degree(node -> first_child,v_parent);
        if (c != -1){
            return c;
        }
    }
    if (node -> next_sibling != NULL){
        int c = degree(node -> next_sibling,v_parent);
        if (c != -1){
            return c;
        }
    }
    return -1;
}

int is_root(node_t *node, int value){
	return node->value == value ? 1 : 0;
}

int is_leaf(node_t *node, int v){
    node_t *pos = position(node,v);
    if (pos == NULL){
        return 0;
    }
    if (pos -> first_child == NULL) {
        return 1;
    }
    return 0;
}

void siblings(node_t *node,int v){
    if (search(node,v) == 0){
        printf("\n");
        return;
    }
    node_t *who = position(node,v);
    if (who -> parent ==NULL){
        printf("\n");
        return;
    }
    node_t *first = who -> parent -> first_child;
    while (first != NULL){
        if(first != who){
            printf("%d ",first -> value);
        }
        first = first -> next_sibling;
    }
    printf("\n");
}

int depth(node_t *node,int v){
    node_t *pos = position(node,v);
    return pos -> dep;
}

stack_t *createpath(node_t *node,int start,int end){
    node_t *start_node = position(node,start);
    node_t *end_node = position(node,end);
    stack_t *path = (stack_t *)malloc(sizeof(stack_t));
    while (end_node -> value != start_node -> value){
        path = push(path,end_node -> value);
        end_node = position(node,end_node -> value);
    }
    path = push(path,end_node -> value);
    return path;
}

void print_path(node_t *node,int start,int end){
    stack_t *path = createpath(node,start,end);
    while (path -> next != NULL) {
        printf("%d ",path -> data);
        path = path -> next;
    }
    printf("\n");
}

int path_length(node_t *node,int start,int end){
    stack_t *path = createpath(node,start,end);
    return path->len;
}

void ancestor(node_t *node,int v){
    stack_t *ans = createpath(node,node->value,v);
    while (ans->next != NULL){
        printf("%d ",ans->data);
        ans = ans->next;
    }
    printf("\n");
}

void bfs(node_t *node) {
    if (node == NULL) {
        return;
    }
    typedef struct queue {
        node_t *data;
        struct queue *next;
    } queue_t;
    queue_t *front = NULL;
    queue_t *rear = NULL;
    queue_t *newNode = (queue_t *)malloc(sizeof(queue_t));
    newNode->data = node;
    newNode->next = NULL;
    front = rear = newNode;

    while (front != NULL) {
        node_t *current = front->data;
        queue_t *temp = front;
        front = front->next;
        free(temp);
        printf("%d ", current->value);
        node_t *child = current->first_child;
        while (child != NULL) {
            newNode = (queue_t *)malloc(sizeof(queue_t));
            newNode->data = child;
            newNode->next = NULL;
            if (front == NULL) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
            child = child->next_sibling;
        }
    }
}

void descendant(node_t *node,int v){
    node_t *check = position(node,v);
    bfs(check);
}

void dfs(node_t *node){
	printf("%d ",node->value);
	if(node->first_child != NULL)
		dfs(node->first_child);
	if(node->next_sibling != NULL)
		dfs(node->next_sibling);
}

void printspace(int t){
    for(int i = 0;i<t;i++){
        printf("    ");
    }
}

void print_tree(node_t *node){
    node_t *temp = node;
    if (node == NULL){
        return;
    }
    printspace(node->dep-1);
    printf("%d\n",node->value);
    if (node->first_child != NULL){
        print_tree(node->first_child);
    }
    if (node->next_sibling != NULL){
        print_tree(node->next_sibling);
    }
}

int main(void) {
    tree_t *t = NULL;
    int n, i, command;
    int parent, child, node, start, end;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch(command) {
            case 1:
                scanf("%d %d", &parent, &child);
                t = attach(t, parent, child);
                break;
            case 2:
                scanf("%d", &node);
                t = detach(t, node);
                break;
            case 3:
                scanf("%d", &node);
                printf("%d\n", search(t, node));
                break;
            case 4:
                scanf("%d", &node);
                printf("%d\n", degree(t, node));
                break;
            case 5:
                scanf("%d", &node);
                printf("%d\n", is_root(t, node));
                break;
            case 6:
                scanf("%d", &node);
                printf("%d\n", is_leaf(t, node));
                break;
            case 7:
                scanf("%d", &node);
                siblings(t, node);
                break;
            case 8:
                scanf("%d", &node);
                printf("%d\n", depth(t, node));
                break;
            case 9:
                scanf("%d %d", &start, &end);
                print_path(t, start, end);
                break;
            case 10:
                scanf("%d %d", &start, &end);
                printf("%d\n",
                path_length(t, start, end));
                break;
            case 11:
                scanf("%d", &node);
                ancestor(t, node);
                break;
            case 12:
                scanf("%d", &node);
                descendant(t, node);
                break;
            case 13:
                bfs(t);
                break;
            case 14:
                dfs(t);
                break;
            case 15:
                print_tree(t);
                break;
        }
    }
    return 0;
}