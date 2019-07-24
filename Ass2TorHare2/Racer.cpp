
/**
* @file Racer.cpp
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
#include "Racer.h"
#include <iostream>

Racer::Racer()
{
	_type = "racer";
	_name = "racer";
	_wins = 0;
	_position = 1;
	//std::cout << "Racer constructor" << std::endl;
}

Racer::~Racer()
{
	//std::cout << "Racer destructor" << std::endl;
}

std::string Racer::getName() const
{
	return _name;
}

void Racer::setName(std::string name)
{
	_name = name;
}

int Racer::getPosition()const
{
	return _position;
}

void Racer::resetPosition()
{
	_position = 1;
}

void Racer::incrementWins()
{
	_wins++;
}

int Racer::getWins()
{
	return _wins;
}

std::string Racer::getType()const
{
	return _type;
}

void Racer::setType(std::string type)
{
	_type = type;
}

