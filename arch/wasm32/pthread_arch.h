extern int32_t
__attribute__((import_module("env"), import_name("wasmlinux_tlsrw32")))
wasmlinux_tlsrw32(uint32_t op, uint32_t val);

static inline uintptr_t 
__get_tp(){
    return wasmlinux_tlsrw32(1, 0);
}
