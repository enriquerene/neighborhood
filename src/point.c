#include <math.h>

bool arePtsEqual = ( Point P1, Point P2 )
{
	return P1.x == P2.x && P1.y == P2.y && P1.z == P2.z;
}

Point sumPts ( Point P1, Point P2 )
{
	float x = P1.x + P.x;
	float y = P1.y + P.y;
	float z = P1.z + P.z;

	return Point( x, y, z );
}

Point simmetricPnt ( Point P )
{
	float x = 0.0f - P.x;
	float y = 0.0f - P.y;
	float z = 0.0f - P.z;

	return Point( x, y, z );
}

// return -1.0 if Distance is negative (meaning error!)
distance Distance ( Point P1, Point P2 )
{
	distance Dx = pow( P1.x - P2.x, 2 );
	distance Dy = pow( P1.y - P2.y, 2 );
	distance Dz = pow( P1.z - P2.z, 2 );
	distance D = sqrt( Dx + Dy + Dz );
	if ( D < 0 )
		return -1.0;
	return D;
}

void exchangeListPositions ( Point *pts, i, j )
{
	Point a = pts[ i ];
	pts[ i ] = pts[ j ];
	pts[ j ] = a;
}

void orderByDistance ( Point centralPnt, Point *pts )
{
	for ( size_t i = 0; i < this->size; i++ )
	{
		for ( size_t j = i; j > 0; j-- )
		{
			Point Pj = pts[ j ], Pj_1 = pts[ j - 1 ];
			distance Dj = Distance( centralPnt, Pj );
			distance Dj_1 = Distance( centralPnt, Pj_1 );
			if ( Dj != -1.0 && Dj_1 != -1.0 )
			{
				if ( Dj < Dj_1 )
					exchangeListPositions( pts, j, j - 1 );
			}
		}
		
	}
}
