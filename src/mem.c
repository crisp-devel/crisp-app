#include <core.h>
#include <string.h>

void
    mem_set
        (void* des, u8_t set, u64_t len) {
            if (!len) return;
            if (!des) return;

            memset(des, set, len);
}

void
    mem_copy
        (void* des, void* src, u64_t len) {
            if (!des) return;
            if (!src) return;
            if (!len) return;

            memcpy(des, src, len);
}

void
    mem_move
        (void* des, void* src, u64_t len) {
            if (!des) return;
            if (!src) return;
            if (!len) return;

            memmove(des, src, len);
}

u64_t
    mem_find
        (void* des, void* src, u64_t dlen, u64_t slen) {
            if (dlen > slen) return -1;
            return (u64_t) strstr     (
                des,
                src
            );
}

ord_t
    mem_ord
        (void* des, void* ord, u64_t len) {
            if (!des) return ord_err;
            if (!ord) return ord_err;
            if (!len) return ord_err;

            int ret = memcmp (des, ord, len);
            if (ret < 0) return ord_lt;
            if (ret > 0) return ord_gt;
            return ord_eq;
}

bool_t mem_eq(void* des, void* ord, u64_t len) { return mem_ord(des, ord,len) == ord_eq; }
bool_t mem_gt(void* des, void* ord, u64_t len) { return mem_ord(des, ord,len) == ord_gt; }
bool_t mem_lt(void* des, void* ord, u64_t len) { return mem_ord(des, ord,len) == ord_lt; }