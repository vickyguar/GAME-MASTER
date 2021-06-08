///////////////////////////////////////////////////////////
//  cGuerrero.cpp
//  Implementation of the Class cGuerrero
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cGuerrero.h"

cGuerrero::cGuerrero(unsigned int _AT, unsigned int _HP_Actual, unsigned int _HP_Inicial)
{
	AT = _AT;
	HP_Actual = _HP_Actual;
	HP_Inicial = _HP_Inicial;
}

cGuerrero::~cGuerrero(){

}

unsigned int cGuerrero::getAT() const
{
	return AT;
}
