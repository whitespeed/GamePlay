#ifndef LUA_SCRIPT_H_
#define LUA_SCRIPT_H_

namespace gameplay
{

// Lua bindings for Script.
int lua_Script__gc(lua_State* state);
int lua_Script_addRef(lua_State* state);
int lua_Script_functionExists(lua_State* state);
int lua_Script_getPath(lua_State* state);
int lua_Script_getRefCount(lua_State* state);
int lua_Script_getScope(lua_State* state);
int lua_Script_release(lua_State* state);
int lua_Script_reload(lua_State* state);

void luaRegister_Script();

}

#endif
