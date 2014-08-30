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
//        File: UnitTest.h
// Description: Simple C++ Unit Test framework
//      Author: Ioan L. Rus
//        Date: Aug 29, 2014
//   Revisions: 
// -------------------------------------------------------------------
// INI Date        Description
// --- ----------- ---------------------------------------------------
// 
// *******************************************************************
#ifndef _UNITTEST_H_INCLUDED_
#define _UNITTEST_H_INCLUDED_

// Comment this out to disable all unit test code
#define ENABLE_UNIT_TEST

#ifdef ENABLE_UNIT_TEST

// Use thread-safe init by default
#define USE_THREAD_SAFE_INIT 1

#if USE_THREAD_SAFE_INIT
#include "Singleton.h"
#endif

namespace Ioan {

  class UnitTest 
#if USE_THREAD_SAFE_INIT
    : public Ioan::Thread::SingletonRef<UnitTest>
#endif
  {
#if USE_THREAD_SAFE_INIT
  private:
    friend class Ioan::Thread::SingletonRef<UnitTest>;
#endif

  public:
    typedef void (*ReportErrorCallback)(const char *errFile,int errLine);

  public:
    // This struct is used to register all test functions into a
    // linked list structure
    struct UnitTestInstance
    {
      typedef int (*TestFunction)();

      UnitTestInstance  *m_pNext;
      TestFunction       m_test;
      const char        *m_pszFile;

      UnitTestInstance(TestFunction test,const char *pszFile) 
        : m_pNext(0)
        , m_test(test)
        , m_pszFile(pszFile)
      {
        UnitTest::GetInstance().AddTest(this);
      }
    };

  private:
    UnitTestInstance *m_pTestList;

    UnitTest();

  public:
#if !USE_THREAD_SAFE_INIT
    static UnitTest &GetInstance();
#endif

    void AddTest(UnitTestInstance *p);
    bool RunTests(ReportErrorCallback cb=nullptr,bool bStopOnFirstError=false);
  }; // class UnitTest

}; // namespace Ioan


// Use this macro to declare the test method in the class definition.
// Doing so gives your test function access to the private members of
// the class for deep inspection.
#define DECLARE_TEST_METHOD() \
  static int UnitTest()

// Use this macro to define the test method. Pass the name of the
// class as the first argument. The test method is declared as static,
// so follow the guidelines for static methods when implementing the
// function body.
#define DEFINE_TEST_METHOD(cls) \
  static Ioan::UnitTest::UnitTestInstance Test##obj##__LINE__( cls::UnitTest,__FILE__); \
  int cls::UnitTest()


// If you're not happy with the default methods names, you can use
// this version to specify your own function name.
#define DECLARE_NAMED_TEST_METHOD(fn) \
  static int fn()

// Named function definition
#define DEFINE_NAMED_TEST_METHOD(cls,fn) \
  static Ioan::UnitTest::UnitTestInstance fn##obj##__LINE__(cls::fn,__FILE__); \
  int cls::fn()


// If you don't want/need a test method, you can also define test
// functions using this macro.
#define DEFINE_TEST_FUNCTION(fn) \
  static int fn(); \
  static Ioan::UnitTest::UnitTestInstance testManagerFunctionObj_##__LINE__(fn,__FILE__); \
  static int fn()


// Add this macro as the first line in main() to run your tests. The
// macro will exit the program by returning from main() with an exit
// code of 1 if any unit tests fail. The RunTests() method has this
// signature:
//
// bool RunTests
//  ( ReportErrorCallback cb=nullptr 
//  , bool bStopOnFirstError=false 
//  );
//

// Normally, the default arguments are fine. If you don't want the
// test results to be printed to the screen, pass a pointer to your
// own callback function. This is useful if you want to write the
// results to a log file, or perhaps want to display them in a message
// box.
#define RUN_UNIT_TESTS(...) if(!Ioan::UnitTest::GetInstance().RunTests(__VA_ARGS__)) return 1
#define RUN_UNIT_TESTS_NOEXIT(...) Ioan::UnitTest::GetInstance().RunTests(__VA_ARGS__)

#define TEST_T(x) if(!(x)) return __LINE__
#define TEST_F(x) if((x)) return __LINE__
#define RETURN_FAILURE() return __LINE__
#define RETURN_SUCCESS() return 0

#else // defined(ENABLE_UNIT_TEST)

#define DECLARE_NAMED_TEST_METHOD(fn)    /*nada*/
#define DEFINE_NAMED_TEST_METHOD(cls,fn) /*nada*/

#define DECLARE_TEST_METHOD()            /*nada*/
#define DEFINE_TEST_METHOD(cls)          /*nada*/

#define DEFINE_TEST_FUNCTION(fn)         /*nada*/

#define RUN_UNIT_TESTS(...)              /*nada*/
#define RUN_UNIT_TESTS_NOEXIT(...)       /*nada*/

#define TEST_T(x)                        /*nada*/
#define TEST_F(x)                        /*nada*/

#define RETURN_FAILURE()                 return __LINE__
#define RETURN_SUCCESS()                 return 0

#endif // defined(ENABLE_UNIT_TEST)

#endif // _UNITTEST_H_INCLUDED_
