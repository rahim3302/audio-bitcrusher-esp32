$ErrorActionPreference = 'Stop'
$projectRoot = Split-Path -Parent $PSScriptRoot
$compilerPath = 'C:\msys64\ucrt64\bin\gcc.exe'
$buildDirectory = Join-Path $projectRoot 'build'

if (-not (Test-Path -LiteralPath $compilerPath)) {
    throw "C compiler not found at $compilerPath. Update scripts/build.ps1 and .vscode/settings.json to match your compiler."
}

New-Item -ItemType Directory -Path $buildDirectory -Force | Out-Null
$compilerArguments = @(
    '-std=c11', '-Wall', '-Wextra', '-Wpedantic', '-g3', '-O0',
    '-I', (Join-Path $projectRoot 'include'),
    (Join-Path $projectRoot 'src\main.c'),
    (Join-Path $projectRoot 'src\bitcrusher.c'),
    '-o', (Join-Path $buildDirectory 'pcm_lab.exe')
)
& $compilerPath @compilerArguments
if ($LASTEXITCODE -ne 0) {
    throw "Build failed with exit code $LASTEXITCODE."
}
Write-Host 'Build successful: build/pcm_lab.exe'
