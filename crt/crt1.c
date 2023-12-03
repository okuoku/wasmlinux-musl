#include <features.h>
#include "libc.h"

#define START "_start"

#include "crt_arch.h"

#ifndef __wasm__
int main();
#else
int __main_argc_argv(int ac, char** av);
weak int main(int ac, char** av, char** envp){
	(void) envp;
	return __main_argc_argv(ac, av);
}
static int wasmlinux_libc_main(int ac, char** av, char** envp){
	main(ac, av, envp);
}
#endif

weak void _init();
weak void _fini();
int __libc_start_main(int (*)(), int, char **,
	void (*)(), void(*)(), void(*)());

void _start_c(long *p)
{
	int argc = p[0];
	char **argv = (void *)(p+1);
#ifndef __wasm__
	__libc_start_main(main, argc, argv, _init, _fini, 0);
#else
	__libc_start_main(wasmlinux_libc_main, argc, argv, _init, _fini, 0);
#endif
}

