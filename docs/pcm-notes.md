# PCM and bitcrusher notes

## A sample is a number

In this project, each input sample is an `int16_t`: a signed 16-bit number stored
in 2 bytes. Its possible values range from `-32768` to `32767`. A sample value
such as `131` is a sound amplitude at one instant, not a count of bits.

The `256` in `src/bitcrusher.c` is the **step between allowed output values**.
The function calculates `roundf(sample / 256) * 256`. For example:

| Input sample | Nearest multiple of 256 | Output sample |
| ---: | ---: | ---: |
| 112 | 0 | 0 |
| 131 | 256 | 256 |
| 1000 | 1024 | 1024 |
| -1000 | -1024 | -1024 |

The function also clamps the result to `-32768` through `32512`, so the output
has 256 possible amplitude levels. It still stores each output in an `int16_t`.
This changes amplitude resolution, not the number of samples per second.

## What the current program shows

`src/main.c` reads only the first 16 samples of `440hz.wav`. The first 12
input values (`0` through `112`) become `0`; the next four (`131` through `196`)
become `256`. The program prints these pairs. It does not save or play audio.

The fixed 44-byte skip in `main.c` was chosen for this particular WAV. It is not
a general WAV reader yet.

## Terms for later

- **Amplitude quantization:** round each sample value to an allowed level. This
  is what the current bitcrusher function does.
- **Sample holding:** repeat one sample value for several sample positions. This
  is a separate effect planned for a later exercise.
