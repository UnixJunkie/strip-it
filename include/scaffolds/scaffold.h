/**********************************************************************
scaffold.h - strip-it
 
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



#ifndef __SCAFFOLD_H__
#define __SCAFFOLD_H__



#include <string>
#include <map>
#include <list>
#include <set>
#include <algorithm>

#include <openbabel/mol.h>
#include <options.h>



class Scaffold
{
   	protected:
   
      	std::string _name;
      	std::string _smiles;
		OpenBabel::OBConversion _mol2can;
    
    	virtual bool IsEndStanding(OpenBabel::OBAtom*, bool, bool);
      
   	public:
   
      	Scaffold(void);
      	virtual ~Scaffold(void);
      	Scaffold(const Scaffold&);
      	Scaffold& operator=(const Scaffold&);
   
      	virtual bool CalculateScaffold(const OpenBabel::OBMol&, Options*) = 0;
      	virtual std::string PrintName(void);
      	virtual std::string PrintScaffold(void);
};



#endif
