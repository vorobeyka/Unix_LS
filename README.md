# Unix_LS

--------
_A program that simulates behavior of Mac ls \
_Developed as study assignment in the Ucode school._

## Description:
```
ls is a Unix shell command that lists directory contents of files and directories.
```

## Usage:
```
1. git clone https://github.com/vorobeyka/Unix_LS.git
2. make
3. ./uls [-ACFGORSTUacefghiklmnoprstux1@] [file ...]
```

## Flags short description:
| Builtin  | Description |
|:-:|:-:|
|**ls -a**| List all files including hidden file starting with '.' |
|**ls -i**| For each file, print the file's file serial number |
|**ls -l**| List with long format - show permissions |
|**ls -la**| List long format including hidden files |
|**ls -lh**| List long format with readable file size |
|**ls -ls**| List with long format with file size |
|**ls -r**| List in reverse order |
|**ls -R**| Recursively list subdirectories encountered |
|**ls -s**| List file size |
|**ls -S**| Sort by file size |
|**ls -t**| Sort by time & date |
|**ls -C**| Force multi-column output; this is the default when output is to a terminal |
