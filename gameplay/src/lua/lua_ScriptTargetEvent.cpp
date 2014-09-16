#include "Base.h"
#include "ScriptController.h"
#include "lua_ScriptTargetEvent.h"
#include "Base.h"
#include "ScriptController.h"
#include "ScriptTarget.h"

namespace gameplay
{

void luaRegister_ScriptTargetEvent()
{
    const luaL_Reg lua_members[] = 
    {
        {"getArgs", lua_ScriptTargetEvent_getArgs},
        {"getName", lua_ScriptTargetEvent_getName},
        {NULL, NULL}
    };
    const luaL_Reg* lua_statics = NULL;
    std::vector<std::string> scopePath;
    scopePath.push_back("ScriptTarget");

    gameplay::ScriptUtil::registerClass("ScriptTargetEvent", lua_members, lua_ScriptTargetEvent__init, lua_ScriptTargetEvent__gc, lua_statics, scopePath);
}

static ScriptTarget::Event* getInstance(lua_State* state)
{
    void* userdata = luaL_checkudata(state, 1, "ScriptTargetEvent");
    luaL_argcheck(state, userdata != NULL, 1, "'ScriptTargetEvent' expected.");
    return (ScriptTarget::Event*)((gameplay::ScriptUtil::LuaObject*)userdata)->instance;
}

int lua_ScriptTargetEvent__gc(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                void* userdata = luaL_checkudata(state, 1, "ScriptTargetEvent");
                luaL_argcheck(state, userdata != NULL, 1, "'ScriptTargetEvent' expected.");
                gameplay::ScriptUtil::LuaObject* object = (gameplay::ScriptUtil::LuaObject*)userdata;
                if (object->owns)
                {
                    ScriptTarget::Event* instance = (ScriptTarget::Event*)object->instance;
                    SAFE_DELETE(instance);
                }
                
                return 0;
            }

            lua_pushstring(state, "lua_ScriptTargetEvent__gc - Failed to match the given parameters to a valid function signature.");
            lua_error(state);
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_ScriptTargetEvent__init(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 0:
        {
            void* returnPtr = (void*)new ScriptTarget::Event();
            if (returnPtr)
            {
                gameplay::ScriptUtil::LuaObject* object = (gameplay::ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(gameplay::ScriptUtil::LuaObject));
                object->instance = returnPtr;
                object->owns = true;
                luaL_getmetatable(state, "ScriptTargetEvent");
                lua_setmetatable(state, -2);
            }
            else
            {
                lua_pushnil(state);
            }

            return 1;
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 0).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_ScriptTargetEvent_getArgs(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                ScriptTarget::Event* instance = getInstance(state);
                const char* result = instance->getArgs();

                // Push the return value onto the stack.
                lua_pushstring(state, result);

                return 1;
            }

            lua_pushstring(state, "lua_ScriptTargetEvent_getArgs - Failed to match the given parameters to a valid function signature.");
            lua_error(state);
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_ScriptTargetEvent_getName(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                ScriptTarget::Event* instance = getInstance(state);
                const char* result = instance->getName();

                // Push the return value onto the stack.
                lua_pushstring(state, result);

                return 1;
            }

            lua_pushstring(state, "lua_ScriptTargetEvent_getName - Failed to match the given parameters to a valid function signature.");
            lua_error(state);
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

}
