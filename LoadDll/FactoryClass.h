#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

#include "TunerInterface.h"

using namespace std;

class FactoryTuner
{
public:
	static TunerInterface* create(std::string aName)
	{
		if (aName == "one")
		{
			typedef TunerInterface* (__cdecl *iklass_factory)(std::string name);
			HINSTANCE dllObject = ::LoadLibrary(TEXT("DllTuner1.dll"));//TODO: maybe it can be "Static"
			
			if (!dllObject) {
				std::cerr << "Unable to load DllTuner1.dll!\n";
				return nullptr;
			}

			iklass_factory Tuner1 = reinterpret_cast<iklass_factory>(
				::GetProcAddress(dllObject, "createTuner1"));
			if (!Tuner1) {
				std::cerr << "Unable to load create_klass from DLL!\n";
				::FreeLibrary(dllObject);
				return nullptr;
			}

			TunerInterface* tuner1 = Tuner1("Tuner Number ONE!!!!");
			return tuner1;
		}
		if (aName == "two")
		{
			typedef TunerInterface* (__cdecl *iklass_factory)(std::string name);
			HINSTANCE dllObject = ::LoadLibrary(TEXT("DllTuner2.dll"));

			if (!dllObject) {
				std::cerr << "Unable to load DllTuner2.dll!\n";
				return nullptr;
			}

			iklass_factory Tuner2 = reinterpret_cast<iklass_factory>(
				::GetProcAddress(dllObject, "createTuner2"));
			if (!Tuner2) {
				std::cerr << "Unable to load create_klass from DLL!\n";
				::FreeLibrary(dllObject);
				return nullptr;
			}

			TunerInterface* tuner2 = Tuner2("Tuner Number Two!!!!");
			return tuner2;
		}
		return nullptr;
	}
};