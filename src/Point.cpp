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
del::Point::Point ( float x, float y, float z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}

del::Point::~Point(){};

std::string del::Point::to_string( void )
{
	std::string str = "(";
	str += std::to_string( this->x );
	str += ",";
	str += std::to_string( this->y );
	str += ",";
	str += std::to_string( this->z );
	str += ")";
    return str;
}

float del::Point::distancia ( del::Point P )
{
	return sqrt( pow( this->x - P.x, 2 ) + pow( this->y - P.y, 2 ) + pow( this->z - P.z, 2 ) );
}

float del::Point::distancia ( del::Point P1, del::Point P2 )
{
	return sqrt( pow( P1.x - P2.x, 2 ) + pow( P1.y - P2.y, 2 ) + pow( P1.z - P2.z, 2 ) );
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
	float x = this->x + P.x;
	float y = this->y + P.y;
	float z = this->z + P.z;

	return Point( x, y, z );
}

del::Point del::Point::operator - ( del::Point P )
{
	float x = this->x - P.x;
	float y = this->y - P.y;
	float z = this->z - P.z;

	return Point( x, y, z );
}

bool del::Point::operator == (del::Point P)
{
	return ( this->x == P.x && this->y == P.y && this->z == P.z );
}

#endif
