#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct Node {
int roll;
int marks;
char name[50];
struct Node* next;
}Node;

void printList( Node* Node)
{
    while (Node != NULL) {
    printf("{%s,%d,%d}",Node->name,Node->roll,Node->marks);
    if(Node->next!=NULL)
    printf("->");
    else
    printf("\n");

    Node = Node->next;
}
}
void push( Node** head_ref, int new_roll,int new_marks,char n[50])
{
Node* new_node = ( Node*) malloc(sizeof( Node));
new_node->roll = new_roll;
new_node->marks = new_marks;
strcpy(new_node->name, n);
new_node->next = (*head_ref);
(*head_ref) = new_node;
}
void swap( Node *a, Node *b) 
{ int temp;char n[50];
    temp = a->marks; 
    a->marks = b->marks; 
    b->marks = temp; 
    temp = a->roll; 
    a->roll = b->roll; 
    b->roll = temp; 
    
    strcpy(n,a->name);
   strcpy(a->name,b->name);
   strcpy(b->name,n);
    
} 
void bubbleSort( Node *start) 
{ 
    int swapped, i; 
    struct Node *ptr1; 
    struct Node *lptr = NULL; 
  
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->marks < ptr1->next->marks) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

int main()
{   int r,m;
Node* res = NULL;
Node* a = NULL;
    printf("Enter the number of Student:\t");
    int s;char n[50];
    scanf("%d",&s);
    for(int i=0;i<s;i++)
    {
      printf("Enter Name for %d student:\t",i+1);
      scanf("%s",&n);
      printf("Enter roll for %d student:\t",i+1);
      scanf("%d",&r);
      printf("Enter marks for %d student:\t",i+1);
      scanf("%d",&m);
      
      push(&a, r,m,n);
    }
    printList(a);
    
    printf("Sorted list based on marks:\n");
    bubbleSort(a);
    printList(a);
    
    printf("{%s,%d,%d}",a->next->name,a->next->roll,a->next->marks);
    
return 0;
}
