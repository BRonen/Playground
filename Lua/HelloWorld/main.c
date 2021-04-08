#include "lua/lua.h"
#include "lua/lualib.h"
#include "lua/lauxlib.h"
#include "lua/luajit.h"

#include <stdio.h>


int test(lua_State* L){
  printf("\thello from c\n");
  return 0;
}

int main(int argc, char *argv[]){
  lua_State *L;
  
  L = luaL_newstate(); // open Lua
  if (!L) {
    return -1; // Checks that Lua started up
  }

  luaL_openlibs(L); // load Lua libraries

  lua_register(L, "test", test);

  if(luaL_dofile(L, "main.lua") != LUA_OK){ // load Lua script
    fprintf(stderr, "%s\n", lua_tostring(L, -1));
    return 1;
  }

  lua_close(L); // Close Lua
  return 0;
}