#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

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
