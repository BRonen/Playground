#include <stdio.h>
#include <stdlib.h>

struct Node{
   int data;
   struct Node *next;
};

struct QueueLL{
  int length;
  struct Node *head;
  struct Node *tail;
};

struct QueueLL queueLLCreate(){
  struct QueueLL queueLL;
  queueLL.length = 0;
  queueLL.head = NULL;
  queueLL.tail = NULL;
  
  return queueLL;
}

int queueLLIsEmpty(struct QueueLL *queueLL){
  if(queueLL->length == 0)
    return 1;
  else
    return 0;
}

void queueLLPush(struct QueueLL *queueLL, int data){
  struct Node *node = malloc(sizeof(struct Node));
  
  node->data = data;
  
  if(queueLLIsEmpty(queueLL)){
    node->next = NULL;
    
    queueLL->head = queueLL->tail = node;
    
  }else{
    queueLL->tail->next = node;
    queueLL->tail = node;
  }
  
  queueLL->length++;
}

int queueLLPull(struct QueueLL *queueLL){
  struct Node *tmp = queueLL->head;
  int data = queueLL->head->data;
  
  queueLL->head = queueLL->head->next;
  
  free(tmp);
  
  queueLL->length--;
  return(data);
}

void nodePrint(struct Node *node){
  printf("\t(%d <=> #%x)\n",node->data, node->next);
}

void queueLLPrint(struct QueueLL *queueLL) {
  if(queueLL->length == 0){
    printf("\nactual queueLL:\n");
    printf("  %d \n { \n", queueLL->length);
    
    printf("\n }\n");

  }else{
    struct Node *node = queueLL->head;
    printf("\nactual queueLL:\n");
    printf("  %d \n { \n", queueLL->length);
    
    nodePrint(node);
    
    while(node->next != NULL){
      node = node->next;
      nodePrint(node);
    }
    
    printf("\n }\n");
  }
}

