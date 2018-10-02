CC=gcc-7
OUT=amd

all: clean amd

amd: amd.c
	$(CC) -o $(OUT) -fopenmp amd.c

debug: amd.c
	$(CC) -o $(OUT).debug amd.c -DDEBUG=1 -Wall

clean:
	rm -f $(OUT) $(OUT).debug

