#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
int key;
struct Node* next;
}Node;

Node* reverseList(Node* head)
{
if (head->next == NULL)
return head;
Node* rest = reverseList(head->next);
head->next->next = head;
head->next = NULL;
return rest;
}

Node* sortedMerge(Node* a, Node* b)
{
    a = reverseList(a);
    b = reverseList(b);
    Node* head = NULL;
    Node* temp;
    while (a != NULL && b != NULL) {
    if (a->key >= b->key)
    {
            temp = a->next;
            a->next = head;
            head = a;
            a = temp;
    }
    else
    {
        temp = b->next;
        b->next = head;
        head = b;
        b = temp;
    }
    }

    while (a != NULL)
    {
        temp = a->next;
        a->next = head;
        head = a;
        a = temp;
    }


    while (b != NULL) {
        temp = b->next;
        b->next = head;
        head = b;
        b = temp;
}
return head;
}
void printList(struct Node* Node)
{
while (Node != NULL) {
printf("%d ",Node->key);
Node = Node->next;
}
}
void push( Node** head_ref, int new_data)
{
Node* new_node = ( Node*) malloc(sizeof( Node));
new_node->key = new_data;

new_node->next = (*head_ref);

(*head_ref) = new_node;
}
int main()
{   int q;
Node* res = NULL;
Node* a = NULL;
Node* b = NULL;
    printf("Enter the number of element of 1 sorted list:\t");
    int s;
    scanf("%d",&s);
    for(int i=0;i<s;i++)
    {
      printf("Enter %d element:\t",i+1);
      scanf("%d",&q);
      push(&a, q);
    }
    a=reverseList(a);
    printf("Enter the number of element of 2 list:\t");
    scanf("%d",&s);
    for(int i=0;i<s;i++)
    {
      printf("Enter %d element:\t",i+1);
      scanf("%d",&q);
      push(&b, q);
    }b=reverseList(b);

printf("List 1: \n");
printList(a);

printf("\nList 2: \n");
printList(b);

res = sortedMerge(a, b);

printf("\nAfter merging: \n");
printf("LIST1: ");
printList(res);

return 0;
}
