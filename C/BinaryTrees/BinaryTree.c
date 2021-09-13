#include <stdio.h>
#include <assert.h>

#include "BinaryTree.h"

int main(){
  struct Bst *bst = bstCreate(106);

  bstInsert(bst, 729);
  bstInsert(bst, 22);
  bstInsert(bst, 62);
  bstInsert(bst, 18);
  bstInsert(bst, 52);
  bstInsert(bst, 78);
  bstInsert(bst, 9);
  bstInsert(bst, 5);
  bstInsert(bst, 92);
  bstInsert(bst, 39);
  bstInsert(bst, 26);
  bstInsert(bst, 122);
  bstInsert(bst, 38);
  bstInsert(bst, 12);
  bstInsert(bst, 2);
  bstInsert(bst, 200);
  bstInsert(bst, 1);
  bstInsert(bst, 3);
  
  /*
   *     bst concept is something
   *          like this:
   *
   *              16
   *            8    18
   *          5        38
   *        3   7
   *      2
   *    1
   */

  assert(bstSuccessor(bst, 18) ==   22);
  assert(bstSuccessor(bst,  5) ==    9);
  assert(bstSuccessor(bst, 38) ==   39);
  assert(bstSuccessor(bst,  4) ==   -1);
  assert(bstSuccessor(bst,  3) ==    5);
  assert(bstCountNodes(bst)    ==   19);
  assert(bstHeight(bst)        ==    7);
  assert(bstGetMin(bst)        ==    1);
  assert(bstGetMax(bst)        ==  729);

  assert(bstSearch(bst, 38) == 1);
  bstDelete(bst, 38);
  assert(bstSearch(bst, 38) == 0);
  //delete multiple times is safe
  bstDelete(bst, 38);
  assert(bstSearch(bst, 38) == 0);

  bstFree(bst);
  //after free bst, a trash node still on root
  //you need to set it to null
  assert(bstCountNodes(bst)    ==    1);
  assert(bstHeight(bst)        ==    1);

  assert(bstGetMin(bst)        == bst->value);
  assert(bstGetMax(bst)        == bst->value);

  //now the pointer will be really clear
  bst = NULL;
  assert(bstCountNodes(bst)    ==    0);
  assert(bstHeight(bst)        ==    0);
  assert(bstGetMin(bst)        ==    0);
  assert(bstGetMax(bst)        ==    0);

  struct Bst *badBst = bstCreate(106);
  badBst->right = bstCreate(100);
  assert(bstIsValid(badBst) == 0);
  bstFree(badBst);
  badBst = NULL;
  assert(bstIsValid(badBst) == 1);

  return 0;
}