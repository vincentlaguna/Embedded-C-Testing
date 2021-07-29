/*********************************************
#include <stdio.h>
#include <stdlib.h>
// Definition for singly-linked list.
struct ListNode 
{
  int val;
  struct ListNode *next;
} listNodeArr[3];

// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
// {
//   struct ListNode *retNode = NULL;
//   retNode = (struct ListNode*)malloc(sizeof(struct ListNode));
//   // retNode->val = 1;
//   retNode->val = l1->val + l2->val;
//   printf("%d\n\n", retNode->val);
    
//   return retNode;
// }

int main(void)
{
  for (int i = 0; i < 3; i++)
  {
    struct listNodeArr->val = i;
  }
  
  for (int i = 0; i < 3; i++)
  {
    while (struct listNodeArr[i]->next != NULL)
    {
      printf("\nlistNodeArr[%d]->val = %d\n\n", struct listNodeArr[i]->val);
    }
  }
  // struct ListNode *l1, *l2;
  
  // l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
  // l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
  
  // l1->val = 2;
  // l2->val = 2;
  
  // printf("\nl1->val = %d, l2->val = %d\n\n", l1->val, l2->val);
  
  // addTwoNumbers(l1, l2);
  
  // printf("\nretNode->val = %d\n\n", retNode->val);
  
  return(0);
}

/*********************************************/


/*********************************************

#include <stdio.h>

int main(int argc, char **argv)
{
  puts("\nHello World!\n\n");
  
  return(0);
}

/*********************************************/  

/*************** Ejercicio 3.5 ***************/

/*********************************************/

/*********************************************/  

/*********************************************/
#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

#define   MAX_STR   128 

typedef   struct
{
  char    string[MAX_STR];
  struct _node_t *next;
} _node_t;

_node_t *head = NULL;

void insertAtHead(_node_t *p, char *string);

int main(void)
{
  
  char *entry = '\0';
  // head = (_node_t*)malloc(sizeof(_node_t));
  
  if (!head)
  {
    printf("Malloc Failed.\n");
    return -1;
  }
  else
  {
    printf("\nEnter String: ");
    scanf("%s", head->string);
  }
  
  _node_t *node1 = NULL;
  node1 = (_node_t*)malloc(sizeof(_node_t));
  
  if (!node1)
  {
    printf("Malloc Failed.\n");
    return -1;
  }
  else
  {
    printf("\nEnter String for node1: ");
    scanf("%s", node1->string);
    head->next = node1->next;
    node1->next = next;
  }
  
  printf("\n%s, %s\n\n", head->next, node1->???)                              

  return(0);
}

void insertAtHead(_node_t *p, char *string) 
{
    _node_t *current = (_node_t *)malloc(sizeof(_node_t));
    current = p;
}


/*********************************************/

/*********************************************/

/*********************************************/
