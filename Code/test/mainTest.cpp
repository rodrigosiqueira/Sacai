#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>

int main (int argc, char* argv[])
{
	//Tell for listening about the result of test
	CPPUNIT_NS :: TestResult testresult;

	//Register the listners for collect the result of tests
	CPPUNIT_NS :: TestResultCollector collectedresults;
	testresult.addListener(&collectedresults);

	//Listener of register for per-test
	CPPUNIT_NS :: BriefTestProgressListener progress;
	testresult.addListener(&progress);

	//Insert the suite test in testrunner for the register
	CPPUNIT_NS :: TestRunner testrunner;
	testrunner.addTest(CPPUNIT_NS :: TestFactoryRegistry :: getRegistry().makeTest());
	testrunner.run(testresult);

	//Result of output in compile format
	CPPUNIT_NS :: CompilerOutputter compileroutputter (&collectedresults, std::cerr);
	compileroutputter.write();

	//Return 0 if the result was successfull
	return collectedresults.wasSuccessful() ? 0 : 1;
}

