/**********************************************************************
counter.cpp - strip-it
 
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



#include <counter.h>



Counter::Counter(void):
_totalMol(0),
_scaffolds(0),
_noScaffolds(0)
{
}



Counter::~Counter(void)
{
}



Counter::Counter(const Counter& f):
_totalMol(f._totalMol),
_scaffolds(f._scaffolds),
_noScaffolds(f._noScaffolds)
{
}



Counter&
Counter::operator=(const Counter& f)
{
   	_totalMol = f._totalMol;
   	_scaffolds = f._scaffolds;
   	_noScaffolds = f._noScaffolds;
   	return *this;
}



void
Counter::NewMolecule(void)
{
   	++_totalMol;
}



void
Counter::NewScaffold(void)
{
   	++_scaffolds;
}



void
Counter::FailedScaffold(void)
{
   	++_noScaffolds;
}



std::string
Counter::Results(void) const
{
   	std::ostringstream os;
   	os << "-> Molecules processed: " << _totalMol << std::endl;
   	os << "-> Scaffolds generated: " << _scaffolds << std::endl;
   	os << "-> Scaffolds failed:    " << _noScaffolds << std::endl;
   	return os.str();
}

