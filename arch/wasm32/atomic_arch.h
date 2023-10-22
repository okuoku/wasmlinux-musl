#define a_cas a_cas

static inline int
a_cas(volatile int *p, int t, int s){
    return __sync_val_compare_and_swap(p, t, s);
}
