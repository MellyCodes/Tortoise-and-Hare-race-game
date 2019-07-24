/**
* @file Racer.h
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

#pragma once
#include <string>
class Racer
{
public:
	Racer();
	virtual ~Racer();

	//name
	std::string getName()const;
	void setName(std::string name);

	//position
	virtual void move(int rand) = 0;
	int getPosition()const;
	void resetPosition();

	//wins
	void incrementWins();
	int getWins();

	//type
	std::string getType()const;
	void setType(std::string type);

protected:
	int _position{ 0 };
	std::string _type = "racer";
	std::string _name = "";

private:
	int _wins{ 0 };
};

