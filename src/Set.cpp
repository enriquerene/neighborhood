#ifndef DEL_SET_C
#define DEL_SET_C

#include <math.h>
#include "./Set.hpp"
/****************************************************************************/
/*																			*/
/*								  METHODS									*/
/*																			*/
/****************************************************************************/
template <typename T>
del::Set<T>::Set ( int size )
{
	this->size = size;
	del::Point points[ size ];
	this->points = points;
	for ( int i = 0; i < size; i++ )
	{
		this->points[ i ] = del::Point();
	}
}

template <typename T>
del::Set<T>::Set ( int size, T* points )
{
	this->size = size;
	del::Point _points[ size ];
	this->points = _points;
	this->copyList( points, size );
}

template <typename T>
void del::Set<T>::copyList ( T* points, size_t size )
{
	for ( size_t i = 0; i < size; i++ )
	{
		this->points[ i ] = points[ i ];
	}
}

template <typename T>
std::string del::Set<T>::to_string( void )
{
	std::string str = "";
	for ( size_t i = 0; i < this->size; i++ )
	{
		str += this->points[ i ].to_string() + "\n";
	}
	
	return str;
}


template <typename T>
void del::Set<T>::exchangeListPositions ( T* pos1, T* pos2 )
{
	T tmp = *( pos1 );
	*( pos1 ) = *( pos2 );
	*( pos2 ) = tmp;
}

template <typename T>

template <typename T>
void del::Set<T>::subSetFromTop ( del::Set<T> subset )
{
	for ( size_t i = 0; i < subset.size; i++ )
	{
		// *( subset.points + i ) = *( this->points + i );
		subset.points[ i ] = this->points[ i ];
	}
}

#endif
