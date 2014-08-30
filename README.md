# unit-test
Basic C++ Unit Test Framework

## Goals
- Code only, no heavy framework required. Consists of only two files.
- Available when you need it, remove with one #define
- Dead-simple to use

## Adding unit testing to a C++ class in three easy steps

1. Include UnitTest.h and UnitTest.cpp in your project. Add a unit test function to the class definition:

<pre>class ClassToBeTested
{
  ...

public:
#ifdef ENABLE_UNIT_TEST
	DECLARE_TEST_METHOD2();
#endif
};</pre>

2. Define the test function implementation. The test function is defined as static, so treat it as any other static function.

<pre>#ifdef ENABLE_UNIT_TEST

#include "UnitTest.h"

DEFINE_TEST_METHOD2(ClassToBeTested)
{
  // --- tests go here ---
  ClassToBeTested obj;

  TEST_T(obj.Function1());
  TEST_T(obj.Function2());
  ...
  
  RETURN_SUCCESS();
}

#endif</pre>

3. Add the RUN_UNIT_TESTS() macro as the first line in main() to run all unit tests. 

<pre>int main(int argc,char *argv[])
{
  RUN_UNIT_TESTS();
  
  ...
}</pre>

Now, if any of the tests fail, then main() will exit and display the file name and line number of the test that failed. You place a breakpoint on the offending line and debug away.

Have a look at the demo project source code for additional details.
