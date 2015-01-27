#include "ITuringCommandList.h"

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Shared
		{	
			using namespace System;
			
			public interface class ITuringLogic
			{
				event EventHandler ^ AfterStateChanged;
				
				property ITuringCommandList ^ CommandList { ITuringCommandList ^ get(); }
				
				property cli::array<wchar_t> ^ Tape { cli::array<wchar_t> ^ get(); }
				
				property int TapePosition { System::Int32 get(); }
				
				property MovementValues NextMove { MovementValues get(); }
				
				property wchar_t CurrentTapeChar { wchar_t get(); }

				property bool Terminated { bool get(); }
				
				property bool Ready { bool get(); }

				property int CurrentCommandIndex { int get(); }

				property ITuringCommand ^ CurrentCommand { ITuringCommand ^ get(); }

				void Initialize(ITuringCommandList ^ turingCommandList, System::String ^ inputString);

				void Load(System::String ^ filename, System::String ^ inputString);
				
				void Start();
				
				bool Step();
				
				void Reset();
			};
		}
	}
}