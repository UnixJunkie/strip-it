/**********************************************************************
murcko_2.cpp - strip-it
 
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



#include <scaffolds/murcko_2.h>



Murcko_2::Murcko_2(void):
Scaffold()
{
	_name = "MURCKO_2";
}



Murcko_2::~Murcko_2(void)
{
}



Murcko_2::Murcko_2(const Murcko_2& s)
{
	_name = s._name;
	_smiles = s._smiles;
}



Murcko_2&
Murcko_2::operator=(const Murcko_2& s)
{
	if (this != &s)
	{
		_name = s._name;
		_smiles = s._smiles;
	}
	return *this;
}



bool
Murcko_2::CalculateScaffold(const OpenBabel::OBMol& mol, Options* o)
{
	OpenBabel::OBMol m(mol);
	OpenBabel::OBAtom* atom;
	OpenBabel::OBAtom* nbrAtom[2];
	OpenBabel::OBBondIterator bi;
	std::vector<OpenBabel::OBAtom*>::iterator avi;
	OpenBabel::OBBond* bond;
	std::vector<OpenBabel::OBBond*>::iterator bvi;
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

	// Make all atoms as neutral C and all bond orders equal to 1
	m.BeginModify();
	for (atom = m.BeginAtom(avi); atom; atom = m.NextAtom(avi))
	{
		atom->SetAtomicNum(6);
		atom->SetFormalCharge(0);
	}
   	for (bond = m.BeginBond(bvi); bond; bond = m.NextBond(bvi))
	{
		bond->SetBondOrder(1);
	}
 	m.EndModify();
   
   	// Condense all linkers to a single chain
	removed = true;
  	while (removed)
   	{
		removed = false;
      	for (atom = m.BeginAtom(avi); atom; atom = m.NextAtom(avi))
      	{
         	if (!atom->IsInRing() && (atom->GetValence() == 2))
         	{
	         	nbrAtom[0] = atom->BeginNbrAtom(bi);
	         	nbrAtom[1] = atom->NextNbrAtom(bi);
				if (nbrAtom[0] && nbrAtom[1])
				{
			      	m.BeginModify();
	         		m.AddBond(nbrAtom[0]->GetIdx(), nbrAtom[1]->GetIdx(), 1);
	         		m.DeleteAtom(atom);
			      	m.EndModify();
					removed = true;
					break;
				}
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
