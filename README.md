unit-test
=========

Basic C++ Unit Test Framework

Adding unit testing to a C++ class in three easy steps
1. Add a unit test function to the class definition:

<pre>
class ClassToBeTested
{
  ...
public:
  ...
  
#ifdef ENABLE_TESTMANAGER
	DECLARE_TEST_METHOD2();
#endif
};
</pre>



