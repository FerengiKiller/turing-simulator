// <copyright file="TuringLogic.cpp" company="Privat">
//   Copyright (c) Sascha Schwegelbauer. All rights reserved.
// </copyright>

#include "StdAfx.h"
#include "TuringLogic.h"
#include "TuringCommandList.h"

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Core
		{
			namespace CppShared = TuringSimulator::CPP::Shared;

			void TuringLogic::InitializeFromFile(System::String ^ filename, System::String ^ inputString)
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
				this->RaiseLogReceived(String::Format("Pre-Step : State: {0,3} | Pos: {1,3} | char: {2}      | nMov: {3} | Tape: {4}", this->currentState, this->TapeheadPosition, this->CurrentTapeChar, this->nextMove, this->Tape->Length < 50 ? gcnew String(this->Tape) : "Tape zu lang (> 50)"));
				
				switch ( this->nextMove )
				{						
					case CppShared::MovementValues::S:
						this->terminated = true;
						this->ready = false;
						this->RaiseLogReceived("Keine Ausführung - Zustand STOP!");
						return false;
					case CppShared::MovementValues::N:
						break;
					case CppShared::MovementValues::R:
						this->tapeheadPosition++;
						break;
					case CppShared::MovementValues::L:
						this->tapeheadPosition--;
						break;
					case CppShared::MovementValues::Undefined:
						break;
					default:
						throw gcnew ArgumentOutOfRangeException();
				}

				wchar_t tempChar = this->CurrentTapeChar;
				this->currentCommandIndex = this->CommandList->GetCommandIndex(this->currentState, tempChar);
				if ( !this->CurrentCommandIndex.HasValue )
					throw gcnew Exception("Gefordertes Kommando nicht in Liste gefunden!");

				System::Diagnostics::Debug::WriteLine(System::String::Format("Hole Kommando mit Index {0} aus Liste...", this->CurrentCommandIndex));
				CppShared::ITuringCommand ^ command = this->CommandList[this->CurrentCommandIndex.Value];
				this->currentState = command->Z1;

				// Zeichen auf Tape ggfls. ersetzen lt. Anweisung
				if ( command->SZ != '#' && command->SZ != '$' )
					this->Tape[this->TapeheadPosition] = command->SZ;
				
				this->nextMove = command->MOV;
				this->RaiseLogReceived(String::Format("Post-Step: State: {0,3} | Pos: {1,3} | char: {2} -> {3} |  Mov: {4} | Tape: {5}", this->currentState, this->TapeheadPosition, tempChar, this->CurrentTapeChar, command->MOV, this->Tape->Length < 50 ? gcnew String(this->Tape) : "Tape zu lang (> 50)"));
				this->RaiseAfterStateChanged();

				return true;			
			}

			void TuringLogic::Initialize(CppShared::ITuringCommandList ^ turingCommandList, System::String ^ inputString)
			{
				this->Reset(true);
				this->CommandList = turingCommandList;
				this->tape = inputString->ToCharArray();
				this->ready = true;

				this->RaiseAfterStateChanged();
			}
			
			void TuringLogic::Reset(void)
			{
				this->Reset(false);
			}

			/// Prüft bzw. ruft den EventHandler für AfterStateChanged auf
			/// 2015-01-06 SaS: Sollte an sich auch ohne den nullptr-check funktionieren, nur lässt sich das (nach meinem aktuellen C++/CLI - Wissen) nicht mit der Definition des Events im Interface vereinbaren
			void TuringLogic::RaiseAfterStateChanged()
			{
				if ( this->afterStateChanged != nullptr )
					this->afterStateChanged->Invoke(this, System::EventArgs::Empty);
			}

			void TuringLogic::RaiseLogReceived(System::String ^ logMessage)
			{
				Debug::WriteLine(logMessage);

				if ( this->logReceived != nullptr )
					this->logReceived->Invoke(logMessage);
			}

			void TuringLogic::Reset(bool skipAfterStateChanged)
			{
				this->currentCommandIndex = System::Nullable<System::Int32>();
				this->nextMove = CppShared::MovementValues::Undefined;
				this->currentState = 0;
				this->tapeheadPosition = 0;
				this->terminated = false;
				this->tape = nullptr;
				this->nextMove = CppShared::MovementValues::Undefined;
				this->ready = false;

				if ( !skipAfterStateChanged )
					this->RaiseAfterStateChanged();
			}
		}
	}
}