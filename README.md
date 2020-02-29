# CloseLater

When writing C++, it is always preferable to release resources in a destructor. However, sometimes it is necessary to deal with resources that are not encapsulated in an object and must be "released" or "closed" manually. For instance, if memory is allocated with malloc() it must be freed with free(). If a file is opened with fopen(), it must be closed with fclose(). Sometimes use of these functions is unavoidable in C++ when, for instance, interfacing with third-party libraries.

The `CloseLater` class is a template class which provides a way to automatically release these resources by calling a template function when the object loses scope. This frees the programmer from having to keep track of all program execution paths and manually insert calls to release the object at the end of each path.

Here is the basic paradigm illustrated with malloc() and free():

```c++
#include <stdlib.h>

#include "CloseLater.h"

int main() {
	// Allocate an array that will need to be free'd
	char* array = (char*)malloc(256);
	CloseLater<free> ci(array);
	// array will be free'd when ci loses scope, no matter how it happens
}
```

If you frequently use a specific function to close a resource, such as free(), you can create a special class.

```c++
typedef CloseLater<free> FreeLater;
```

See a more detailed example in `example.cpp`.
