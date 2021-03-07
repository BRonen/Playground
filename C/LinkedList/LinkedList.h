#include <stdio.h>
#include <stdlib.h>

struct Node{
   int index;
   int data;
   struct Node *next;
};

struct List{
  int index;
  int length;
  struct Node *head;
};

struct List listCreate(){
  struct List list;
  list.index = -1;
  list.length = 0;
  list.head = NULL;
  
  return list;
}

void listClear(struct List *list){
  struct Node *node = list->head;
  while(node->index != 0){
    struct Node *tmp = node->next;
    free(node);
    node = tmp;
  }
  free(node);
  list->index = -1;
  list->length = 0;
  list->head = NULL;
}

int listIsEmpty(struct List *list){
  if(list->length == 0)
    return 1;
  else
    return 0;
}

int listSize(struct List *list){
  return list->length;
}

void listPushFront(struct List *list, int value){
  struct Node *node = (struct Node*)malloc(sizeof(struct Node));
  
  node->index = list->length;
  list->length++;
  
  list->index++;
  
  node->next = list->head;
  list->head = node;
  
  node->data = value;
}

struct Node *listPopFront(struct List *list){
  struct Node *node = list->head;
  list->head = node->next;
  
  list->index--;
  list->length--;
  
  return node;
}

void listPushBack(struct List *list, int value){
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  
  newNode->index = 0;
  newNode->data = value;
  newNode->next = NULL;
  
  if(list->head != NULL){
    struct Node *node;
    
    for(node = list->head; node->index != 0; node = node->next){
      node->index++;
    }
    
    node->index++;
    node->next = newNode;
    
  }else{
    list->head = newNode;
  }

  list->index++;
  list->length++;
}

struct Node *listPopBack(struct List *list){
  struct Node *node;
  
  
  for(node = list->head; node->index != 1; node = node->next){
    node->index--;
  }
  node->index--;
  
  free(node->next);
  node->next = NULL;
  list->index--;
  list->length--;
  
  return node;
}

struct Node *listFront(struct List *list){
  return list->head;
}

struct Node *listBack(struct List *list){
  struct Node *node;
  for(node = list->head; node->index != 0; node = node->next){
  }
  return node;
}

struct Node *listAtIndex(struct List *list, int index){
  struct Node *node = list->head;
  
  while(node->index != index){
    node = node->next;
  }
  return node;
}

struct Node *listInsert(struct List *list, int index, int value){
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  
  newNode->index = index;
  newNode->data = value;
  newNode->next = NULL;
  
  struct Node *node;
  
  for(node = list->head; node->index != index; node = node->next){
    node->index++;
  }
  node->index++;
  newNode->next = node->next;
  node->next = newNode;

  list->index++;
  list->length++;
}

struct Node *listRemove(struct List *list, int index){
  struct Node *node;
  struct Node *tmp;
  
  for(node = list->head; node->index != index + 1; node = node->next){
    node->index--;
  }
  node->index--;
  tmp = node->next;
  node->next = tmp->next;
  free(tmp);

  list->index--;
  list->length--;
}

void nodePrint(struct Node *node){
  printf("\t(%d,%d,#%x)\n",node->index, node->data, node->next);
}

void listPrint(struct List *list) {
  if(list->length == 0){
    printf("\nactual list:\n");
    printf("  %d  %d\n { \n", list->index, list->length);
    
    printf("\n }\n");

  }else{
    struct Node *node = list->head;
    printf("\nactual list:\n");
    printf("  %d  %d\n { \n", list->index, list->length);
    
    nodePrint(node);
    
    while(node->next != NULL){
      node = node->next;
      nodePrint(node);
    }
    
    printf("\n }\n");
  }
}

