#include "StdAfx.h"
#include "TuringLogic.h"

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Core
		{
			TuringLogic::TuringLogic(void)
			{
			}

			void TuringLogic::Initialize(CsShared::ITuringCommandList ^ turingCommandList, System::String ^ inputString)
			{
			}
			
			void TuringLogic::Start(void)
			{
			}
			
			bool TuringLogic::Step(void)
			{
				return true;
			}
			
			void TuringLogic::Reset(void)
			{
				this->tapePosition = 0;
				this->terminated = false;
				this->tape = nullptr;
				this->nextMove = CsShared::MovementValues::Undefined;
			}
		}
	}
}