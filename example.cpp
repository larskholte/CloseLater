// example.cpp
//
// A simple program to demonstrate the functionality of the CloseLater class.
// Run this program with and without command-line arguments to see that the
// memory is freed no matter how the program exits.

#include <stdlib.h>
#include <stdio.h>

#include "CloseLater.h"

void free_func(void* ptr) {
	printf("freeing memory from free_func\n");
	free(ptr);
}

int main(int argc, const char* argv[]) {
	// Allocate an array that will need to be free'd later.
	char* array = (char*)malloc(256);
	// We use "free_func" to deallocate the memory for the purposes of this
	// example because it allows us to see that the memory was freed.
	// "free" could just as well be used.
	CloseLater<free_func> cl(array);
	if (argc > 1) {
		printf("exiting from conditional\n");
		return 0;
	}
	printf("exiting normally\n");
	return 0;
}
