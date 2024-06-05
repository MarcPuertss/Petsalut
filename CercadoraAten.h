#pragma once
#include "PassarellaAten.h"

using namespace System;
using namespace System::Collections::Generic;
ref class CercadoraAten
{
	public:
		List<String^>^ cercaTipusAten(int id);
		static List<int>^ cercaCentreIdsPerTipus(String^ tipus);
};