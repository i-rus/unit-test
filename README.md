# unit-test
Basic C++ Unit Test Framework

## Goals
- Dead-simple to use
- Code only, no heavy framework required
- Available when you need it, remove with one #define

## Adding unit testing to a C++ class in three easy steps

1. Add a unit test function to the class definition:

<pre>class ClassToBeTested
{
  ...

public:
#ifdef ENABLE_TESTMANAGER
	DECLARE_TEST_METHOD2();
#endif
};</pre>

2. Define the test function implementation:

<pre>#ifdef ENABLE_TESTMANAGER

#include "TestManager.h"

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




