/*
 * lua-ar.c: lua binding for Ar
 *
 * Primary contact:
 *     weiz@us.ibm.com
 */

#if defined (__cplusplus)
extern "C" {
#endif

#include <string.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
/* torch/install/include/TH/generic */
#include <TH/TH.h>
/* torch/install/include */
#include <luaT.h>
/* #include <TH/generic/THStorage.h> */

#if defined (__cplusplus)
}
#endif

#include "ar.h"

typedef struct {
	void  *data;
	long   size;
	int    refcount;
	char   flag;
} lar_THStorage;

static int lar_init(lua_State *L)
{

	init();
	return 0;
}


/* THStorage: torch/pkg/torch/lib/TH/generic/THStorage.h */
static int lar_allreduce(lua_State *L)
{

	lar_THStorage  *t;
	const char *type;

	type = luaT_typename(L, 1);
	t = luaT_toudata(L, 1, type);
	int sz =  luaL_checkint(L, 2);
	allreduce((float*) t->data, sz);
	
	return 0;
}

static int lar_finalize(lua_State *L){
  finalize();
  return 0;
}

static int lgadei_get_rank(lua_State *L){
	int res = getRank();
	lua_pushinteger(L, res); // push integer on the stack
	return 1; // 1 means the number of returns is 1
}

static const struct luaL_Reg lar_functions[] = {
	{ "init",          lar_init   },
	{ "allreduce",		   lar_allreduce},
	{ "finalize", lar_finalize},
	{ NULL,            NULL                 },
};
 
int luaopen_liblar(lua_State *L)
{
	/* Create the metatable and put it on the stack. */
	luaL_newmetatable(L, "LAr");
	/* Duplicate the metatable on the stack (We know have 2). */
        lua_pushvalue(L, -1);

	/* Pop the first metatable off the stack and assign it to __index
	 * of the second one. We set the metatable for the table to itself.
	 * This is equivalent to the following in lua:
	 * metatable = {}
	 * metatable.__index = metatable
	lua_setfield(L, -2, "__index");
	 */
 
#if LUA_VERSION_NUM == 501
	/* LUA 5.1, LUAJIT 2.0, LUAJIT 2.1 */
	/* setup obejct methods */
	luaL_register(L, NULL, lar_functions);
#else
	/* Set the methods to the metatable that should be accessed via
	 * object:func
	 */
	luaL_setfuncs(L, lar_functions, 0);
 
	/* for compile warning luaL_typerror */
	if (false)
		luaL_typerror(L, 0, "holding");
#endif

	return 1;
}

