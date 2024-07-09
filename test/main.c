#include <stdlib.h>
#include <assert.h>
void *malloc(size_t size);

int main() {
	void *ptr = malloc(42);
	assert(ptr == NULL);
	return 0;
}
