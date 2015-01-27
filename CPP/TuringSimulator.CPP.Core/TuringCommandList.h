#pragma once
#include "TuringCommand.h"
namespace CppShared = TuringSimulator::CPP::Shared;


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
			/// (Implementiert das von ITuringCommandList geforderte IEnumerable �ber die Basisklasse List<>)
			/// </remarks>
			public ref class TuringCommandList : public List<CppShared::ITuringCommand^>, public CppShared::ITuringCommandList
			{
			public:
				TuringCommandList(void);

				virtual CppShared::ITuringCommandList ^ LoadFromFile(System::String ^filename);

				virtual CppShared::ITuringCommand^ SelectCommand(System::Int32 state, wchar_t input);
			};
		}
	}
}