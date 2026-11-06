$ErrorActionPreference = 'Stop'
$projectRoot = Split-Path -Parent $PSScriptRoot

& (Join-Path $PSScriptRoot 'build.ps1')
& (Join-Path $projectRoot 'build\pcm_lab.exe')
if ($LASTEXITCODE -ne 0) {
    throw "Program exited with code $LASTEXITCODE."
}
