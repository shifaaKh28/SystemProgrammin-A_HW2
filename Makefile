CC = gcc               # Compiler
AR = ar                # Archiver
CFLAGS = -Wall -g      # Compiler flags for warnings and debugging information
AFLAGS = rcs           # Archiver flags for creating a static library

.PHONY: all clean

# Default target: Build the executable 'mains'
all: mains

# Target to build the executable 'mains'
mains: main.o libmymath.a
	$(CC) $(CFLAGS) $^ -o $@

# Target to create the static library 'libmymath.a'
libmymath.a: my_mat.o
	$(AR) $(AFLAGS) $@ $<

# Target to compile 'main.c' into 'main.o'
main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -c $<

# Target to compile 'my_mat.c' into 'my_mat.o'
my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c $<

# Target to clean up generated files
clean:
	rm -f *.o *.a mains

