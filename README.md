# Interruprion C example code for Cortex-M0 
Minimal "*framework*" providing startup code and Makefile for building a bare-metal C program for Cortex-M0. This should be used alongside the Cortex-M0 softcore implementation available on https://github.com/vfinotti/cortex-m0-soft-microcontroller.

# Required software
This "*framework*" requires following components:
- ARM GCC compiler (install `arm-none-eabi-gcc`)

# Configuration
You have to set to rename Makefile.in to Makefile and set two paths in it: `TOOLCHAIN_PATH` and `JLINK_PATH`.

# Usage
Command "make" is all you need, you can do everything with it.

`make` - build project (in ELF, BIN and IHEX formats)

`make clean` - clean files


# References

1. https://github.com/goofacz/cortex-m-minimal-c
