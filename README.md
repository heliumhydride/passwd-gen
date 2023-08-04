# passwd-gen
this program will generate passwords for you based on a character set (charset[], defined in config.h)
by selecting random characters from it, ultimately generating a random password

# Configuring and compiling
## I/ Configuring
To configure passwd-gen, edit config.h and config.mk

## II/ Compiling
### Natively
To compile natively, simply run `make`.
### Cross-compiling
To cross-compile, you can either:
 - Edit config.mk and Modify `CROSS_COMPILE`, `CC`, and `O` variables
 - Or pass these variable to `make` like this:
 ```sh
 make CROSS_COMPILE=x86_64-w64-mingw32- WIN32=1
 ```
Note: when `WIN32=1`, `make` will append `.exe` to `O`
