#include <stdlib.h>
#include <limits.h>

struct Bst{
  int value;
  struct Bst *left;
  struct Bst *right;
};

struct Bst* bstCreate(int value){
  struct Bst *bst = malloc(sizeof(struct Bst));

  bst->value = value;

  bst->left  = NULL;
  bst->right = NULL;
  return bst;
}

void bstFree(struct Bst *bst){
  if(bst == NULL)
    return;

  bstFree(bst->left);
  bst->left = NULL;
  bstFree(bst->right);
  bst->right = NULL;
  free(bst);
}

int bstGetMin(struct Bst *bst){
  if(bst == NULL)
    return 0;

  struct Bst *tmp = bst;

  while(tmp->left){
    tmp = tmp->left;
  }

  return tmp->value;
}


int bstGetMax(struct Bst *bst){
  if(bst == NULL)
    return 0;

  struct Bst *tmp = bst;

  while(tmp->right){
    tmp = tmp->right;
  }

  return tmp->value;
}

void bstInsert(struct Bst *bst, int value){
  if(value == bst->value)
    return;
  //if value is higher then insert at right
  if(value > bst->value){
    //if right isn't NULL then insert
    if(bst->right){
      bstInsert(bst->right, value);
      return;
    }
    //if right is NULL then create
    bst->right = bstCreate(value);
    return;
  }
  //if value is lower then insert at left
  //and if left isn't NULL then insert
  if(bst->left){
    bstInsert(bst->left, value);
    return;
  }
  //if left is NULL then create
  bst->left = bstCreate(value);
  return;
}

struct Bst* bstDelete(struct Bst *bst, int value){
  if(bst == NULL)
    return bst;
  //search for value and bstDelete
  if(value < bst->value){
    bst->left = bstDelete(bst->left, value);
  }else if(value > bst->value){
    bst->right = bstDelete(bst->right, value);
  //found it
  }else{
    //if dont has childs node just delete it
    if(bst->left == NULL && bst->right == NULL){
      free(bst);
      bst = NULL;
    //if has then switch it with child before
    }else if (bst->left == NULL){
      struct Bst *tmp = bst;
      bst = bst->right;
      free(tmp);
    }else if (bst->right == NULL){
      struct Bst *tmp = bst;
      bst = bst->left;
      free(tmp);
    //if has both childs then switch with min of right child tree
    }else{
      int min = bstGetMin(bst->right);
      bst->value = min;
      bst->right = bstDelete(bst->right, min);
    }
  }

  //return child node
  return bst;
}

int bstSearch(struct Bst *bst, int value){
  if(bst == NULL)
    return 0;

  if(value < bst->value){
    return bstSearch(bst->left, value);
  }else if(value > bst->value) {
    return bstSearch(bst->right, value);
  }else{
    return 1;
  }
}

int bstSuccessor(struct Bst *bst, int value){
  struct Bst *tmp = bst;

  while(tmp->value != value){
    //search for node with the value
    if(tmp->value > value){
      tmp = tmp->left;

    }else if(tmp->value < value){
      tmp = tmp->right;
    }
    //if value dont exists then return -1
    if(tmp == NULL){
      return -1;
    }
  }

  if(tmp->right != NULL){
    return bstGetMin(tmp->right);
  }

  tmp = NULL;
  
  while(bst != NULL){
    //get lowest ancestor that is a left child in the path to target value
    if (value < bst->value){
      tmp = bst;
      bst = bst->left;
    }else{
      bst = bst->right;
    }
  }

  return tmp->value;
}

int bstHeight(struct Bst *bst) {
  if(bst == NULL)
    return 0;

  int leftHeight  = bstHeight(bst->left);
  int rightHeight = bstHeight(bst->right);

  int maxValue = (
    leftHeight > rightHeight ?
    leftHeight : rightHeight
  );

  return 1 + maxValue;
}


int bstCountNodes(struct Bst *bst){
  if(bst == NULL)
    return 0;

  return 1 + bstCountNodes(bst->left) + bstCountNodes(bst->right);
}

int bstIsBetween(struct Bst *bst, int min, int max) {
  if(bst == NULL)
    return 1;

  // ensure subtrees are not hiding a value lower or higher than the subtree
  // allows
  return bst->value > min && bst->value < max &&
         bstIsBetween(bst->left, min, bst->value) &&
         bstIsBetween(bst->right, bst->value, max);
}

int bstIsValid(struct Bst *bst){
  if(bst == NULL)
    return 1;

  return bstIsBetween(bst, INT_MIN, INT_MAX);
}

void bstPrint(struct Bst *bst){
  if(bst == NULL)
    return;

  bstPrint(bst->left);
  printf("%d\n", bst->value);
  bstPrint(bst->right);
}