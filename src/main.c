#include <stdio.h>
#include "bitcrusher.h"

int main(void)
{
    FILE *file = fopen("440hz.wav", "rb");

    if (file == NULL) {
        puts("Could not open file.");
        return 1;
    }

    // Verified start of audio in this particular file.
    fseek(file, 44, SEEK_SET);

    int16_t input[16];
    int16_t output[16];

    size_t count = fread(input, sizeof(int16_t), 16, file);

    bitcrusher_process(input, output, count);

    puts("Input -> Crushed output");

    for (size_t i = 0; i < count; i++) {
        printf("%d -> %d\n", (int)input[i], (int)output[i]);
    }

    fclose(file);
    return 0;
}