#pragma once
#include "TuringCommand.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace TuringSimulator::CPP::Core;
namespace CsShared = TuringSimulator::CS::Shared;

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Core
		{
			public ref class TuringCommandList : public List<CsShared::ITuringCommand^>, public CsShared::ITuringCommandList
			{
			public:
				TuringCommandList(void);

				virtual void LoadFromFile(System::String ^filename);

				virtual CsShared::ITuringCommand^ SelectCommand(int state, wchar_t input);
			};
		}
	}
}