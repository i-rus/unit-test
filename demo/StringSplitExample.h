// *******************************************************************
// The MIT License (MIT)
// 
// Copyright (c) 2014 Ioan "John" Rus
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
// BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// -------------------------------------------------------------------
//        File: StringSplitExample.h
// Description: Example file to illustrate the use of UnitTest.
//      Author: Ioan L. Rus
//        Date: Aug 29, 2014
//   Revisions: 
// -------------------------------------------------------------------
// INI Date        Description
// --- ----------- ---------------------------------------------------
// 
// *******************************************************************
#ifndef _STRINGSPLITEXAMPLE_H_INCLUDED_
#define _STRINGSPLITEXAMPLE_H_INCLUDED_

// Usually, the UnitTest.h file is included in a project global header
// file. By doing that, the UnitTest.h file does not need to be
// included into every class that uses UnitTest.
#include "..\src\UnitTest.h"

#include <string>

// Sample class to demonstrate the use of C++ UnitTest. The class
// splits a string into substrings on whitespace boundaries. It is not
// very used (and buggy too), but it does illustrate the use of
// UnitTest.
class StringSplitExample
{
private:
  enum { MAX_SUBSTRINGS=4 };
  std::string m_strings[MAX_SUBSTRINGS];
  unsigned    m_count;

public:
  StringSplitExample()
    : m_count(0)
  {
  }

  bool Split(const char *str);

  unsigned GetSubstringCount();
  bool GetSubstring(std::string &str,unsigned index);

  // Add the unit test method here.
#ifdef ENABLE_UNIT_TEST
  DECLARE_TEST_METHOD();
#endif
};

#endif // _STRINGSPLITEXAMPLE_H_INCLUDED_
