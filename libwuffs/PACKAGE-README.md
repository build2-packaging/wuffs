# libwuffs - A C library

This is a `build2` package for the [`<UPSTREAM-NAME>`](https://<UPSTREAM-URL>)
C library. It provides <SUMMARY-OF-FUNCTIONALITY>.


## Usage

To start using `libwuffs` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libwuffs ^<VERSION>
```

Then import the library in your `buildfile`:

```
import libs = libwuffs%lib{<TARGET>}
```


## Importable targets

This package provides the following importable targets:

```
lib{<TARGET>}
```

<DESCRIPTION-OF-IMPORTABLE-TARGETS>


## Configuration variables

This package provides the following configuration variables:

```
[bool] config.libwuffs.<VARIABLE> ?= false
```

<DESCRIPTION-OF-CONFIG-VARIABLES>
