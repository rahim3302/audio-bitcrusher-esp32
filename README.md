# Audio BitCrusher ESP32

A C audio-processing project that currently runs on the PC. The ESP32 stage is
planned; no board or additional audio hardware is needed for the current work.

## What works now

The program opens `440hz.wav`, skips the 44-byte header in this particular file,
and reads its first 16 signed 16-bit PCM samples. `bitcrusher_process` rounds
each sample to the nearest multiple of 256 and limits the result to the chosen
range. The program prints each input and output value.

For example, an input sample of `131` becomes `256`. This reduces amplitude
resolution, but the values are still stored as 16-bit samples. The program does
not yet process the whole file, save a new WAV, play audio, or run on the ESP32.

## Start in VS Code

Open `Audio BitCrusher ESP32.code-workspace`.

- **Build:** press `Ctrl+Shift+B`.
- **Run:** choose **Terminal > Run Task > Run C lab**.
- **Run Code:** the Code Runner button (or `Ctrl+Alt+N`) also builds and runs the
  whole project when a C file is open, including both source files and the header
  search path. Open this workspace rather than a single loose file.
- **Debug:** set a breakpoint inside `bitcrusher_process` in `src/bitcrusher.c`,
  then press `F5`. Use the Variables panel to inspect the samples.

## Project files

| File | Purpose |
| --- | --- |
| `src/main.c` | Opens the example WAV, processes 16 samples, and prints results |
| `src/bitcrusher.c` | Portable C amplitude quantization function |
| `include/bitcrusher.h` | Processing function declaration |
| `440hz.wav` | Example input file needed to run the program |
| `scripts/build.ps1` | Build using the existing GCC installation |
| `.vscode/` | Build tasks, debugger, and C language settings |
| `firmware/README.md` | Outline for the later ESP32 stage |
| `docs/pcm-notes.md` | Short notes on samples and the current effect |
| `docs/progress.md` | Dated checkpoints for resuming work later |
| `build/` | Generated executable and debug information |

## Learning milestones

1. ~~Read PCM samples from an example WAV and print them.~~
2. ~~Implement amplitude quantization in `bitcrusher_process`.~~
3. Add sample holding, preserving its state between processing calls.
4. Process a whole mono 16-bit PCM WAV and save an output WAV on the laptop.
5. Move processing onto the ESP32 using USB/serial blocks.
6. Add a potentiometer when the hardware is available.

I2S is only needed if the project later connects to an audio converter or digital
microphone. The initial USB workflow does not use I2S.

## Existing tools used

- GCC: `C:/msys64/ucrt64/bin/gcc.exe`
- GDB: `C:/msys64/ucrt64/bin/gdb.exe`
- VS Code extension: Microsoft C/C++ (`ms-vscode.cpptools`)
- Language: C11 with compiler warnings and debug information enabled

No additional packages were installed. These paths match this PC; update the
build script and VS Code configuration if moving to another computer.

## Keeping progress

After a meaningful change, record what changed and what you tested in
`docs/progress.md`, then commit the source and notes together. The `build/` folder
is ignored because it can be recreated. `440hz.wav` is included because the
program needs it to run; other WAV files remain ignored by default.

From the project folder, save a checkpoint with:

```powershell
git status
git add -A
git commit -m "Describe what changed"
git push
```

Review `git status` before adding files. A commit saves history on this PC;
`git push` copies it off the PC once a remote repository is connected. Until
then, the Git history is local only.

## Terminal commands

From the project folder in PowerShell:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\build.ps1
.\build\pcm_lab.exe
```

The execution-policy option applies only to that build process; it does not
change the machine's saved PowerShell policy.
