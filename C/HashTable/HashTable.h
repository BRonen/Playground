#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned int hashCode(char *key, unsigned int hashSize) {
  unsigned long hash = 5381;
  unsigned int c;
  while((c = *key++)) {
    hash = ((hash << 5) + hash) + c; // hash * 33 + c
  }
  return hash % hashSize;
};

/* Node */

struct Node {
  char *key;
  char *value;
  struct Node* next;
};

struct Node* nodeCreate(char *key, char *value) {
  struct Node *node = malloc(sizeof(struct Node));
  node->key = key;
  node->value = value;
  node->next = NULL;
  return node;
};

/* Hash Table */

struct HashTable {
  struct Node **list;
  int length;
};

struct HashTable* hashtableCreate(unsigned int length){
  struct HashTable *hashtable = malloc(sizeof(struct HashTable));
  hashtable->list = malloc(sizeof(struct Node*)*length);
  hashtable->length = length;

  for(int i = 0; i < length; i++){
    hashtable->list[i] = NULL;
  }

  return hashtable;
}



void hashtableInsert(struct HashTable *hashtable, char *key, char *value) {
  unsigned int index = hashCode(key, hashtable->length);
  struct Node *node = hashtable->list[index];
  if(node == NULL){
    hashtable->list[index] = nodeCreate(key, value);
  }else{
    while(node) {
      if(strcmp(node->key, key) == 0){
        struct Node *tmp = node;
        hashtable->list[index] = nodeCreate(key, value);
        free(tmp);
      }
      if (node->next == NULL) {
        node->next = nodeCreate(key, value);
        break;
      }
      node = node->next;
    }
  }
};

char* hashtableSearch(struct HashTable *hashtable, char *key) {
  unsigned int index = hashCode(key, hashtable->length);
  struct Node *node = hashtable->list[index];
  while(node) {
    if (strcmp(node->key, key) == 0) {
      return node->value;
    }
    node = node->next;
  }
  return "";
}

void hashtableDelete(struct HashTable *hashtable, char *key){
  unsigned int index = hashCode(key, hashtable->length);
  struct Node *node = hashtable->list[index];
  
  //if first node from linkedlist of this index
  //is the key we search then swap with the next
  if(strcmp(node->key, key) == 0){
    hashtable->list[index] = node->next;
    free(node);
    return;
  }

  //while not in the end, get the next node as *ptr
  //when get the right node then swap with next
  while(node){
    struct Node *ptr = node->next;
    if(strcmp(ptr->key, key) == 0){
      node->next = ptr->next;
      free(ptr);
    }
    node = node->next;
  }
}

void hashtableDump(struct HashTable *hashtable){
  printf("\n");

  for(int i = 0; i < hashtable->length; i++){
    printf("%d {\n", i);
    struct Node* ptr = hashtable->list[i];
    while(ptr != NULL){
      printf("\t#%x\t%s => %s\t#%x\n", ptr, ptr->key, ptr->value, ptr->next);
      ptr = ptr->next;
    }
    printf("}\n\n");
  }

  printf("\n");
}
