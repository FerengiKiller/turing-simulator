#pragma once
#include "ITuringCommand.h"

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Shared
		{	
			using namespace System;
			
			public interface class ITuringCommandList
			{
				property System::Int32 Count { System::Int32 get(); }
				
				property ITuringCommand ^ default[System::Int32]
				{
					ITuringCommand ^ get(System::Int32 index);
					void set(System::Int32 index, ITuringCommand ^ value);
				}
				
				ITuringCommandList ^ LoadFromFile(System::String ^ filename);
				
				ITuringCommand ^ SelectCommand(System::Int32 state, wchar_t input);
			};
		}
	}
}