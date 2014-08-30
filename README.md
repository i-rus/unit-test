# Basic C++ Unit Test Framework

Way back in 1949, computing pioneer Maurice Wilkes said "I can remember the exact instant when I realized that a large part of my life from then on was going to be spent in finding mistakes in my own programs."  Many of us had  similar realizations. This unit test framework is my attempt at reducing the time spent debugging, while also reducing the number of bugs in the code. 

## Features
- Code only, compiled in your application. Just add UnitTest.cpp to your project.
- Available when you need it, remove with one #define.
- Dead-simple to use.
- Usable in Windows, Linux, or embedded projects.
- Free to use in commercial or open source projects (MIT license).

## Adding unit testing to a C++ class in three easy steps

**Step 1:** Add a unit test function to the class definition:

<pre>class ClassToBeTested
{
  ...

public:
#ifdef ENABLE_UNIT_TEST
	DECLARE_TEST_METHOD();
#endif
};</pre>

**Step 2:** Define the test function implementation. The test function is defined as static, so treat it as any other static function.

<pre>#ifdef ENABLE_UNIT_TEST

#include "UnitTest.h"

DEFINE_TEST_METHOD(ClassToBeTested)
{
  // --- tests go here ---
  ClassToBeTested obj;

  TEST_T(obj.Function1());
  TEST_T(obj.Function2());
  ...
  
  RETURN_SUCCESS();
}

#endif</pre>

**Step 3:** Add the RUN_UNIT_TESTS() macro as the first line in main() to run all unit tests. 

<pre>int main(int argc,char *argv[])
{
  RUN_UNIT_TESTS();
  
  ...
}</pre>

Now, if any of the tests fail, main() will exit and display the file name and line number of the test that failed. You place a breakpoint on the offending line and debug away.

Have a look at the demo project source code for additional details.
