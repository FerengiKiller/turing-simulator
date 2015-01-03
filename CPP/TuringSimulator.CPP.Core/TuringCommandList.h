#pragma once
#include "TuringCommand.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace TuringSimulator::CPP::Core;

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Core
		{
			public ref class TuringCommandList : public List<TuringCommand^>
			{
			public:
				TuringCommandList(void);
			};
		}
	}
}