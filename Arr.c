#include "Arr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* reallocate(Vect* vect, size_t oldSize, size_t newSize){
	if(newSize == 0){
		free(vect->Array);
		return NULL;
	}
	void* result = realloc(vect->Array, newSize);
	if(result == NULL){
		printf("There is not enough memory to reallocate array. Exiting");
		exit(1);
	}
	return result;
}

void initVect(Vect* vect){	
	vect->count = 0;
	vect->capacity = 0;
	vect->Array = NULL;
}

Vect* constructVect(int array[], int count, int capacity){ //Find a way to get the count and size of an array by using a function rather than having it as a parameter
	Vect* vect = (Vect*)malloc(sizeof(Vect));
	vect->capacity = capacity;
	vect->count = count;
	vect->Array = (int*)malloc(capacity);
	memcpy(vect->Array, array, capacity);

	return vect;
}

void addVect(Vect* vect, int data){
	if(vect->capacity < (vect->count*4)+1){
		int oldCapacity = vect->capacity;
		vect->capacity = growCapacity(oldCapacity);

		vect->Array = (int*)reallocate(vect, oldCapacity, vect->capacity);
	}
	vect->Array[vect->count] = data;
	vect->count++;
}

void changeVect(int data, int index, Vect* vect){
	if(index > vect->count){
		fprintf(stderr, "ERR: element does not exist...");
		exit(-1);
	}
	vect->Array[index] = data;
}


void removeVect(Vect* vect, int count){
	vect->count -= count; //Removes amount of vectors specified in count, the data is not fully deleted but it is no longer accessible
}


