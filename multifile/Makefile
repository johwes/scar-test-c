CC     = clang
CFLAGS = -Wall -Iinclude

SRCS = main.c src/input.c src/process.c src/output.c
OBJS = $(SRCS:.c=.o)
BIN  = record_tool

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BIN)
