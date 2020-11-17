#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include <stdio.h>

int test(lua_State* L){
  printf("\thello from c\n");
  return 0;
}

int main(int argc, char *argv[]){
  lua_State* L;

  L = luaL_newstate();
  if (!L) {
    return -1;
  }

  luaL_openlibs(L);

  lua_register(L, "test", test);

  int ret = luaL_dostring(L, "return 0");
  if (ret != 0) {
    fprintf(stderr, "%s\n", lua_tostring(L, -1));
    return 1;
  }

  //printf(argv[1]);
  if(!argv[1]){
    fprintf(stderr, "Usage: ./(program bin) LuaFile.lua\n");
  }
  ret = luaL_dofile(L, argv[1]);
  if (ret != 0) {
    fprintf(stderr, "%s\n", lua_tostring(L, -1));
    return 1;
  }

  lua_close(L);
  return 0;
}
