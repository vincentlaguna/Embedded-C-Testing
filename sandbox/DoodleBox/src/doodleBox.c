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


/*********************************************/
#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

#define   MAX_STR   128 

typedef   struct  node
{
  
  char            *pString;
  struct  node    *next;

} _node_t;

typedef   _node_t *pListNode;

void      insert(pListNode *head, char *pString);
void      printList(pListNode head);

int main(void)
{
  char    userString[MAX_STR];
  
  pListNode head = NULL;
  
  // head = malloc(sizeof(_node_t));
  for (int i = 0; i < 3; i++)
  {
    printf("\nEnter %d string to store at first node of the linked list: ", i);
    scanf("%s", userString);
    printf("\nString entered: %s\n\n", userString);
  
    insert(&head, userString);
  
    printf("\nString in Node 0: %s\n\n", head->pString);
  }
  
  return(0);
}

void      insert(pListNode *head, char *pString)
{
  pListNode newNode = malloc(sizeof(_node_t));
  newNode->pString  = pString;
  newNode->next     = *head;
  *head             = newNode;
}

void      printList(pListNode head)
{
  
}

/*********************************************/

/*********************************************/

/*********************************************/
