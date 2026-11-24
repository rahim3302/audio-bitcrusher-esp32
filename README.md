# Audio Bitcrusher — Desktop C Prototype

This is my first desktop implementation of a bitcrusher in C. I built it to understand PCM samples and amplitude quantization before moving the effect to the ESP32.

The program reads the first 16 signed 16-bit PCM samples from the included `440hz.wav`, quantizes them to the nearest multiple of 256, and prints the input and output values. For example, an input sample of `131` becomes `256`.

The ESP32 version with Bluetooth output and Wi-Fi controls is in the [ESP32 Bitcrusher project](https://github.com/rahim3302/esp32-bitcrusher-bluetooth-wifi).

## Build and run

1. Open `Audio BitCrusher ESP32.code-workspace` in VS Code.
2. Build with **Ctrl+Shift+B**.
3. Run **Terminal > Run Task > Run C lab**.

The project uses C11 and GCC.

## Project files

| File | Purpose |
| --- | --- |
| `src/main.c` | Reads the WAV samples and prints the processed values |
| `src/bitcrusher.c` | Implements amplitude quantization |
| `include/bitcrusher.h` | Declares the bitcrusher function |
| `440hz.wav` | Example input file |
| `scripts/build.ps1` | Builds the program with GCC |
| `docs/pcm-notes.md` | Notes on PCM samples and quantization |

## Current limitations

This prototype skips a 44-byte header in the included WAV and processes only its first 16 samples. It does not process the whole file, save a processed WAV, or play audio.

A possible next step for this desktop version is to process the whole WAV and save the result. The ESP32 implementation is documented in the separate project linked above.
