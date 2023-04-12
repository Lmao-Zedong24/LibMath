#include <catch2/catch_session.hpp>

/*
* todo: finish adding test to the debug section of the Vector3 test case in Vector_UnitTest.cpp
*/

/*
* Fun piece of code (for you to discover)
* 
* automatic converetion from Degree to Radian (see "Angle/Degree.h" line 16)
* literral can bypass explicit constructor (see "Angle/Degree.h" line 46)
* use of include guards instead of "pragma once" let you auto include stuff if another header is already included (see "Vector/Vector4" line 18)
* overloading operator>> make it easy to save/display state (see "Vector/Vector3" line 89)
* macro that performe many catch test in a single test will still displaying the right variable name (see "Vector_UnitTest.cpp" line 14)
* 
* 
* 
* tricks (you can use)
* 
* you may want to set LibMath_UnitTest as your startup project
* be wary of where the physical file are place when using "Add/New Item..."
* many function body can reuse other function (this is called the DRY principle, as opposed to the WET principle)
* you can use the default keyword (other keywords include: delete, static, consteval, noexcept, [[nodiscard]], inline, ...)
* many function can be made constexpr (this will trade runtime execution for compile time execution)
* inline/constexpr function body can be defined in a .hpp/.inl file and included in you headear file (keeping function declaration and definition separated)
* replacing "Vector3" with a template, then making typedef for floats call "Vector3" won't brake the unit test (if done well)
* you can change the folder structure or add/remove file as you see fit (you may want to refactor/rename the test file)
* you are forbidden to use glm in your math library but it is allowed to use to test against in the unit test (I greatly encourage you to do that extensively)
* you can add custom argument to the arguments' vector in the main function
* 
* 
* 
* traps
* 
* many comment left by me make you lines execed your coding standard limits (you will have to fix this)
* this main function is way too long to fit your coding standard limits (you will also have to fix this)
* Radian, Degree, Vector3 are by no means fully complete (you can add to them any function you think would be useful (don't forget to test))
* test only for success think of as many edge case as you can and create as many test, your math library will be that more robust
* disable working test once they've pass, keeping them active will protect you against regression as you add more functionnality
* 
* 
* 
* references
* https://en.cppreference.com/w/cpp/language/operators
* 
* https://docs.unity3d.com/ScriptReference/Vector3.html
* https://docs.unity3d.com/ScriptReference/Mathf.html
* https://docs.unity3d.com/ScriptReference/Matrix4x4.html
* https://docs.unrealengine.com/4.26/en-US/API/Runtime/Core/Math/FVector/
* https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FMath/
* https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FMatrix/
*/

#if defined _WIN32 // for memory leak tracking when you will transfer on Windows' Visual Studio
int mainImpl(int argc, char* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	// transfers command line argument to dynamique collection so we can add our own argument easily
	std::vector<char const*> arguments;
	for (int i = 0; i < argc; i++)
	{
		arguments.push_back(argv[i]);
	}

	/************************************\
	*                                    *
	*    uncomment line(s) from below    *
	*    to run all test cases marked    *
	*    by at least 1 of the            *
	*    uncommented tags                *
	*                                    *
	*    By default :                    *
	*    If no test are specified, no    *
	*    test are runned                 *
	*                                    *
	\************************************/
	//arguments.push_back("[all],");
	arguments.push_back("[angle],");
	//arguments.push_back("[vector],");


	/************************************\
	*                                    *
	*    uncomment line(s) from below    *
	*    to add the test case with       *
	*    matching name to the list of    *
	*    test cases to run defined       *
	*    above                           *
	*                                    *
	*    Note :                          *
	*    You can leave de section        *
	*    above fully commented out       *
	*    and only uncomment line(s)      *
	*    from this section               *
	*                                    *
	\************************************/
	arguments.push_back("Degree,");
	//arguments.push_back("Radian,");
	//arguments.push_back("Vector2,");
	//arguments.push_back("Vector3,");
	//arguments.push_back("Vector4,");


	/************************************\
	*                                    *
	*    uncomment line(s) from below    *
	*    to only run specific section    *
	*    from the test selected above    *
	*                                    *
	*    By default :                    *
	*    If no section are specified,    *
	*    all section are runned          *
	*                                    *
	\************************************/
	//arguments.push_back("-c Accessor");
	//arguments.push_back("-c Arithmetic");
	//arguments.push_back("-c Comparator");
	//arguments.push_back("-c Constant");
	//arguments.push_back("-c Conversion");
	//arguments.push_back("-c Debug");
	//arguments.push_back("-c Extra");
	//arguments.push_back("-c Functionality");
	arguments.push_back("-c Instantiation");
	//arguments.push_back("-c Transformation");


	/************************************\
	*                                    *
	*    add more catch command line     *
	*    argument here                   *
	*                                    *
	\************************************/
	// https://github.com/catchorg/Catch2/blob/devel/docs/command-line.md
	//arguments.push_back("-o test file.txt"); // catch2 will output the test result to "test file.txt" instead of the console
	/*
	std::string argument = std::string("-o ") + __DATE__ + ' ' + __TIME__ + ".txt";
	std::replace(argument.begin(), argument.end(), ':', '.');
	arguments.push_back(argument.c_str()); // catch2 will output the test result to a file name after the current date instead of the console
	*/

	// running catch test with command line argument + custom argument from main
	return Catch::Session().run((int)arguments.size(), &arguments[0]);
}


#if defined _WIN32 // for memory leak tracking when you will transfer on Windows' Visual Studio

//#include <iostream>
//#define WIN32_LEAN_AND_MEAN // do not include rarely use functionnality of <Windows.h> (reduce compile time)
//#include <Windows.h>
//#define _CRTDG_MAP_ALLOC //to get more detail
//#include <stdlib.h>
//#include <crtdbg.h> //for malloc & free

int main(int argc, char* argv[])
{
	//_CrtMemState sOld;
	//_CrtMemState sNew;
	//_CrtMemState sDiff;
	//_CrtMemCheckpoint(&sOld); //take a snapshot

	int exitCode = mainImpl(argc, argv);

	//_CrtMemCheckpoint(&sNew); //take a snapshot
	//if (_CrtMemDifference(&sDiff, &sOld, &sNew)) //if diff exist
	//{
	//	OutputDebugString("----- _CrtMemDumpStatistics -----");
	//	_CrtMemDumpStatistics(&sDiff);
	//	OutputDebugString("----- _CrtMemDumpAllObjectsSince -----");
	//	_CrtMemDumpStatistics(&sOld);
	//	OutputDebugString("----- _CrtMemDumpMemoryLeak -----");
	//	_CrtDumpMemoryLeaks();
	//}

	return exitCode;
}
#endif // defined _WIN32