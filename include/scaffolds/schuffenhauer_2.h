/**********************************************************************
schuffenhauer_2.h - strip-it
 
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



#ifndef __SCHUFFENHAUER_2_H__
#define __SCHUFFENHAUER_2_H__



#include <scaffolds/schuffenhauer.h>



class Schuffenhauer_2: virtual public Schuffenhauer
{
   	public:
   
      	Schuffenhauer_2(void);
      	virtual ~Schuffenhauer_2(void);
      	Schuffenhauer_2(const Schuffenhauer_2&);
      	Schuffenhauer_2& operator=(const Schuffenhauer_2&);
};



#endif
