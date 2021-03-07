#include <assert.h>
#include "LinkedList.h"


void main() {
  struct List list = listCreate();
  
  assert(listIsEmpty(&list) == 1);
  
  listPushFront(&list, 189);
  listPushFront(&list, 298);
  listPushFront(&list, 376);
  listPushFront(&list, 456);
  listPushFront(&list, 545);
  listPushFront(&list, 643);
  listPushFront(&list, 722);
  
  assert(listSize(&list) == 7);
  
  assert(listAtIndex(&list, 2)->data == 376);
  
  assert(list.index == listPopFront(&list)->index);
  
  assert(listSize(&list) == 6);
  
  assert(listAtIndex(&list, list.index) == listFront(&list));
  
  assert(listAtIndex(&list, 0) == listBack(&list));
  
  struct List tmpCopy = list;
  
  listPushBack(&list, 42);
  listPushBack(&list, 42);
  listPushBack(&list, 42);
  
  listPopBack(&list);
  listPopBack(&list);
  listPopBack(&list);
  
  assert(listSize(&tmpCopy) == listSize(&list));
  
  listInsert(&list, 3, 43);
  
  assert(listAtIndex(&list, 3)->data == 43);
  
  listRemove(&list, 3);
  
  assert(listAtIndex(&list, 3)->data != 43);
  
  listClear(&list);
  
  assert(listIsEmpty(&list) == 1);
  
  listPushBack(&list, 123);
  listPushBack(&list, 234);
  listPushBack(&list, 345);
  listPushBack(&list, 456);
  listPushBack(&list, 567);
  listPushBack(&list, 678);
  listPushBack(&list, 789);
  
  assert(listSize(&list) == 7);
  
  assert(listAtIndex(&list, 2)->data == 567);
  
  assert(0 == listPopBack(&list)->index);
  
  assert(listSize(&list) == 6);
  
  assert(listAtIndex(&list, list.index) == listFront(&list));
  
  assert(listAtIndex(&list, 0) == listBack(&list));
  
  listClear(&list);
  
  assert(listIsEmpty(&list) == 1);
}
