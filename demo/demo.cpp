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
//        File: demo.cpp
// Description: Example file to illustrate the use of UnitTest.
//      Author: Ioan L. Rus
//        Date: Aug 29, 2014
//   Revisions: 
// -------------------------------------------------------------------
// INI Date        Description
// --- ----------- ---------------------------------------------------
// 
// *******************************************************************
#include "..\src\UnitTest.h"
#include "StringSplitExample.h"


int main(int argc,char *argv[])
{
  // The macro below will run all unit tests defined in the project.
  // Have a look at the StringSplitExample.h and .cpp for an example
  // of how to use UnitTest.
  RUN_UNIT_TESTS();

  // run the application normally from here on...
  // StringSplitExample s;
  // ...

  return 0;
}

