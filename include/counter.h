/**********************************************************************
counter.h - strip-it
 
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



#ifndef __COUNTER_H__
#define __COUNTER_H__



#include <vector>
#include <algorithm>
#include <sstream>



class Counter
{
   	protected:
   
      	unsigned int _totalMol;
      	unsigned int _scaffolds;
      	unsigned int _noScaffolds;

   	public:
   
      	Counter(void);
     	virtual ~Counter(void);
      	Counter(const Counter&);
      	Counter& operator=(const Counter&);

      	virtual void NewMolecule(void);
      	virtual void NewScaffold(void);
      	virtual void FailedScaffold(void);
      
      	virtual std::string Results(void) const;
};



#endif
