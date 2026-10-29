# Uso:
#   make            compila todos los ejercicios en build/
#   make ejercicio07   compila solo uno
#   make clean      borra build/
# En Windows: instala make en MSYS2 con `pacman -S make`.

CC      = gcc
CFLAGS  = -Wall -Wextra -g
LDLIBS  = -lm

# Solo los .c que tienen main (seleccionDirecta.c es una función suelta)
SRCS := $(shell grep -l "main" *.c)
ifeq ($(OS),Windows_NT)
  EXE := .exe
endif
BINS := $(SRCS:%.c=build/%$(EXE))

all: $(BINS)

build/%$(EXE): %.c | build
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS)

%: build/%$(EXE) ;

build:
	mkdir -p build

clean:
	rm -rf build

.PHONY: all clean
