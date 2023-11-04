#include <stdio.h>
#include <stdlib.h>
#include "Arr.h"

int main(){
	int array[] = {1, 2, 3, 4 , 5};
	int count = sizeof(array)/sizeof(array[0]);
	int capacity = sizeof(array);
	Vect* vecto = constructVect(array, count, capacity);

	for(int i = 0; i<vecto->count; i++){ //Write elements
		printf("Count: %d    Capacity: %d    Element: %d\n", vecto->count, vecto->capacity, vecto->Array[i]);
	}
	printf("\n\n Updated after adding 2 elements\n\n");

	addVect(vecto, 7);
	addVect(vecto, 9);

	for(int i = 0; i<vecto->count; i++){ //Write elements
		printf("Count: %d    Capacity: %d    Element: %d\n", vecto->count, vecto->capacity, vecto->Array[i]);
	}

	printf("\n\n Changed element\n\n");

	changeVect(54, 0, vecto);

	for(int i = 0; i<vecto->count; i++){ //Write elements
		printf("Count: %d    Capacity: %d    Element: %d\n", vecto->count, vecto->capacity, vecto->Array[i]);
	}

	printf("\n\n Update after removing 2 elements\n\n");
	
	removeVect(vecto, 2);

	for(int i = 0; i<vecto->count; i++){
		printf("Count: %d    Capacity: %d    Element: %d\n", vecto->count, vecto->capacity, vecto->Array[i]);
	}
	
	free(vecto);

	return 0;
}
