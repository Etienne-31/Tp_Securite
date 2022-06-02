#include <stdio.h>
#include "cache.h"

int main(int ac, char **av) {
	
	char * name = av[1];
	uint32_t offset = 0;
	
	// Add arguments of map_offset function //
	if(ac != 0 && ac > 2) offset = strtol(av[2],NULL,16);
	
	// Add arguments of map_offset function //
	void* ptr = map_offset( name, offset );
	void * handle = dlopen (name, RTLD_LAZY);
	
	if (!handle) {
		fprintf (stderr, "%s\n", dlerror());
		exit(1);
	}
	
	dlerror();    // Clear any existing error //
	
	void * modmult = dlsym(handle, "modmult");
	char * error;
	
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s\n", error);
		return 1;
	}
	
	if (modmult == NULL) {
		// Write your code below //
		exit(1);
	}
	
	//int offs=ptr-modmult;
	printf("ptr lib : %p\n",ptr);
	printf("ptr modmul : %p\n",modmult);
	printf("ptr offset : %x\n",offset);
	printf("ptr handle : %p\n",handle);
	
	while(1) {
		// Write your code below //
		clflush(ptr);
	}
	/*resultat : 
	sans slowdown : 15944/30638/148
	slowdown : 288958/480532/1726s
	
	*/
	return 0;
}

