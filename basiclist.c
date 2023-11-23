#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
    } node_t;

node_t *append(node_t *node1)
{
  node_t *p = node1;
  node_t *node2 = (node_t *)malloc(sizeof(node_t));
  node_t *tmp = NULL;
  scanf(" %d", &node2->data);
  node2->next = NULL;

  if (node1 == NULL)
  {
    return node2;
  }
  while (p != NULL)
  {
    tmp = p;
    p = p->next;
  }
  tmp->next = node2;
  return node1;
}

void get(node_t *node1)
{
  int index;
  scanf(" %d", &index);
  for (int i = 0; i < index; i++)
  {
    node1 = node1->next;
  }
  printf("%d\n", node1->data);
}

void show(node_t *start)
{
  while (start != NULL)
  {
    printf("%d ", start->data);
    start = start->next;
  }
  printf("\n");
}

node_t *cut(node_t *pNode)
{
  node_t *nNode = NULL;
  node_t *sNode = NULL;
  int start, stop;
  int i = 0;
  scanf(" %d %d", &start, &stop);
  while (pNode != NULL)
  {
    nNode = pNode->next;
    if (i >= start && i <= stop)
    {
      if (i == start)
      {
        sNode = pNode;
      }
      if (i == stop)
      {
        pNode->next = NULL; // Terminate the cut portion
      }
    }
    else
    {
      free(pNode);
    }
    pNode = nNode;
    i++;
  }
  return sNode;
}

node_t *reverse(node_t *start)
{
  node_t *nNode;
  node_t *lNode = NULL;
  if (start->next == NULL)
  {
    return start;
  }
  while (start != NULL)
  {
    nNode = start->next;
    start->next = lNode;
    lNode = start;
    start = nNode;
  }
  free(start);
  return lNode;
}

int main(void) {
node_t *startNode;
int n,i;
char command;
startNode = NULL;
scanf("%d", &n);
for (i=0; i<n; i++) {
scanf(" %c", &command);
switch (command) {
case 'A':
startNode = append(startNode);
break;
case 'G':
get(startNode);
break;
case 'S':
show(startNode);
break;
case 'R':
startNode = reverse(startNode);
break;
case 'C':
startNode = cut(startNode);
break;
default:
break;
}
}
return 0;
}