#include <assert.h>

struct Test{
   int var1;
   int var2;
   int var3;
};

void compareAB(struct Test* a, struct Test* b){
    assert(b->var1 == a->var1);
    assert(b->var2 == a->var2);
    assert(b->var3 == a->var3);
}

int main(){
   struct Test a;
   struct Test b;

   a.var1 = 0;
   a.var2 = 1;
   a.var3 = 2;

   b.var1 = 0;
   b.var2 = 1;
   b.var3 = 2;

   compareAB(&a, &b);

   return 0;
}
