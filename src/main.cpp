<<<<<<< HEAD
#include <cstddef>
#include <sys/stat.h>
#include <sys/types.h>
=======
>>>>>>> refatoracao/triangle_building
#include <stdio.h>
#include <math.h>
#include <string>
#include <unistd.h>
#include <iostream>
#include <functional>
#include <time.h>
#include <array>
<<<<<<< HEAD
#include <vector>
=======
>>>>>>> refatoracao/triangle_building
#include <fstream>
#include <bits/stdc++.h>
#include "Point.cpp"
#include "Point.hpp"
#include "Set.hpp"
<<<<<<< HEAD
#include "Vizinhanca.cpp"
#include "Centro_Esfera_Aprox.cpp"
#include "triangle_building.cpp"
#include "Triangle.cpp"
#include "convex_hull.cpp"
#include "stl_module.cpp"
#include "find_z_max.cpp"

#define NEIGHBOORHOOD_MAX_SIZE 6
=======
>>>>>>> refatoracao/triangle_building

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

	/*
	
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
<<<<<<< HEAD
		for ( size_t j = 0; j < listSize; j++ )
		{
			set.orderByDistance( del::Point (0,0,8) );
		}
	}


	std::cout << set.to_string() << std::endl;

	std::cout << std::endl;
	std::cout << std::endl << "Operação de leitura do arquivo realizada em " << timeBetween( t[ 0 ], t[ 1 ] ) << " ms" << std::endl << std::endl;



	float delta_z = 1.5;
	std::cout << "Parâmetro de resolução de leitura: " << delta_z << std::endl;
	// obter_catalogo_de_vizinhancas de points inicia aqui
	// primeiro instancio a classe inserindo os points
	del::Vizinhanca vizinhanca( points , 7);
	del::Triangle_Building triangle_Builder;
	// ativo ou desativo o debug (para leitura no console)
	vizinhanca.ativar_debug();
	//vizinhanca.desativar_debug();

	// defino o raio da vizinhança
	float radius =  1.5 * delta_z;
	vizinhanca.definir_raio( radius );

	// t[0] armazena a posição do tempo antes do processo de "catalogação"
	t[ 0 ] = clock();
	// processo de catalogação
	std::vector<std::vector<del::Point>> neighboorhoodsBook = vizinhanca.obter_catalogo_de_vizinhancas();
	triangle_Builder.Recebe_Catalogo(neighboorhoodsBook);
	// t[1] armazena o tempo final do processo
	t[ 1 ] = clock();
	appendToFile( "timer.log", std::to_string( currentLine ) + " " + std::to_string( timeBetween( t[ 0 ], t[ 1 ] ) ) + " " + std::to_string( delta_z ) );
	std::cout << std::endl << "Operação de catalogação das vizinhanças realizada em " << timeBetween( t[ 0 ], t[ 1 ] ) << " ms" << std::endl << std::endl;

	delete[] points;



	Todo este bloco inicial deve ser repensado com base no formato de saída do NBHBB
	
	*/


	//Inicia triangulação

	std::cout << "Iniciando triangulação." << std::endl;
	std::vector< del::Stl_module> Triangulation_with_normals; //Armazena todos os triângulos de Delaunay e suas respectivas normais
	std::cout << "Vetor de armazenamento dos módulos stl criado com sucesso." << '\n';
	del::Triangle_Building Triangle_Building_obj;
	std::cout << "Instância da classe Triangle_Building criada com sucesso." << '\n';



	//*******************************************************************************
	//del::Find_Extremal_Points find_extremal_points_obj;
	//std::cout << "Instância da classe Find_Extremal_Points criada com sucesso." << '\n';
	//del::Point A = find_extremal_points_obj.Find_Z_Max(points);; //ponto mais alto do sólido (maior z)
	//std::cout << "Ponto mais alto do sólido localizado com sucesso:" << '\n';
	//std::cout << "X=" << A.x<<'\n';
	//std::cout << "Y=" << A.y<<'\n';
	//std::cout << "Z=" << A.z<<'\n';
	//
	// Necessário repensar este bloco baseado no formato da saída do construtor de vizinhanças: 
	// cada par (carta + shadow) deve dar origem a uma coleção de vizinhanças (NBHB)
	//
	//*******************************************************************************
	

	del::Point A;
	del::Triangle T_0 = Triangle_Building_obj.Point_based_Triangle_Building(A);
	std::cout << "Primeiro triângulo da triangulação determinado com sucesso:" << '\n';
	std::cout << "Ponto A:" << "X="<<T_0.A.x<<"Y="<<T_0.A.y<<"Z="<<T_0.A.z<<'\n';
	std::cout << "Ponto B:" << "X="<<T_0.B.x<<"Y="<<T_0.B.y<<"Z="<<T_0.B.z<<'\n';
	std::cout << "Ponto C:" << "X="<<T_0.C.x<<"Y="<<T_0.C.y<<"Z="<<T_0.C.z<<'\n'; 

	del::Point first_Normal = T_0.Normal();
	std::cout << "Normal ao Primeiro triângulo determinada com sucesso:" << '\n';
	std::cout << "Normal:" << "X="<<first_Normal.x<<"Y="<<first_Normal.y<<"Z="<<first_Normal.z<< '\n';

	//orientando corretamente para cima a normal do primeiro triangulo:
	if (first_Normal.z<0)
	{
		T_0.swap();
	}
	std::cout << "Pontos do primeiro triângulo após aplicação do Swap:" << '\n';
	std::cout << "Ponto A:" << "X="<<T_0.A.x<<"Y="<<T_0.A.y<<"Z="<<T_0.A.z<<'\n';
	std::cout << "Ponto B:" << "X="<<T_0.B.x<<"Y="<<T_0.B.y<<"Z="<<T_0.B.z<<'\n';
	std::cout << "Ponto C:" << "X="<<T_0.C.x<<"Y="<<T_0.C.y<<"Z="<<T_0.C.z<<'\n';
	first_Normal = T_0.Normal();
	std::cout << "Normal ao Primeiro triângulo após aplicação do Swap:" << '\n';
	std::cout << "Normal:" << "X="<<first_Normal.x<<"Y="<<first_Normal.y<<"Z="<<first_Normal.z<< '\n';

	del::Stl_module Module_0;
	Module_0.Normal = T_0.Normal();
	Module_0.Triangle = T_0;
	std::cout << "Primeiro módulo Stl determinado com sucesso." << '\n';

	//guardando primeiro módulo do arquivo stl:
	Triangulation_with_normals.push_back(Module_0);
	std::cout << "Primeiro módulo Stl guardado em triangulation with normals com sucesso:" << '\n';


	std::cout << "Primeiro triângulo:" << '\n';
	std::cout << "Ponto A:" << "X="<<Triangulation_with_normals[0].Triangle.A.x<<"Y="<<Triangulation_with_normals[0].Triangle.A.y<<"Z="<<Triangulation_with_normals[0].Triangle.A.z<<'\n';
	std::cout << "Ponto B:" << "X="<<Triangulation_with_normals[0].Triangle.B.x<<"Y="<<Triangulation_with_normals[0].Triangle.B.y<<"Z="<<Triangulation_with_normals[0].Triangle.B.z<<'\n';
	std::cout << "Ponto C:" << "X="<<Triangulation_with_normals[0].Triangle.B.x<<"Y="<<Triangulation_with_normals[0].Triangle.B.y<<"Z="<<Triangulation_with_normals[0].Triangle.B.z<<'\n';
	std::cout << "Normal:" << '\n';
	std::cout << "Normal:" << "X="<<Module_0.Normal.x<<"Y="<<Module_0.Normal.y<<"Z="<<Module_0.Normal.z<< '\n';

	//inicia Convex_Hull
	del::Convex_Hull Convex_Hull_obj;
	std::cout << "Instância da classe Convex Hull criada com sucesso." << '\n';

	//constrói primeiros edges a partir do T_0 e os armazena no Convex_Hull_obj
	del::Edge AB;
	AB.first_Point = Module_0.Triangle.A;
	AB.second_Point = Module_0.Triangle.B;
	Convex_Hull_obj.edge_collection.push_back(AB);

	del::Edge BC;
	BC.first_Point = Module_0.Triangle.B;
	BC.second_Point = Module_0.Triangle.C;
	Convex_Hull_obj.edge_collection.push_back(BC);

	del::Edge CA;
	CA.first_Point = Module_0.Triangle.C;
	CA.second_Point = Module_0.Triangle.A;
	Convex_Hull_obj.edge_collection.push_back(CA);
	std::cout << "Primeiras 3 arestas criadas e adicionadas ao Convex Hull com sucesso:" << '\n';
	std::cout << "Aresta AB:" << '\n';
	std::cout << "Primeiro Ponto:" << "X="<<AB.first_Point.x<<"Y="<<AB.first_Point.y<<"Z="<<AB.first_Point.z<< '\n';
	std::cout << "Primeiro Ponto:" << "X="<<AB.second_Point.x<<"Y="<<AB.second_Point.y<<"Z="<<AB.second_Point.z<< '\n';

	std::cout << "Aresta BC:" << '\n';
	std::cout << "Primeiro Ponto:" << "X="<<BC.first_Point.x<<"Y="<<BC.first_Point.y<<"Z="<<BC.first_Point.z<< '\n';
	std::cout << "Primeiro Ponto:" << "X="<<BC.second_Point.x<<"Y="<<BC.second_Point.y<<"Z="<<BC.second_Point.z<< '\n';

	std::cout << "Aresta CA:" << '\n';
	std::cout << "Primeiro Ponto:" << "X="<<CA.first_Point.x<<"Y="<<CA.first_Point.y<<"Z="<<CA.first_Point.z<< '\n';
	std::cout << "Primeiro Ponto:" << "X="<<CA.second_Point.x<<"Y="<<CA.second_Point.y<<"Z="<<CA.second_Point.z<< '\n';


	if (Convex_Hull_obj.reliability())
	{
		std::cout << "Convex Hull iniciado com sucesso." << '\n';
	}
	else
	{
		std::cout << "Convex Hull iniciado com erro no primeiro triângulo." << '\n';
		exit( EXIT_FAILURE );
	}

	del::Stl_module New_Module;
	del::Triangle_Building Build;
	del::Triangle New_Triangle;
	bool not_found;
	del::Edge New_Edge_Unique;
	del::Edge New_Edge_1;
	del::Edge New_Edge_2;

	del::Point Origem;

	size_t J =0;
	// while Convex_Hull still have 'bool really_a_Convex_Hull_member = false' edges
	while (J < Convex_Hull_obj.edge_collection.size() )
	{
		// varre Convex_Hull testando really_a_Convex_Hull_member para cada edge
		del::Edge working_edge = Convex_Hull_obj.edge_collection[J];
		New_Triangle = Build.Edge_based_Triangle_Building (working_edge, T_0);


		//triângulo construído trivial é retornado pela função Edge_based_Triangle_Building caso
		//não haja nenhum ponto dentro das vizinhanças dos pontos do working_edge
		if (New_Triangle.A ==  New_Triangle.B  && New_Triangle.B == New_Triangle.C)
		{
			Convex_Hull_obj.edge_collection[J].really_a_Convex_Hull_member = true;
			J++; //apenas prossegue na varredura do Convex_Hull quando a aresta working_edge não dá origem a outro triangulo
			working_edge = Convex_Hull_obj.edge_collection[J];
		}
		if (Convex_Hull_obj.edge_collection[J].really_a_Convex_Hull_member == false)
		{
			New_Triangle.same_curl(T_0);

			del::Point New_Point = New_Triangle.not_common_point_in_this_triangle_comparing_to_the_sharing_edge_triangle(T_0);

			//Shrinking phase:
			if (Convex_Hull_obj.all_points_in_convex_hull(New_Triangle, J)) 
			{
				New_Edge_Unique = Convex_Hull_obj.new_single_edge(New_Triangle, J);
				if (New_Edge_Unique.first_Point == working_edge.first_Point) 
				{
					Convex_Hull_obj.edge_collection.erase(Convex_Hull_obj.edge_collection.begin()+J);
					Convex_Hull_obj.edge_collection.erase(Convex_Hull_obj.edge_collection.begin()+J-1);
					Convex_Hull_obj.edge_collection.insert(Convex_Hull_obj.edge_collection.begin()+J - 1, New_Edge_Unique);
				}
				if (New_Edge_Unique.second_Point == working_edge.second_Point) 
				{
					Convex_Hull_obj.edge_collection.erase(Convex_Hull_obj.edge_collection.begin()+J);
					Convex_Hull_obj.edge_collection.erase(Convex_Hull_obj.edge_collection.begin()+J+1);
					Convex_Hull_obj.edge_collection.insert(Convex_Hull_obj.edge_collection.begin()+J, New_Edge_Unique);
				}
			}
			else /*Expanding phase*/
			{
				New_Edge_1.first_Point = working_edge.first_Point;
				New_Edge_1.second_Point = New_Point;
				New_Edge_2.first_Point = New_Point;
				New_Edge_2.second_Point = working_edge.second_Point;
				Convex_Hull_obj.edge_collection.erase(Convex_Hull_obj.edge_collection.begin()+J);
				Convex_Hull_obj.edge_collection.insert(Convex_Hull_obj.edge_collection.begin()+J,New_Edge_2);
				Convex_Hull_obj.edge_collection.insert(Convex_Hull_obj.edge_collection.begin()+J,New_Edge_1);
			}

			// triangulo já listado em Triangles_with_normals que possui working_edge como um de seus lados
			New_Module.Normal = New_Triangle.Normal();
			New_Module.Triangle = New_Triangle;
			not_found = true; //marcador lógico para registrar quando o triangulo encontrado já está guardado no Triangulation_with_normals

			//varre Triangulation_with_normals em busca de um módulo igual ao New_Module:
			for (size_t i = 0; i < Triangulation_with_normals.size(); i++)
			{
				if (Triangulation_with_normals[i] == New_Module)
				{
				// descarta triangulo e o modulo e sai do loop
				not_found = false;
				break;
				}
				else if ((i==Triangulation_with_normals.size() - 1) && (not_found))
				{
				Triangulation_with_normals.push_back(New_Module);
				}
			}
			working_edge = Convex_Hull_obj.edge_collection[J];
			T_0 = New_Triangle;
		}
	} //end while:
	//leia a segunda faixa de dados e adicione os points da borda superior ao conjunto
	//repita até computar todas as faixas de dados


=======
		p = set.points[ i ];
		set.orderByDistance( p );
		set.subSetFromTop( subset );
		appendToFile( filename, subset.to_string() );
	}

>>>>>>> refatoracao/triangle_building
	return EXIT_SUCCESS;
}
