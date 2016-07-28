/**********************************************************************
parseCommandLine.cpp - strip-it
 
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



#include <parseCommandLine.h>



void
parseCommandLine(int argc, char* argv[], Options* o)
{
  	static struct option Arguments[] =
	{
      	{ "input",               required_argument,   NULL, 11 },
		{ "output",              required_argument,   NULL, 12 },
		{ "scaffolds",           required_argument,   NULL, 13 },
		{ "noLog",               no_argument,         NULL, 14 },
		{ "noHeader",            no_argument,         NULL, 15 },
		{ "help",                no_argument,         NULL, 21 },
		{ "version",             no_argument,         NULL, 22 },
		{ "inputFormat",         required_argument,   NULL, 23 },
      	{ NULL,                  0,                   NULL,  0 }
	};

   	// Process command-line
	bool sethelp = false;
	bool setversion = false;
   	int choice;
   	std::string ff;
	opterr = 0;
	int optionIndex = 0;
	OpenBabel::OBFormat* format = NULL;
	
	while ((choice = getopt_long(argc, argv, "vh", Arguments, &optionIndex )) != -1)
	{
      	switch(choice)
		{
         	case 11:
            (void) o->InputFilename(optarg);
            // Check if filename is provided
            if ((o->InputFilename()).empty())
            {
              	std::cerr << "ERROR: No filename provided with the '--input <file>' option." << std::endl;
               	std::cerr << "       Please use -h or --help for more help." << std::endl;
               	exit(1);
           	}
            // Check file format
			format = (!format) ? o->InputConverter()->FormatFromExt(optarg) : format;
            if (!format)
            {
           		std::cerr << "ERROR: Could not detect format from the '--input <file>' option." << std::endl;
               	std::cerr << "       Please use -h or --help for more help." << std::endl;
               	exit(1);
            }
            o->InputConverter()->SetInFormat(format);
            // Check validity of file
            o->InputStream()->open(optarg);
            if (!o->InputStream()->good())
            {
              	std::cerr << "ERROR: Cannot open the file as specified by the '--input <file>' option." << std::endl;
               	std::cerr << "       Please use -h or --help for more help." << std::endl;
               	exit(1);
            }
            o->InputConverter()->AddOption("d", OpenBabel::OBConversion::GENOPTIONS);
            break;
            
         	case 12:
            (void) o->OutFilename(optarg);
            // Check if filename is provided
            if ((o->OutFilename()).empty())
            {
              	std::cerr << "ERROR: No filename provided with the '--output <file>' option." << std::endl;
               	std::cerr << "       Please use -h or --help for more help." << std::endl;
               	exit(1);
            }
            // Check validity of file
            o->OutStream()->open(optarg);
            if (!o->OutStream()->good())
            {
               	std::cerr << "ERROR: Cannot open the file as specified by the '--output <file>' option." << std::endl;
               	std::cerr << "       Please use -h or --help for more help." << std::endl;
               	exit(1);
            }
            break;

         	case 13:
            (void) o->ScaffoldFilename(optarg);
            // Check if filename is provided
            if ((o->ScaffoldFilename()).empty())
            {
               	std::cerr << "ERROR: No filename provided with the '--scaffolds <file>' option." << std::endl;
               	std::cerr << "       Please use -h or --help for more help." << std::endl;
               	exit(1);
            }
            // Check validity of file
            o->ScaffoldStream()->open(optarg);
            if (!o->ScaffoldStream()->good())
            {
               	std::cerr << "ERROR: Cannot open the file as specified by the '--scaffolds <file>' option." << std::endl;
               	std::cerr << "       Please use -h or --help for more help." << std::endl;
               	exit(1);
            }
            break;

         	case 14:
            (void) o->SetLog(false);
            break;

            case 15:
            (void) o->SetHeader(false);
            break;

	        case 21:
			case 'h':
			sethelp = true;
	        break;

		    case 22:
         	case 'v':
			setversion = true;
            break;
			
			case 23:
			format = o->InputConverter()->FindFormat(optarg);
			break;
           
			default:
            version();
            usage();
            std::cerr << "ERROR:" << std::endl << std::endl;
			std::cerr << "  Unknown command-line option " << argv[optind - 1] << std::endl;
            exit(1);
			break;
		}
	}

	argc -= optind;
	argv += optind;

	if (sethelp)
	{
		version();
		usage();
		exit(0);
	}
	
	if (setversion)
	{
		version();
		exit(0);
	}

   	// Input file processing
   	if (o->InputFilename().empty())
   	{
      	std::cerr << "ERROR: Required command-line option '--input <file>' has not been given." << std::endl;
      	std::cerr << "       Please use -h or --help for more help." << std::endl;
      	exit(1);
   	}
}



void
usage(void) 
{
   	std::cerr << std::endl;
   	std::cerr << "TASK: " << std::endl;
   	std::cerr << std::endl;
   	std::cerr << "  Strip-it is a tool to extract predefined scaffolds from input molecules." << std::endl;
   	std::cerr << std::endl;
   	std::cerr << "REQUIRED OPTIONS:" << std::endl;
   	std::cerr << std::endl;
   	std::cerr << "  --input <file>" << std::endl;
   	std::cerr << "    Specifies the file containing the input molecules. The format of the" << std::endl;
	std::cerr << "    file is specified by its file extension or by the --inputFormat option." << std::endl;
	std::cerr << "    Gzipped files are also read." << std::endl;
   	std::cerr << std::endl;
   	std::cerr << "OPTIONAL OPTIONS:" << std::endl;
   	std::cerr << std::endl;
   	std::cerr << "  --output <file>" << std::endl;
   	std::cerr << "    Specifies the file to which the extracted scaffolds are written." << std::endl;
   	std::cerr << "    The file is a text file with on each row the original molecule" << std::endl;
   	std::cerr << "    and the generated scaffolds in SMILES format. If this option is " << std::endl;
   	std::cerr << "    not provided, then all scaffolds are written to standard output." << std::endl;
   	std::cerr << std::endl;
   	std::cerr << "  --inputFormat <format>" << std::endl;
   	std::cerr << "    Specifies the input file format. If not provided then the format" << std::endl;
   	std::cerr << "    is determined from the file extension." << std::endl;
   	std::cerr << std::endl;
   	std::cerr << "  --scaffolds <file>" << std::endl;
   	std::cerr << "    Specifies the file in which the required scaffolds have been defined." << std::endl;
   	std::cerr << "    If not provided then all scaffolds are calculated." << std::endl;
   	std::cerr << std::endl;
   	std::cerr << "  --noLog" << std::endl;
   	std::cerr << "    Suppresses the output of additional information to standard error." << std::endl;
   	std::cerr << std::endl;
   	std::cerr << "  --noHeader" << std::endl;
   	std::cerr << "    Suppresses the header line in the output." << std::endl;
   	std::cerr << std::endl;
   	std::cerr << "  -h  --help" << std::endl;
   	std::cerr << std::endl;
   	std::cerr << "  -v  --version" << std::endl;
   	std::cerr << std::endl;
}



void
version(void)
{
	std::cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cerr << "  Strip-it v" << STRIPIT_VERSION;
   	std::cerr << "." << STRIPIT_RELEASE;
   	std::cerr << "." << STRIPIT_SUBRELEASE;
   	std::cerr << " | " << __DATE__;
   	std::cerr << " " << __TIME__ << std::endl;
	std::cerr << std::endl;
	std::cerr << "  -> GCC:         " << __VERSION__ << std::endl;
	std::cerr << "  -> Open Babel:  " << BABEL_VERSION << std::endl;
	std::cerr << std::endl;
	std::cerr << "  Copyright 2012 by Silicos-it, a division of Imacosi BVBA" << std::endl;
	std::cerr << std::endl;
	std::cerr << std::endl;
	std::cerr << "  Strip-it is free software: you can redistribute it and/or modify" << std::endl;
	std::cerr << "  it under the terms of the GNU Lesser General Public License as published" << std::endl;
	std::cerr << "  by the Free Software Foundation, either version 3 of the License, or" << std::endl;
	std::cerr << "  (at your option) any later version." << std::endl;
	std::cerr << std::endl;
	std::cerr << "  Strip-it is distributed in the hope that it will be useful," << std::endl;
	std::cerr << "  but WITHOUT ANY WARRANTY; without even the implied warranty of" << std::endl;
	std::cerr << "  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the" << std::endl;
	std::cerr << "  GNU Lesser General Public License for more details." << std::endl;
	std::cerr << std::endl;
	std::cerr << "  You should have received a copy of the GNU Lesser General Public License" << std::endl;
	std::cerr << "  along with Strip-it.  If not, see http://www.gnu.org/licenses/." << std::endl;
	std::cerr << std::endl;
	std::cerr << "  Strip-it is linked against OpenBabel version 2." << std::endl;
	std::cerr << "  OpenBabel is free software; you can redistribute it and/or modify" << std::endl;
	std::cerr << "  it under the terms of the GNU General Public License as published by" << std::endl;
	std::cerr << "  the Free Software Foundation version 2 of the License." << std::endl;
	std::cerr << std::endl;
}
