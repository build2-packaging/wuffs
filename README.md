# wuffs - Memory-safe C library for parsing untrusted file formats

This is a `build2` package repository for [`wuffs`](https://github.com/google/wuffs),
a memory-safe standard library for wrangling untrusted file formats. Wrangling
includes parsing, decoding and encoding. Example file formats include images,
audio, video, fonts and compressed archives.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`wuffs` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](libwuffs/PACKAGE-README.md) file.

The development setup for `wuffs` uses the standard `bdep`-based workflow.
For example:

```
git clone --recurse-submodules .../wuffs.git
cd wuffs

bdep init -C @gcc cc config.c=gcc
bdep update
bdep test
```
