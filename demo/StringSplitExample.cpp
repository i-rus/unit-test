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
//        File: StringSplitExample.cpp
// Description: Example file to illustrate the use of UnitTest.
//      Author: Ioan L. Rus
//        Date: Aug 29, 2014
//   Revisions: 
// -------------------------------------------------------------------
// INI Date        Description
// --- ----------- ---------------------------------------------------
// 
// *******************************************************************
#include "StringSplitExample.h"

#include <ctype.h>

bool StringSplitExample::Split(const char *str)
{
  m_count=0;
  if(str==nullptr) return false;

  while(*str!='\0')
  {
    while(isspace(*str)) ++str;

    m_strings[m_count].clear();

    while(!isspace(*str) && *str!='\0')
    {
      m_strings[m_count]+=*str++;
    }

    if(++m_count >= MAX_SUBSTRINGS) return false;
  }

  return true;
}

unsigned StringSplitExample::GetSubstringCount()
{
  return m_count;
}

bool StringSplitExample::GetSubstring(std::string &str,unsigned index)
{
  if(index>=m_count) return false;
  str=m_strings[index];
  return true;
}


#ifdef ENABLE_UNIT_TEST

DEFINE_TEST_METHOD(StringSplitExample)
{
  StringSplitExample s;

  std::string str;

  TEST_T(s.GetSubstringCount()==0); // we've split nothing yet
  TEST_F(s.GetSubstring(str,0));    // expected to fail
  TEST_F(s.GetSubstring(str,1));    // expected to fail
  TEST_F(s.GetSubstring(str,100));  // expected to fail

  // Split string
  TEST_T(s.Split("ab cde"));        // perform split...
  TEST_T(s.GetSubstringCount()==2); // expect 2 substrings

  TEST_T(s.GetSubstring(str,0));    // check first substring
  TEST_T(str=="ab");                //

  TEST_T(s.GetSubstring(str,1));    // check seconds substring
  TEST_T(str=="cde");               //

  TEST_F(s.GetSubstring(str,2));    // there should not be a third

  // Test with leading and trailing spaces
  TEST_T(s.Split("  abd  de  "));   // perform split...
  TEST_T(s.GetSubstringCount()==2); // expect 2 substrings

  TEST_T(s.GetSubstring(str,0));    // check first substring
  TEST_T(str=="abc");               //

  TEST_T(s.GetSubstring(str,1));    // check seconds substring
  TEST_T(str=="de");                //

  TEST_F(s.GetSubstring(str,2));    // there should not be a third


  RETURN_SUCCESS();
}

#endif

