# Progress log

Add a short entry after each meaningful change: what changed, what you ran or
checked, and the next step. Commit the log with the code so the checkpoint is
easy to understand later.

## 2026-11-06 — VS Code commit routine

- Added a Source Control workflow to the README so future commits can be
  reviewed, made, and synced without copying terminal commands.
- Checked the steps against the current VS Code Source Control documentation.

## 2026-11-06 — First Git checkpoint

- Current PC program reads the first 16 samples from `440hz.wav`, rounds each
  value to a multiple of 256, and prints the input and output pairs.
- The C build and run completed successfully with the current example file.
- ESP32 firmware, sample holding, full-file processing, and audio output are
  still future stages.
- Updated the README and these notes to match the current code. Included the
  example WAV in version control so a fresh checkout can run the program.

## Next working session

- Decide whether to add sample holding next or make the PC program process and
  save a complete WAV first.
