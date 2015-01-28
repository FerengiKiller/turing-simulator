// <copyright file="TuringCommandList.h" company="Privat">
//   Copyright (c) Sascha Schwegelbauer. All rights reserved.
// </copyright>

#pragma once
#include "TuringCommand.h"

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Core
		{
			using namespace System;
			using namespace System::Collections::Generic;
			namespace CppShared = TuringSimulator::CPP::Shared;

			/// <summary>Implementiert eine Liste von ITuringCommands</summary>
			/// <remarks>
			/// Keine Prüfung auf mehrere, identische Steps (keine wirkliche Einschränkung)
			/// (Implementiert das von ITuringCommandList geforderte IEnumerable über die Basisklasse List<>)
			/// </remarks>
			public ref class TuringCommandList : public List<CppShared::ITuringCommand^>, public CppShared::ITuringCommandList
			{
			public:
				TuringCommandList(void);

				virtual CppShared::ITuringCommandList ^ LoadFromFile(System::String ^filename);

				virtual CppShared::ITuringCommand^ SelectCommand(System::Int32 state, wchar_t input);

				virtual System::Nullable<System::Int32> GetCommandIndex(System::Int32 state, wchar_t input);
			};
		}
	}
}