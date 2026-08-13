# libwuffs - Memory-safe C library for parsing untrusted file formats

This is a `build2` package for the [`wuffs`](https://github.com/google/wuffs)
library. It provides memory-safe parsers and decoders for untrusted file
formats (images, compression, and related data).


## Usage

To start using `libwuffs` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libwuffs ^0.3.5
```

Then import the library in your `buildfile`:

```
import libs = libwuffs%lib{wuffs}
```

Include the public header with:

```
#include <wuffs/wuffs.h>
```


## Importable targets

This package provides the following importable targets:

```
lib{wuffs}
```

The compiled C library. The default build is C. Set
`config.libwuffs.cpp=true` to compile the amalgamation as C++11 and
include the `wuffs_aux` helpers (`DecodeImage`, `DecodeJson`, and
similar).
Metadata `libwuffs.cpp` reflects `config.libwuffs.cpp`.


## Configuration variables

```
[bool] config.libwuffs.cpp ?= false
```

Compile as C++ (`true`) or as C (`false`, default). The C++ build is
the same amalgamation compiled as C++11 so `wuffs_aux` is part of
`lib{wuffs}`.
