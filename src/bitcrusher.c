#include "bitcrusher.h"


float quantization(float sample, float step){

    return roundf (sample/step) * step;

}

void bitcrusher_process(const int16_t *input, int16_t *output,
                        size_t sample_count)
{

const float step = 256.0;
    for (size_t i = 0; i < sample_count; ++i) {
        float crushed = quantization(input[i], step);

        // Keep the result within the chosen quantization range.
        if (crushed > 32512.0) {
            crushed = 32512.0;
        }

        if (crushed < -32768.0) {
            crushed = -32768.0;
        }

        output[i] = (int16_t)crushed  ;
    }
}
