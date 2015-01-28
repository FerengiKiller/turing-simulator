// <copyright file="ITuringCommandList.h" company="Privat">
//   Copyright (c) Sascha Schwegelbauer. All rights reserved.
// </copyright>

#pragma once
#include "ITuringCommand.h"

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Shared
		{	
			using namespace System;
			
			/// <summary></summary>
			public interface class ITuringCommandList : System::Collections::IList
			{
				property System::Int32 Count { System::Int32 get(); }
				
				property ITuringCommand ^ default[System::Int32]
				{
					ITuringCommand ^ get(System::Int32 index);
					void set(System::Int32 index, ITuringCommand ^ value);
				}
				
				ITuringCommandList ^ LoadFromFile(System::String ^ filename);
				
				ITuringCommand ^ SelectCommand(System::Int32 state, wchar_t input);

				System::Nullable<System::Int32> GetCommandIndex(System::Int32 state, wchar_t input);
			};
		}
	}
}