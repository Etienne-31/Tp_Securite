#include <stdio.h>

#include "cache.h"

#define RUNS  10000
#define LIMIT 500

int main(int ac, char **av) {
	
	uint32_t cache_hit_cycles [RUNS];
	uint32_t cache_miss_cycles[RUNS];
	uint32_t cache_hit_histogram [LIMIT];   
	uint32_t cache_miss_histogram[LIMIT];
	
	memset(cache_hit_histogram ,0,LIMIT*sizeof(uint32_t));
	memset(cache_miss_histogram,0,LIMIT*sizeof(uint32_t));
	
		
	void* ptr = map_offset("profiling.c",0);
	uint64_t nb_cycle;
	
	uint64_t result;
	int nbHit;
	
	// Cache hit cycles profiling //
	/** (Question 1) **/ 
	for(int i = 0;i < RUNS;i++){
		cache_hit_cycles[i] = memaccesstime(ptr);
	}  
	
	
	// Cache miss cycles profiling //
	/** (Question 1) **/  
	for(int i = 0;i < RUNS;i++){
		clflush(ptr);
		cache_miss_cycles[i] = memaccesstime(ptr);
	}  
	
	
	
	// Compute histogram //
	/** (Question 2) **/
	// On rempli le premier histograme//
	nbHit = 0;
	for(int limit = 0;limit<LIMIT;limit++){
		for(int i =0;i<RUNS;i++){
			if(limit == cache_hit_cycles[i]){
				nbHit++;
			}
		}
		cache_hit_histogram [limit] = nbHit;
		nbHit = 0;
	}

	
	for(int limit = 0;limit<LIMIT;limit++){
		for(int i =0;i<RUNS;i++){
			if(limit == cache_miss_cycles[i]){
				nbHit++;
			}
		}
		cache_miss_histogram [limit] = nbHit;
		nbHit = 0;
	}
	
	
	
	
	
	// Export to csv file // 
	
	FILE* fcache_profiling = fopen("cache_profiling.csv","w");
	fprintf(fcache_profiling,"index;cache hit;cache miss\n");
	
	for(size_t i = 0; i < LIMIT;++i) fprintf(fcache_profiling,"%d;%d;%d;\n",
						  i,
						  cache_hit_histogram[i],
						  cache_miss_histogram[i]);
	
	fclose(fcache_profiling);
	
	return 0;
}
