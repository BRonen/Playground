#include <assert.h>
#include <string.h>
#include "HashTable.h"

int main() {
  struct HashTable *hash = hashtableCreate(50);

  //hashtableDump(hash);

  hashtableInsert(hash, "hello", "world");
  hashtableInsert(hash, "24323", "world");
  hashtableInsert(hash, "&*@#)", "world");
  hashtableInsert(hash, "     ", "world");

  //hashtableDump(hash);
  
  /*
  printf("\thello => %s\n", hashtableSearch(hash, "hello"));
  printf("\t24323 => %s\n", hashtableSearch(hash, "24323"));
  printf("\t&*@#) => %s\n", hashtableSearch(hash, "&*@#)"));
  printf("\t      => %s\n", hashtableSearch(hash, "     "));
  */

  assert(strcmp(hashtableSearch(hash, "hello"), "world") == 0);
  assert(strcmp(hashtableSearch(hash, "24323"), "world") == 0);
  assert(strcmp(hashtableSearch(hash, "&*@#)"), "world") == 0);
  assert(strcmp(hashtableSearch(hash, "     "), "world") == 0);

  hashtableInsert(hash, "hello", "world2");
  //hashtableDump(hash);
  assert(strcmp(hashtableSearch(hash, "hello"), "world2") == 0);

  hashtableDelete(hash, "hello");
  //hashtableDump(hash);
  assert(strcmp(hashtableSearch(hash, "hello"), "") == 0);

  return 0;
}