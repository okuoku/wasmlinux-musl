#include <stdint.h>

extern int32_t
__attribute__((import_module("env"), import_name("wasmlinux_tlsrw32")))
wasmlinux_tlsrw32(uint32_t op, uint32_t val);

int 
__set_thread_area(void *p) {
    return wasmlinux_tlsrw32(0, (uint32_t)p);
}
