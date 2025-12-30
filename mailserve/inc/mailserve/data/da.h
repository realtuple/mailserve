#ifndef __MAILSERVE__DATA__DA_H__
#define __MAILSERVE__DATA__DA_H__

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#define MAILSERVE_DEFAULT_CAPACITY 16

#define MAILSERVE_DA(name, type)                                                                                       \
    struct name {                                                                                                      \
        size_t count;                                                                                                  \
        size_t capacity;                                                                                               \
        type  *items;                                                                                                  \
    }

#define MAILSERVE_DA_PUSH_BACK(da, item)                                                                               \
    do {                                                                                                               \
        /* I hate this allocation step */                                                                              \
        if ((da)->count == (da)->capacity) {                                                                           \
            /* calculate new capacity */                                                                               \
            if ((da)->capacity == 0)                                                                                   \
                (da)->capacity = MAILSERVE_DEFAULT_CAPACITY;                                                           \
            else                                                                                                       \
                (da)->capacity <<= 2;                                                                                  \
            void *newItems = realloc((da)->items, (da)->capacity * sizeof((da)->items[0]));                                                                 \
            assert(newItems);                                                                                          \
            ((da)->items) = newItems;                                                                                  \
        }                                                                                                              \
        ((da)->items)[((da)->count)++] = (item);                                                                       \
    } while (0)

#define MAILSERVE_DA_POP_BACK(da) (assert((da)->count != 0), --(da)->count)

#define MAILSERVE_DA_AT(da, index) ((da)->items)[(assert((index) < (da)->count), (index))]

#define MAILSERVE_DA_FREE(da)                                                                                          \
    do {                                                                                                               \
        if ((da)->items) free((da)->items);                                                                            \
        (da)->count    = 0;                                                                                            \
        (da)->capacity = 0;                                                                                            \
    } while (0)

#endif