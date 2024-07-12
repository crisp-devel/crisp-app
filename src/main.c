#include <core.h>
#include <stdlib.h>

int do_run(mem* mem, int(*func)(any_t), any_t arg);

static any_t do_mem_new(u32_t count, va_list arg) { return do_run; }
static void  do_mem_del(any_t mem)                { return; }

static any_t do_mem_use (any_t mem, void* hint, u64_t size) { return malloc(size); }
static any_t do_mem_free(any_t mem, void* addr, u64_t size) { free (addr); }

static mem_ops
    do_mem_ops = make_mem_ops (
        do_mem_use ,
        do_mem_free,
        do_mem_new ,
        do_mem_del
);

static mem do_mem;

int main()                                                     {
    if (!make_at (&do_mem, mem) from (1, &do_mem_ops)) return 0;
    return do_run(&do_mem, null_t, null_t);
}