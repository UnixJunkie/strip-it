/**********************************************************************
main.cpp - strip-it
 
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



#include <options.h>
#include <calculator.h>
#include <parseCommandLine.h>
#include <parseScaffoldDefinitions.h>
#include <counter.h>



int main (int argc, char* argv[])
{
   	// Parse command line
   	Options* uo = new Options();
   	parseCommandLine(argc, argv, uo);
   	version();
   	std::cerr << uo->Print();
   
   	// Initiate the scaffold definitions
   	std::vector<Scaffold*> scaffolds = parseScaffoldDefinitions(uo);

   	// Calculate
   	std::cerr << std::endl;
   	std::cerr << "## START OF CALCULATIONS" << std::endl;
   	Calculator calculator;
   	Counter counts = calculator.Calculate(uo, scaffolds);
   	std::cerr << counts.Results();
   	std::cerr << "## END OF CALCULATIONS" << std::endl;

   	// Return
   	delete uo;
   	uo = NULL;
   	for (unsigned int i(0); i < scaffolds.size(); ++i)
   	{
      	delete scaffolds[i];
      	scaffolds[i] = NULL;
   	}
   	return 0;
}
