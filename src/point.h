typedef float distance;
typedef struct
{
	int x,
		y,
		z;
} Point;

bool arePtsEqual = ( Point P1, Point P2 );

Point sumPts ( Point P1, Point P2 );

Point simmetricPnt ( Point P );

distance Distance ( Point P1, Point P2 );

void exchangeListPositions ( Point *pts, i, j );

void orderByDistance ( Point centralPnt, Point *pts );

#include "./point.c"
