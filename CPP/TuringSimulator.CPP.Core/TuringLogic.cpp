#include "StdAfx.h"
#include "TuringLogic.h"
#include "TuringCommandList.h"

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
				this->CommandList = turingCommandList;
				this->tape = inputString->ToCharArray();
				this->tapePosition = 0;
				this->terminated = false;
				this->nextMove = CsShared::MovementValues::Undefined;

				this->afterStateChanged(nullptr, nullptr);
			}

			void TuringLogic::Load(System::String ^ filename, System::String ^ inputString)
			{
				CsShared::ITuringCommandList ^ turingCommandList = gcnew TuringCommandList();
				this->Initialize(turingCommandList->LoadFromFile(filename), inputString);
			}
			
			void TuringLogic::Start(void)
			{
				if ( this->Tape == nullptr )
					throw gcnew NullReferenceException("Turing-Logik nicht initialisiert! Bitte zuerst Initialize() aufrufen.");
				
				while ( this->Step() )
				{
				}
			}
			
			bool TuringLogic::Step(void)
			{
				Debug::WriteLine(String::Format("Pre-Step : Pos: {0} | char: {1} | nMov: {2} | Tape: {3}", this->TapePosition, this->CurrentTapeChar, this->nextMove, this->Tape->Length < 50 ? gcnew String(this->Tape) : "Tape zu lang (> 50)"));
				
				switch ( this->nextMove )
				{						
					case CsShared::MovementValues::S:
						this->terminated = true;
						return false;
					case CsShared::MovementValues::R:
						this->tapePosition++;
						break;
					case CsShared::MovementValues::L:
						this->tapePosition--;
						break;
					case CsShared::MovementValues::Undefined:
						break;
					default:
						throw gcnew ArgumentOutOfRangeException();
				}

				wchar_t tempChar = this->CurrentTapeChar;
				CsShared::ITuringCommand ^ command = this->CommandList->SelectCommand(this->currentState, tempChar);
				this->currentState = command->Z1;

				// Zeichen auf Tape ggfls. ersetzen lt. Anweisung
				if ( command->SZ != '#' )
					this->Tape[this->TapePosition] = command->SZ;
				
				this->nextMove = command->MOV;
				Debug::WriteLine(String::Format("Post-Step: Pos: {0} | char: {1} -> {2} | Mov: {3} | Tape: {4}", this->TapePosition, tempChar, this->CurrentTapeChar, command->MOV, this->Tape->Length < 50 ? gcnew String(this->Tape) : "Tape zu lang (> 50)"));

				this->afterStateChanged(nullptr, nullptr);

				return true;			
			}
			
			void TuringLogic::Reset(void)
			{
				this->tapePosition = 0;
				this->terminated = false;
				this->tape = nullptr;
				this->nextMove = CsShared::MovementValues::Undefined;
				this->afterStateChanged(nullptr, nullptr);
			}
		}
	}
}