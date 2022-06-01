#include <stdio.h>

#include "cache.h"


int main(int argc, char **argv) {
	uint64_t offset;
	if(argc <= 1){
		printf("Pas assez d'arguments \n");
		exit(1);
	}
	offset = 64*strtol(argv[1],NULL,10);
	// Add arguments of map_offset function //
	void* ptr = map_offset( "secret.txt", offset );
	if (ptr == NULL) {
		printf("La donnée à espionner n'est pas en mémoire \n");
		exit(1);	
	}
	
	
	while(1) {
		//Maintenant que je connais plus ou moins les valeurs en temps de cycle des cache it et cash miss , apres avoir attendu un certains temps et en reverifiant 
		// le temps d acces en cycle je peux savoir si quelqu un à acceder à la donnée
		
		
		
	}
	
	return 0;
}

