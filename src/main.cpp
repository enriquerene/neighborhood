#include <stdio.h>
#include <math.h>
#include <string>
#include <unistd.h>
#include <iostream>
#include <functional>
#include <time.h>
#include <array>
#include <fstream>
#include <bits/stdc++.h>
#include "Point.cpp"
#include "Set.hpp"

#define NEIGHBORHOOD_MAX_SIZE 6

long timeBetween( long before, long after ) {
	return ( after - before ) * 1000 / CLOCKS_PER_SEC;
}

void appendToFile ( std::string fileName, std::string line )
{
	std::ofstream fout;
	std::ifstream fin;
	fin.open( fileName );
	fout.open( fileName, std::ios::app );
	if ( fin.is_open() ) {
		fout << line << std::endl;
	}
	fin.close();
	fout.close();
}

char* cliHandler ( int argc, char* argv[] )
{
	char* filename; // char* instead string because of fopen use bellow
	if ( argc == 1 )
	{
		// Se nenhum parametro é inserido na execução, pede arquivo ao usuário.
		std::cout << "Digite o nome do arquivo a ser triangulado." << std::endl;
		std::cin >> filename;
	}
	else if ( argc == 2 )
	{
		// Utilizando arquivo inserido via linha de comando.
		filename = argv[ 1 ];
	}
	else
	{
		std::cout << "Muitos argumentos inseridos." << std::endl;
		std::cout << "Conversor STL aceita apenas um parâmetro opcional." << std::endl;
		std::cout << "	Utilização:" << std::endl;
		std::cout << "		conversort-stl [<nome do arquivo>]" << std::endl;
		exit( EXIT_FAILURE );
	}
	return filename;
}

int main( int argc, char* argv[] )
{
	time_t t[ 2 ];
	int listSize;
	FILE* file;
	char* filename;
	try
	{
		filename = cliHandler( argc, argv );
		file = fopen( filename, "r" );
		if ( file == NULL  ) {
			std::cout << "Arquivo não pode ser aberto: Não existe ou está sendo editado por outro programa." << std::endl;
			std::cout << "Conversor STL encerra sua execução retornando erro 1." << std::endl;
			exit( EXIT_FAILURE );
		}
		std::cout << "Nome do arquivo inserido:" << filename << std::endl;
		std::cout << std::endl;
		std::ifstream inFile( filename );
		listSize = std::count(std::istreambuf_iterator<char>(inFile), std::istreambuf_iterator<char>(), '\n');
		std::cout << "Total de linhas no arquivo: " << listSize << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	del::Point points[ listSize ];
	del::Point pointsCopy[ listSize ];
	
	{
		del::coordinate x, y, z;
		t[ 0 ] = clock();
		int i = 0;
		while ( fscanf( file, "%E%E%E \n", &x, &y, &z ) != EOF )
		{
			del::Point p ( x, y, z );
			points[ i ] = p;
			pointsCopy[ i ] = p;
			i++;
		}
		t[ 1 ] = clock();
	}
	fclose( file );

	del::Point neighbhd[ NEIGHBORHOOD_MAX_SIZE ];
	del::Set<del::Point> set ( listSize, points );
	del::Set<del::Point> subset ( NEIGHBORHOOD_MAX_SIZE );
	del::Point p;

	ftruncate( fileno( file ), 0 );
	for ( size_t i = 0; i < listSize; i++ )
	{
		p = set.points[ i ];
		set.orderByDistance( p );
		set.subSetFromTop( subset );
		appendToFile( filename, subset.to_string() );
	}

	return EXIT_SUCCESS;
}
