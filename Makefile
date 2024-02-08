CCC = gcc               # Compiler
CFLAGS = -Wall -g      # Compiler flags for warnings and debugging information

.PHONY: all clean

# Default target: Build all executables
all: my_graph my_Knapsack

# Target to build the executable 'my_graph'
my_graph: my_graph.o my_mat.o
	$(CC) $(CFLAGS) $^ -o $@

# Target to compile 'my_graph.c' into 'my_graph.o'
my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) -c $<

# Target to compile 'my_knapsack.c'
my_knapsack.o: my_knapsack.c
	$(CC) $(CFLAGS) -c $<

# Target to compile 'my_mat.c' into 'my_mat.o'
my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c $<

# Target to clean up generated files
clean:
	rm -f *.o my_graph my_Knapsack



