#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

typedef float distance;
typedef struct
{
	int x,
		y,
		z;
} Point;

#define MAX_STR_SIZE 20

char *readLine ( FILE *file_ptr )
{
	char *line;
	size_t length = 0;
	if ( getline( &line, &length, file_ptr ) == -1 )
		line = "";
	return line;
}

int getNumberOfPoints ( FILE *file_ptr )
{
	char *number_in_char;
	//lendo número de pontos da carta:
	number_in_char = readLine( file_ptr );
	return atoi( number_in_char );
}

Point getAPoint ( FILE *file_ptr )
{
	float x, y, z;
	sscanf( readLine( file_ptr ) , "%f , %f , %f \n", &x, &y, &z);
	Point p = { x, y, z };
	return p;
}

void *getPoints ( FILE *file_ptr, int number_of_pts, Point *points )
{
	for ( int i = 0; i < number_of_pts; i++ )
	{
		points[ i ] = getAPoint( file_ptr );
	}
	//return points;
}

//void appendToFile ( char *fileName, char *line )
//{
//	std::ofstream fout;
//	std::ifstream fin;
//	fin.open( fileName );
//	fout.open( fileName, std::ios::app );
//	if ( fin.is_open() ) {
//		fout << line << std::endl;
//	}
//	fin.close();
//	fout.close();
//}

distance Distance ( Point P1, Point P2 )
{
	distance Dx = pow( P1.x - P2.x, 2 );
	distance Dy = pow( P1.y - P2.y, 2 );
	distance Dz = pow( P1.z - P2.z, 2 );
	return sqrt( Dx + Dy + Dz );
}

char* cliHandler ( int argc, char* argv[] )
{
	char* filename; // char* instead string because of fopen use bellow
	if ( argc != 2 )
	{
		printf( "Neighborhood aceita apenas um parâmetro obrigatório.\n" );
		printf( "	Utilização:\n" );
		printf( "		nbhd <nome do arquivo>\n" );
		exit( EXIT_FAILURE );
	}
	filename = argv[ 1 ];
	return filename;
}

int main( int argc, char* argv[] )
{
	char *filename = cliHandler( argc, argv );
	char *number_in_char;
	FILE *fd = fopen( filename, "r" );

	int number_of_pts = getNumberOfPoints( fd );
	Point points[ number_of_pts ];
	getPoints( fd, number_of_pts, points );

	number_of_pts = getNumberOfPoints( fd );
	Point shadow[ number_of_pts ];
	getPoints( fd, number_of_pts, shadow );

	return EXIT_SUCCESS;
}
