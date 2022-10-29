#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct Node {
char name[50];
int oc;
struct Node* next;
}Node;

void push( Node** head_ref, char n[50])
{
Node* new_node = ( Node*) malloc(sizeof( Node));
strcpy(new_node->name, n);
new_node->oc=1;
new_node->next = (*head_ref);
(*head_ref) = new_node;
}
Node* reverseList(Node* head)
{
if (head->next == NULL)
return head;
Node* rest = reverseList(head->next);
head->next->next = head;
head->next = NULL;
return rest;
}

Node* create()
{   Node* a = NULL;
    printf("Enter the number of Student:\t");
    int s;char n[50];
    scanf("%d",&s);
    for(int i=0;i<s;i++)
    {
      printf("Enter Name for %d student:\t",i+1);
      scanf("%s",&n);
      push(&a,n);
    }
    return a;

}
void printList( Node* Node)
{
    while (Node != NULL) {
    printf("{%s,%d}",Node->name,Node->oc);
    if(Node->next!=NULL)
    printf("->");
    else
    printf("\n");

    Node = Node->next;
}
}

void Search(Node* start)
{
    Node *ptr1, *ptr2, *dup;
    ptr1 = start;
 
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
 

        while (ptr2->next != NULL) {
            if (strcmp(ptr2->name,ptr1->name)==0) {
                // ptr2->oc++;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
int main()
{

    Node* a = create(); 
    a=reverseList(a);
    printList(a);   
    Search(a);
    printList(a);    
return 0;
}
