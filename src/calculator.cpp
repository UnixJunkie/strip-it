/**********************************************************************
calculator.cpp - strip-it
 
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



#include <calculator.h>



Calculator::Calculator(void)
{
}



Calculator::~Calculator(void)
{
}



Calculator::Calculator(const Calculator& f)
{
}



Calculator&
Calculator::operator=(const Calculator& f)
{
   	return *this;
}



Counter
Calculator::Calculate(Options* o, const std::vector<Scaffold*>& scaffolds)
{
   	Counter counter;
   	Scaffold* s;

    if (o->GetHeader())
    {
       	// Print title line
       	if (o->OutFilename().empty())
       	{
          	std::cout << "NAME\tMOLECULE";
       	}
       	else
       	{
          	*(o->OutStream()) << "NAME\tMOLECULE";
       	}
       	for (unsigned int i(0); i < scaffolds.size(); ++i)
       	{
          	s = dynamic_cast<Scaffold*>(scaffolds[i]);
          	if (o->OutFilename().empty())
          	{
            	std::cout << "\t" << s->PrintName();
          	}
          	else
          	{
             	*(o->OutStream()) << "\t" << s->PrintName();
          	}
       	}


       	if (o->OutFilename().empty())
       	{
         	std::cout << std::endl;
       	}
       	else
       	{
          	*(o->OutStream()) << std::endl;
        }
    }

   	// Process molecules
   	OpenBabel::OBMol mol;
   	std::string title;
   	OpenBabel::OBConversion mol2can;
   	mol2can.SetOutFormat("can");
   	mol2can.AddOption("n", OpenBabel::OBConversion::OUTOPTIONS);
		
	// first set the stream (needed in case of a zip stream)
    o->InputConverter()->SetInStream(o->InputStream());
   	while (o->InputConverter()->Read(&mol))
   	{
      	// Drop stereo information
      	mol.DeleteData(OpenBabel::OBGenericDataType::StereoData);

      	// Extract a suitable title from molecule
      	counter.NewMolecule();
      	title.clear();
      	title = mol.GetTitle();
      	if (title == "")
      	{
         	mol.SetTitle(mol2can.WriteString(&mol, true).c_str());
      	}
      	if (o->OutFilename().empty())
      	{
         	std::cout << mol.GetTitle();
      	}
      	else
      	{
         	*(o->OutStream()) << mol.GetTitle();
      	}
      	
		// Print smiles
      	if (o->OutFilename().empty())
      	{
         	std::cout << "\t" << mol2can.WriteString(&mol, true);
      	}
      	else
      	{
         	*(o->OutStream()) << "\t" << mol2can.WriteString(&mol, true);
      	}
      
      	// Extract scaffolds
      	for (unsigned int i(0); i < scaffolds.size(); ++i)
      	{
         	s = dynamic_cast<Scaffold*>(scaffolds[i]);
         	if (s->CalculateScaffold(mol, o))
         	{
            	counter.NewScaffold();
         	}
         	else
         	{
            	counter.FailedScaffold();
         	}
         	if (o->OutFilename().empty())
         	{
            	std::cout << "\t" << s->PrintScaffold();
         	}
         	else
         	{
            	*(o->OutStream()) << "\t" << s->PrintScaffold();
         	}
      	}
      	if (o->OutFilename().empty())
      	{
         	std::cout << std::endl;
      	}
      	else
      	{
         	*(o->OutStream()) << std::endl;
      	}
      	mol.Clear();
   	}

   	// Return
   	return counter;
}
