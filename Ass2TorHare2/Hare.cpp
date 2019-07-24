/**
* @file Hare.cpp
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

#include "Hare.h"
#include <iostream>

static int _hareNumber;
Hare::Hare() : Racer()
{
	_type = "hare";
	_hareNumber++;
	_name = "H" + std::to_string(_hareNumber);
	//std::cout << "Hare constructor" << std::endl;
}

Hare::~Hare()
{
	//std::cout << "Hare destructor" << std::endl;
}

void Hare::move(int rand)
{
	int caseNum = rand % 10 + 1;
	switch (caseNum)
	{
	case 1:
	case 2: break; // sleep, do nothing - 1 and 2 (20%)
	case 3:
	case 4: _position += 9; break; // big hop - 3 and 4 (20%)
	case 5: _position -= 12; break; // big slip - 5 (10%)
	case 6:
	case 7:
	case 8: _position += 1; break; // small hop - 6 through 8 (30%)
	case 9:
	case 10: _position -= 2; break; // small slip - 9 and 10 (20%)
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


