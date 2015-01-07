#include "StdAfx.h"
#include "TuringLogic.h"
#include "TuringCommandList.h"
namespace CppShared = TuringSimulator::CPP::Shared;

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Core
		{
			void TuringLogic::Initialize(CppShared::ITuringCommandList ^ turingCommandList, System::String ^ inputString)
			{
				this->CommandList = turingCommandList;
				this->tape = inputString->ToCharArray();
				this->tapePosition = 0;
				this->terminated = false;
				this->nextMove = CppShared::MovementValues::Undefined;
				this->ready = true;

				this->RaiseAfterStateChanged();
			}

			void TuringLogic::Load(System::String ^ filename, System::String ^ inputString)
			{
				CppShared::ITuringCommandList ^ turingCommandList = gcnew TuringCommandList();
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
					case CppShared::MovementValues::S:
						this->terminated = true;
						this->ready = false;
						return false;
					case CppShared::MovementValues::R:
						this->tapePosition++;
						break;
					case CppShared::MovementValues::L:
						this->tapePosition--;
						break;
					case CppShared::MovementValues::Undefined:
						break;
					default:
						throw gcnew ArgumentOutOfRangeException();
				}

				wchar_t tempChar = this->CurrentTapeChar;
				CppShared::ITuringCommand ^ command = this->CommandList->SelectCommand(this->currentState, tempChar);
				this->currentState = command->Z1;

				// Zeichen auf Tape ggfls. ersetzen lt. Anweisung
				if ( command->SZ != '#' )
					this->Tape[this->TapePosition] = command->SZ;
				
				this->nextMove = command->MOV;
				Debug::WriteLine(String::Format("Post-Step: Pos: {0} | char: {1} -> {2} | Mov: {3} | Tape: {4}", this->TapePosition, tempChar, this->CurrentTapeChar, command->MOV, this->Tape->Length < 50 ? gcnew String(this->Tape) : "Tape zu lang (> 50)"));

				this->RaiseAfterStateChanged();

				return true;			
			}
			
			void TuringLogic::Reset(void)
			{
				this->tapePosition = 0;
				this->terminated = false;
				this->tape = nullptr;
				this->nextMove = CppShared::MovementValues::Undefined;
				this->ready = false;

				this->RaiseAfterStateChanged();
			}

			/// Prüft bzw. ruft den EventHandler für AfterStateChanged auf
			/// 2015-01-06 SaS: Sollte an sich auch ohne den nullptr-check funktionieren, nur lässt sich das (nach meinem aktuellen C++/CLI - Wissen) nicht mit der Definition des Events im Interface vereinbaren
			void TuringLogic::RaiseAfterStateChanged()
			{
				if ( this->afterStateChanged != nullptr )
					this->afterStateChanged->Invoke(this, System::EventArgs::Empty);
			}
		}
	}
}