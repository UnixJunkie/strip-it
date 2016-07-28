/**********************************************************************
rings_with_linkers_1.cpp - strip-it
 
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



#include <scaffolds/rings_with_linkers_1.h>



Rings_With_Linkers_1::Rings_With_Linkers_1(void):
Scaffold()
{
	_name = "RINGS_WITH_LINKERS_1";
}



Rings_With_Linkers_1::~Rings_With_Linkers_1(void)
{
}



Rings_With_Linkers_1::Rings_With_Linkers_1(const Rings_With_Linkers_1& s)
{
	_name = s._name;
	_smiles = s._smiles;
}



Rings_With_Linkers_1&
Rings_With_Linkers_1::operator=(const Rings_With_Linkers_1& s)
{
   	if (this != &s)
   	{
      	_name = s._name;
     	_smiles = s._smiles;
   	}
   	return *this;
}



bool
Rings_With_Linkers_1::CalculateScaffold(const OpenBabel::OBMol& mol, Options* o)
{
   	OpenBabel::OBMol m(mol);
   	OpenBabel::OBAtom* atom;
   	std::vector<OpenBabel::OBAtom*>::iterator avi;
   	bool removed(true);
   	while (removed)
   	{
      	removed = false;
      	for (atom = m.BeginAtom(avi); atom; atom = m.NextAtom(avi))
      	{
         	if (IsEndStanding(atom, false, false))
         	{
            	m.DeleteAtom(atom);
            	removed = true;
				break;
         	}
      	}
	}
  
   	if (!m.Empty())
	{
		_smiles = _mol2can.WriteString(&m, true);
	}
   	else
   	{
      	_smiles = "-";
      	return false;
   	}
  	return true;
}
