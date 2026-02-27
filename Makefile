# Define the compiler
CC = gcc

# Define compiler flags
CFLAGS = -Wall

# Define target executable
TARGET = clock

# Define the list of source files
SRCS = main.c display.c

# Define the list of object files
OBJS = $(SRCS:.c=.o)

# Default rule to build the target executable
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lncurses

	# Rule to compile source files into object files
	%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

		# Clean rule to remove object files and the target executable
clean:
	rm -f *.o clock
