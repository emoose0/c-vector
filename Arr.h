#ifndef ARR_H
#define ARR_H

#define growCapacity(capacity) \
	(capacity < 8) ? 8 : capacity*2 

typedef struct{
	int count;
	int capacity;
	int* Array;
}Vect;

void initVect(Vect* vect);
Vect* constructVect(int array[], int count, int capacity);
void addVect(Vect* vect, int data);
void changeVect(int data, int index, Vect* vect);
void removeVect(Vect* vect, int count);

#endif
