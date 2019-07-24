/**
* @file Tortoise.cpp
* @author Melanie Roy-Plommer
* @version 1.0
*
*
* @section DESCRIPTION
* < Tortoise and Hare race game using Inheritance and Polymorphism >
*
*
* @section LICENSE
*
*
* Copyright 2018
* Permission to use, copy, modify, and/or distribute this software for
* any purpose with or without fee is hereby granted, provided that the
* above copyright notice and this permission notice appear in all copies.
*
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
* ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
* ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
* @section Academic Integrity
* I certify that this work is solely my own and complies with
* NBCC Academic Integrity Policy (policy 1111)
**/

#include "Tortoise.h"
#include <iostream>

static int _tortNumber = 0;

Tortoise::Tortoise() : Racer()
{
	_type = "tortoise";
	_tortNumber++;
	_name = "T" + std::to_string(_tortNumber);
	//std::cout << "Tortoise constructor" << std::endl;
}

Tortoise::~Tortoise()
{
	//std::cout << "Tortoise destructor" << std::endl;
}

void Tortoise::move(int rand)
{
	int caseNum = rand % 10 + 1;
	switch (caseNum) 
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5: _position += 3; break; //fast plod - 1 through 5 (50%)
	case 6:
	case 7: _position -= 6; break; //slip - 6 and 7 (20%)
	case 8:
	case 9:
	case 10: _position += 1; break; //slow plod - 8 through 10 (30%)
	}
	if (_position < 1)
	{
		_position = 1;
	}
	else if (_position > 70)
	{
		_position = 70;
	}
}




