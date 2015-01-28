#pragma once
#include "MovementValues.h"
namespace TuringSimulator
{
	namespace CPP
	{
		namespace Shared
		{
			/// <summary>Implementiert ITuringCommand</summary>
			/// <remarks>
			/// </remarks>
			public interface class ITuringCommand
			{
				property System::Int32 Line;

				property System::Int32 Z0;

				property wchar_t GZ;
				
				property System::Int32 Z1;

				property wchar_t SZ;
				
				property TuringSimulator::CPP::Shared::MovementValues MOV;
			};
		}
	}
}