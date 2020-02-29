// example.cpp

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#include "CloseLater.h"

bool uncertainFunction(void) {
	srand(time(0));
	return rand() > (RAND_MAX / 2);
}

void free_func(void* ptr) {
	printf("freeing memory from free_func\n");
	free(ptr);
}

int main() {
	// Allocate an array that will need to be free'd later.
	char* array = (char*)malloc(256);
	// We use "free_func" to deallocate the memory for the purposes of this
	// example because it allows us to see that the memory was freed.
	// "free" could just as well be used.
	CloseLater<free_func> cl(array);
	if (uncertainFunction()) {
		printf("exiting from conditional\n");
		return 1;
	}
	printf("exiting normally\n");
	return 0;
}
