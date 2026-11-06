#ifndef BITCRUSHER_H
#define BITCRUSHER_H

#include <stddef.h>
#include <stdint.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Both arrays must contain at least sample_count elements. */
void bitcrusher_process(const int16_t *input, int16_t *output,
                        size_t sample_count);

#ifdef __cplusplus
}
#endif

#endif
