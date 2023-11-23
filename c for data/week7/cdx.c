#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int data,len;
    struct stack *next;
}stack;
stack *push(stack *head,int value){
    stack *temp = (stack *)malloc(sizeof(stack));
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
typedef struct node{
    int val,node_depth;
    struct node *first_child;
    struct node *next_sibling;
    struct node *last_child;
    struct node *parent;
    struct node *prev_sibling;
}node;
typedef node tree_t;
node *createnode(int val){
    node *temp = (node*)malloc(sizeof(node));
    temp->val = val;
    temp->first_child = NULL;
    temp->next_sibling = NULL;
    temp->last_child = temp->next_sibling;
    return temp;
}
tree_t *searchPos(tree_t *t,int v){
    if(t == NULL || t->val == v){
        return t;
    }
    tree_t *pos = searchPos(t->first_child,v);
    if(pos != NULL){
        return pos;
    }
    else{
        return searchPos(t->next_sibling,v);
    }
}
tree_t *attach(tree_t *treeroot,int parentval,int childval){
    node *newchild = createnode(childval);
    if (treeroot == NULL){
        newchild->node_depth = 1;
        return newchild;
    }
    node *currnode = searchPos(treeroot,parentval);
    newchild->node_depth = currnode->node_depth + 1;
    newchild->parent = currnode;
    if (currnode->first_child == NULL){
    currnode->first_child = newchild;
    currnode->last_child = newchild;
    }
    else{
        newchild->prev_sibling = currnode->last_child;
        currnode->last_child->next_sibling = newchild;
        currnode->last_child = newchild;
    }
    return treeroot;
}
tree_t* detach(tree_t *rootnode, int value){
	if(rootnode->val == value){
		if(rootnode->prev_sibling != NULL)
			rootnode->prev_sibling->next_sibling = rootnode->next_sibling;
		else
			rootnode->parent->first_child = rootnode->next_sibling;
		if(rootnode->next_sibling != NULL)
			rootnode->next_sibling->prev_sibling = rootnode->prev_sibling;
		else
			rootnode->parent->last_child = rootnode->prev_sibling;
		return rootnode;
	}
	if(rootnode->next_sibling != NULL)
		detach(rootnode->next_sibling, value);
	if(rootnode->first_child != NULL)
		detach(rootnode->first_child, value);
	return rootnode;
}
int search(tree_t *root,int schval){
    if (searchPos(root,schval) != NULL){
        return 1;
    }
    return 0;
}
int degree(tree_t *treeroot,int nodeval){
    node *temp = searchPos(treeroot,nodeval);
    int cnt = 0;
    if(temp == NULL)
    return 0;
    node *childnode = temp->first_child;
    while (childnode != NULL){
        cnt++;
        childnode = childnode->next_sibling;
    }
    return cnt;
}
int is_root(tree_t *root,int val){
    node *check = searchPos(root,val);
    if (check == NULL)
        return 0;
    if (check->node_depth == 1){
        return 1;
    }
    return 0;
}
int is_leaf(tree_t *root,int val){
    node *check = searchPos(root,val);
    if (check == NULL)
    return 0;
    if (check->first_child == NULL){
        return 1;
    }
    return 0;
}

void siblings(tree_t *root,int val){
    node *check = searchPos(root,val);
    node *currnode = check;
    if (check == NULL ){
        printf("\n");
        return;
        }
    if (!is_root(root,currnode->val)){
        while(currnode->prev_sibling != NULL){
            currnode = currnode->prev_sibling;
        }
    }
    while (currnode != NULL){
        if (currnode->val != check->val){
        printf("%d ",currnode->val);
        }
        currnode = currnode->next_sibling;
    }
    printf("\n");
}
int depth(tree_t *root,int checkval){
    node *check = searchPos(root,checkval);
    if (check == NULL)
        return -999;
    return check->node_depth - 1;
}
stack *createpath(tree_t *root,int start,int stop){
    node *startnode = searchPos(root,start);
    node *endnode = searchPos(root,stop);
    stack *answer = (stack *)malloc(sizeof(stack));
    while (endnode->val != startnode->val){
        answer = push(answer,endnode->val);
        endnode = searchPos(root,endnode->parent->val);
    }
        answer = push(answer,endnode->val);
    return answer;
}
void print_path(tree_t *root,int startval,int endval){
    stack *answer = createpath(root,startval,endval);
    while (answer->next != NULL){
        printf("%d ",answer->data);
        answer = answer->next;
    }
    printf("\n");
}
int path_length(tree_t *root,int start,int end){
    stack *ans = createpath(root,start,end);
    return ans->len;
}
void ancestor(tree_t *root,int childval){
    stack *answer = createpath(root,root->val,childval);
    while (answer->next != NULL){
        printf("%d ",answer->data);
        answer = answer->next;
    }
    printf("\n");
}
void bfs(tree_t *);
void descendant(tree_t *root,int checkval){
    node *check = searchPos(root,checkval);
    bfs(check);
}
void bfs(tree_t *root) {
    if (root == NULL) {
        return;
    }
    typedef struct QueueNode {
        tree_t *data;
        struct QueueNode *next;
    } QueueNode;
    QueueNode *front = NULL;
    QueueNode *rear = NULL;
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = root;
    newNode->next = NULL;
    front = rear = newNode;

    while (front != NULL) {
        tree_t *current = front->data;
        QueueNode *temp = front;
        front = front->next;
        free(temp);
        printf("%d ", current->val);
        tree_t *child = current->first_child;
        while (child != NULL) {
            newNode = (QueueNode *)malloc(sizeof(QueueNode));
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

void dfs(tree_t *rootnode){
	printf("%d ",rootnode->val);
	if(rootnode->first_child != NULL)
		dfs(rootnode->first_child);
	if(rootnode->next_sibling != NULL)
		dfs(rootnode->next_sibling);
}
void printspace(int times){
    for(int i = 0;i<times;i++){
        printf("    ");
    }
}
void print_tree(tree_t *root){
    node *temp = root;
    if (root == NULL){
        return;
    }
    printspace(root->node_depth-1);
    printf("%d\n",root->val);
    if (root->first_child != NULL){
        print_tree(root->first_child);
    }
    if (root->next_sibling != NULL){
        print_tree(root->next_sibling);
    }
}