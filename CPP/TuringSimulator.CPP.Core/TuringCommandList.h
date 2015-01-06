#pragma once
#include "TuringCommand.h"

namespace CsShared = TuringSimulator::CS::Shared;

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Core
		{
			using namespace System;
			using namespace System::Collections::Generic;

			/// <summary>Implementiert eine Liste von ITuringCommands</summary>
			/// <remarks>
			/// Keine Pr�fung auf mehrere, identische Steps (keine wirkliche Einschr�nkung)
			/// </remarks>
			public ref class TuringCommandList : public List<CsShared::ITuringCommand^>, public CsShared::ITuringCommandList
			{
			public:
				TuringCommandList(void);

				virtual CsShared::ITuringCommandList ^ LoadFromFile(System::String ^filename);

				virtual CsShared::ITuringCommand^ SelectCommand(int state, wchar_t input);
			};
		}
	}
}