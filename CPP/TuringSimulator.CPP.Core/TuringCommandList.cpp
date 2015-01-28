// <copyright file="TuringCommandList.cpp" company="Privat">
//   Copyright (c) Sascha Schwegelbauer. All rights reserved.
// </copyright>

#include "StdAfx.h"
#include "TuringCommandList.h"

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Core
		{
			TuringCommandList::TuringCommandList(void)
			{
			}
			
			CppShared::ITuringCommandList ^ TuringCommandList::LoadFromFile(System::String ^filename)
			{
				this->Clear();
				
				try
				{
					array<String^>^ lines = System::IO::File::ReadAllLines(filename);
					for each ( String^ line in lines )
					{
						TuringCommand^ newCommand = gcnew TuringCommand(line);
						this->Add(newCommand);
					}
				}
				catch ( Exception^ )
				{
					this->Clear(); // Sicherstellen, dass bei einem Ladefehler keine 'Reste' übrig bleiben
					throw;
				}
				
				return this;
			}
			
			CppShared::ITuringCommand^ TuringCommandList::SelectCommand(System::Int32 state, wchar_t input)
			{
				for each ( CppShared::ITuringCommand ^ command in this )
				{
					if ( command->Z0 == state && command->GZ == input )
						return command;
				}
				
				return nullptr;
			}
			
			System::Nullable<System::Int32> TuringCommandList::GetCommandIndex(System::Int32 state, wchar_t input)
			{
				System::Int32 index = 0;
				for each ( CppShared::ITuringCommand ^ command in this )
				{
					if ( command->Z0 == state && command->GZ == input )
						return Nullable<System::Int32>(index);

					index++;
				}
				
				return Nullable<System::Int32>();
			}
		}
	}
}