CC=gcc
ERROR_FLAGS=-Wall -pedantic-errors
DEBUG_FLAGS=-g
PERF_FLAGS=-O3
OUTPUT_FILE=-o arrange

all: debug

debug:
	$(CC) $(ERROR_FLAGS) $(DEBUG_FLAGS) $(OUTPUT_FILE) arrange.c

release:
	$(CC) $(ERROR_FLAGS) $(PERF_FLAGS) $(OUTPUT_FILE) arrange.c

clean:
	rm -rf arrange
