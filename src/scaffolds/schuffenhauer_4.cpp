/**********************************************************************
schuffenhauer_4.cpp - strip-it
 
Copyright 2012-2013 by Silicos-it, a division of Imacosi BVBA
 
This file is part of Strip-it.

	Strip-it is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published 
	by the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Strip-it is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with Strip-it.  If not, see <http://www.gnu.org/licenses/>.

Strip-it is linked against OpenBabel version 2.

	OpenBabel is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation version 2 of the License.

***********************************************************************/



#include <scaffolds/schuffenhauer_4.h>




Schuffenhauer_4::Schuffenhauer_4(void):
Scaffold()
{
	_name = "SCHUFFENHAUER_4";
	_ringsToBeRetained = 4;
}



Schuffenhauer_4::~Schuffenhauer_4(void)
{
}



Schuffenhauer_4::Schuffenhauer_4(const Schuffenhauer_4& s)
{
	_name = s._name;
	_smiles = s._smiles;
	_ringsToBeRetained = s._ringsToBeRetained;
}



Schuffenhauer_4&
Schuffenhauer_4::operator=(const Schuffenhauer_4& s)
{
   if (this != &s)
   {
      _name = s._name;
      _smiles = s._smiles;
      _ringsToBeRetained = s._ringsToBeRetained;
   }
   return *this;
}
