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
//        File: UnitTest.cpp
// Description: Simple C++ Unit Test framework
//      Author: Ioan L. Rus
//        Date: Aug 29, 2014
//   Revisions: 
// -------------------------------------------------------------------
// INI Date        Description
// --- ----------- ---------------------------------------------------
// 
// *******************************************************************
#include "UnitTest.h"

#ifdef ENABLE_UNIT_TEST

#include <string.h>
#include <stdio.h>

static const char *GetNameOnly(const char *errFilePath)
{
#ifdef WIN32
  const char sep='\\';
#else
  const char sep='/';
#endif
  const char *errFile=strrchr(errFilePath,sep);
  return (errFile==0) ? errFilePath : errFile+1;
}

static void ReportErrorToConsole(const char *errFilePath,int errLine)
{
  if(errLine==0)
  {
    fprintf(stderr,"Info: %s tests OK...\n",GetNameOnly(errFilePath));
  }
  else
  {
    fprintf(stderr,"Error: Test failed at %s(%d)!\n",GetNameOnly(errFilePath),errLine);
  }
}


using namespace Ioan;


UnitTest::UnitTest()
  : m_pTestList(0)
{
}

#if !USE_THREAD_SAFE_INIT
UnitTest &UnitTest::GetInstance()
{
  static UnitTest tm;
  return tm;
}
#endif


void UnitTest::AddTest(UnitTestInstance *p)
{
  p->m_pNext=m_pTestList;
  m_pTestList=p;
}

bool UnitTest::RunTests(ReportErrorCallback cb,bool bStopOnFirstError)
{
  bool hadErrors=false;
  for(UnitTestInstance *p=m_pTestList; p!=0; p=p->m_pNext)
  {
    // run test
    int line=p->m_test();

    // report test result (line==0 on test success)
    if(cb!=0) cb(p->m_pszFile,line);
    else ReportErrorToConsole(p->m_pszFile,line);

    if(line!=0) 
    {
      hadErrors=true;
      if(bStopOnFirstError) break;
    }
  }

  return !hadErrors;
}

#endif // ENABLE_UNIT_TEST
