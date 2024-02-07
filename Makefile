CC = gcc               # Compiler
AR = ar                # Archiver
CFLAGS = -Wall -g      # Compiler flags for warnings and debugging information
AFLAGS = rcs           # Archiver flags for creating a static library

.PHONY: all clean

# Default target: Build the executable 'connections'
all: connections

# Target to build the executable 'connections'
connections: my_graph.o libmymath.a
	$(CC) $(CFLAGS) $^ -o $@

# Target to create the static library 'libmymath.a'
libmymath.a: my_mat.o
	$(AR) $(AFLAGS) $@ $<

# Target to compile 'my_graph.c' into 'my_graph.o'
my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) -c $<

# Target to compile 'my_mat.c' into 'my_mat.o'
my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c $<

# Target to clean up generated files
clean:
	rm -f *.o *.a connections

