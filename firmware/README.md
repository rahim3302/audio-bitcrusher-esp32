# ESP32 firmware stage

This folder is reserved for the hardware part of the project.

First use the desktop C lab to understand PCM and build the processing function.
The code in `src/bitcrusher.c` and `include/bitcrusher.h` is independent of desktop
or ESP32 APIs, so it can be reused in the firmware later.

When the board is available:

1. Identify its exact chip and USB connection.
2. Upload and verify a serial echo program.
3. Transfer PCM blocks from the laptop and return them unchanged.
4. Call the C processing function for each received block.

No ESP32 target, COM port, or firmware toolchain has been selected yet.
The VS Code build and debugger currently target the PC, not the ESP32.
