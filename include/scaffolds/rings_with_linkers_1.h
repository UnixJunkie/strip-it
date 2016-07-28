/**********************************************************************
rings_with_linkers_1.h - strip-it
 
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



#ifndef __RINGS_WITH_LINKERS_1_H__
#define __RINGS_WITH_LINKERS_1_H__



#include <string>
#include <vector>
#include <list>

#include <scaffolds/scaffold.h>

#include <openbabel/mol.h>
#include <openbabel/atom.h>
#include <openbabel/bond.h>
#include <openbabel/obconversion.h>



class Rings_With_Linkers_1: virtual public Scaffold
{     
   	public:
   
      	Rings_With_Linkers_1(void);
      	virtual ~Rings_With_Linkers_1(void);
      	Rings_With_Linkers_1(const Rings_With_Linkers_1&);
      	Rings_With_Linkers_1& operator=(const Rings_With_Linkers_1&);
   
      	virtual bool CalculateScaffold(const OpenBabel::OBMol&, Options*);
};



#endif
