#ifndef DEL_Point_C
#define DEL_Point_C

#include "./Point.hpp"
#include <math.h>
#include <string>

/****************************************************************************/
/*																			*/
/*								  METHODS									*/
/*																			*/
/****************************************************************************/
del::Point::Point ( del::coordinate x, del::coordinate y, del::coordinate z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}

del::Point::~Point(){};

std::string del::Point::to_string( void )
{
	std::string str = "";
	str += std::to_string( this->x );
	str += " ";
	str += std::to_string( this->y );
	str += " ";
	str += std::to_string( this->z );
    return str;
}

del::distance del::Point::distancia ( del::Point P )
{
	del::distance Dx = pow( this->x - P.x, 2 );
	del::distance Dy = pow( this->y - P.y, 2 );
	del::distance Dz = pow( this->z - P.z, 2 );
	del::distance squareRoot = sqrt( Dx + Dy + Dz );
	// std::cout << "Dx: " << Dx << std::endl;
	// std::cout << "Dy: " << Dy << std::endl;
	// std::cout << "Dz: " << Dz << std::endl;
	// std::cout << "Dx + Dy + Dz = " << Dx + Dy + Dz << std::endl;
	// std::cout << "Distância = " << squareRoot << std::endl;
	return squareRoot;
}

del::distance del::Point::distancia ( del::Point P1, del::Point P2 )
{
	del::distance Dx = pow( P1.x - P2.x, 2 );
	del::distance Dy = pow( P1.y - P2.y, 2 );
	del::distance Dz = pow( P1.z - P2.z, 2 );
	// std::cout << "Dx: " << Dx << std::endl;
	// std::cout << "Dy: " << Dy << std::endl;
	// std::cout << "Dz: " << Dz << std::endl;
	return sqrt( Dx + Dy + Dz );
}

/****************************************************************************/
/*																			*/
/*									OPERATORS								*/
/*																			*/
/****************************************************************************/

void del::Point::operator = ( del::Point P )
{
	this->x = P.x;
	this->y = P.y;
	this->z = P.z;
}

del::Point del::Point::operator + ( del::Point P )
{
	del::coordinate x = this->x + P.x;
	del::coordinate y = this->y + P.y;
	del::coordinate z = this->z + P.z;

	return Point( x, y, z );
}

del::Point del::Point::operator - ( del::Point P )
{
	del::coordinate x = this->x - P.x;
	del::coordinate y = this->y - P.y;
	del::coordinate z = this->z - P.z;

	return Point( x, y, z );
}

bool del::Point::operator == (del::Point P)
{
	return ( this->x == P.x && this->y == P.y && this->z == P.z );
}

#endif
