default:
	$(CC) main.c properties.c segmentation.c normalization.c -I../include -L../target/debug -lseshat -o test

run:
	LD_LIBRARY_PATH=../target/debug ./test
