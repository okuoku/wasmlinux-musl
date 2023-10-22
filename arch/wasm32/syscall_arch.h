#define __SYSCALL_LL_E(x) \
((union { long long ll; long l[2]; }){ .ll = x }).l[0], \
((union { long long ll; long l[2]; }){ .ll = x }).l[1]
#define __SYSCALL_LL_O(x) __SYSCALL_LL_E((x))

extern long wasmlinux_syscall32(long no, long* in);

static inline long 
__syscall0(long n){
    return wasmlinux_syscall32(n,0);
}

static inline long 
__syscall1(long n, long a){
    long args[6];
    args[0] = a;
    args[1] = 0;
    args[2] = 0;
    args[3] = 0;
    args[4] = 0;
    args[5] = 0;
    return wasmlinux_syscall32(n, args);

}

static inline long 
__syscall2(long n, long a, long b){
    long args[6];
    args[0] = a;
    args[1] = b;
    args[2] = 0;
    args[3] = 0;
    args[4] = 0;
    args[5] = 0;
    return wasmlinux_syscall32(n, args);
}

static inline long 
__syscall3(long n, long a, long b, long c){
    long args[6];
    args[0] = a;
    args[1] = b;
    args[2] = c;
    args[3] = 0;
    args[4] = 0;
    args[5] = 0;
    return wasmlinux_syscall32(n, args);
}

static inline long 
__syscall4(long n, long a, long b, long c, long d){
    long args[6];
    args[0] = a;
    args[1] = b;
    args[2] = c;
    args[3] = d;
    args[4] = 0;
    args[5] = 0;
    return wasmlinux_syscall32(n, args);
}

static inline long 
__syscall5(long n, long a, long b, long c, long d, long e){
    long args[6];
    args[0] = a;
    args[1] = b;
    args[2] = c;
    args[3] = d;
    args[4] = e;
    args[5] = 0;
    return wasmlinux_syscall32(n, args);
}

static inline long 
__syscall6(long n, long a, long b, long c, long d, long e, long f){
    long args[6];
    args[0] = a;
    args[1] = b;
    args[2] = c;
    args[3] = d;
    args[4] = e;
    args[5] = f;
    return wasmlinux_syscall32(n, args);
}

