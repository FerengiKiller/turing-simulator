// <copyright file="ITuringLogic.h" company="Privat">
//   Copyright (c) Sascha Schwegelbauer. All rights reserved.
// </copyright>

#include "ITuringCommandList.h"

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Shared
		{	
			using namespace System;
			
			public delegate void LogEventArgs(System::String ^ logMessage);
			
			public interface class ITuringLogic
			{
				event EventHandler ^ AfterStateChanged;
				
				event LogEventArgs ^ LogReceived;

				property ITuringCommandList ^ CommandList { ITuringCommandList ^ get(); }
				
				property cli::array<wchar_t> ^ Tape { cli::array<wchar_t> ^ get(); }
				
				property int TapeheadPosition { System::Int32 get(); }
				
				property MovementValues NextMove { MovementValues get(); }
				
				property wchar_t CurrentTapeChar { wchar_t get(); }

				property bool Terminated { bool get(); }
				
				property bool Ready { bool get(); }

				property System::Nullable<System::Int32> CurrentCommandIndex { System::Nullable<System::Int32> get(); }

				void Initialize(ITuringCommandList ^ turingCommandList, System::String ^ inputString);

				/// <summary></summary>
				void InitializeFromFile(System::String ^ filename, System::String ^ inputString);
				
				void Start();
				
				bool Step();
				
				void Reset();
			};
		}
	}
}