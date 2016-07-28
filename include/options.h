/**********************************************************************
options.h - strip-it
 
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



#ifndef __OPTIONS_H__
#define __OPTIONS_H__



#include <string>
#include <sstream>

#include <openbabel/obconversion.h>



class Options
{
   	protected:

      	OpenBabel::OBConversion _iconv;
      	std::ifstream _ifs;
      	std::string _ifile; // --in

      	std::ofstream _ofs;
      	std::string _ofile; // --out

      	std::ifstream _sfs;
      	std::string  _sfile; // --scaffold

      	bool _log; // --noLog
      	bool _header; // --noHeader

   	public:
      
      	Options(void);
      	virtual ~Options(void);
      	Options(const Options&);
      	Options& operator=(const Options&);

      	virtual bool InputFilename(const std::string&);
      	virtual std::string InputFilename(void) const;
      	virtual std::string InputFormat(void) const;
      	virtual OpenBabel::OBConversion* InputConverter(void);
      	virtual std::ifstream* InputStream(void);

      	virtual bool OutFilename(const std::string&);
      	virtual std::string OutFilename(void) const;
      	virtual std::ofstream* OutStream(void);

      	virtual bool ScaffoldFilename(const std::string&);
      	virtual std::string ScaffoldFilename(void) const;
      	virtual std::ifstream* ScaffoldStream(void);

      	virtual std::string Print(void) const;     

      	virtual void SetLog(bool);     
      	virtual bool GetLog(void) const;     
      	virtual void SetHeader(bool);
      	virtual bool GetHeader(void) const;
};



#endif
