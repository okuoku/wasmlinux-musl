#define _GNU_SOURCE
#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include <sched.h>
#include "pthread_impl.h"

extern int32_t
__attribute__((import_module("env"), import_name("wasmlinux_clone32")))
wasmlinux_clone32(uint32_t clone_start, uint32_t stack, uint32_t flags, uint32_t arg, uint32_t ptid, uint32_t tls, uint32_t ctid);

int 
__clone(int (*func)(void *), void *stack, int flags, void *arg, ...){
    va_list ap;
    pid_t* ptid = 0;
    pid_t* ctid = 0;
    void* tls = 0;

    va_start(ap, arg);

    if (flags & (CLONE_PIDFD | CLONE_PARENT_SETTID | CLONE_CHILD_SETTID)){
        ptid = va_arg(ap, pid_t *);
    }

    if (flags & CLONE_CHILD_SETTID) {
        tls = va_arg(ap, void *);
        ctid = va_arg(ap, pid_t *);
    }
    va_end(ap);

    return wasmlinux_clone32((uintptr_t)func, (uintptr_t)stack, flags, (uintptr_t)arg, (uintptr_t)ptid, 
                             (uintptr_t)tls, (uintptr_t)ctid);

}
