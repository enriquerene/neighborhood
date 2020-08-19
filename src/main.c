#include <stdio.h>
#include "./point.h"
#include "./reader.h"

#define NBHD_SIZE 6

size_t noPtsInCollection ( size_t number_of_pts, size_t nbhdSize )
{
	return number_of_pts * ( 1 + nbhdSize );
}

int main( int argc, char* argv[] )
{
	char *filename = cliHandler( argc, argv );
	char *number_in_char;
	FILE *fd = fopen( filename, "r" );

	int number_of_pts = getNumberOfPoints( fd );
	Point points[ number_of_pts ];
	Point interior[ noPtsInCollection( number_of_pts, NBHD_SIZE ) ];
	getPoints( fd, number_of_pts, points );

	number_of_pts = getNumberOfPoints( fd );
	Point shadow[ number_of_pts ];
	Point boundary[ noPtsInCollection( number_of_pts, NBHD_SIZE ) ];
	getPoints( fd, number_of_pts, shadow );

	return EXIT_SUCCESS;
}
