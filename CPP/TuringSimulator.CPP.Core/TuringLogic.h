/// Implementierung der Turing-Logik
/// Einschränkungen:
/// * Das Speicherband (TuringLogic->Tape) ist nicht unendlich lang in beide Richtungen

#pragma once
using namespace System;
using namespace System::Diagnostics;
namespace CppShared = TuringSimulator::CPP::Shared;

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Core
		{
			public ref class TuringLogic : public CppShared::ITuringLogic
			{
			private:
				CppShared::ITuringCommandList^ commandList;
				cli::array<wchar_t>^ tape;
				int tapePosition;
				CppShared::MovementValues nextMove;
				bool terminated;
				bool ready;
				int currentState; // MZ - Maschinenzustand
				EventHandler ^ afterStateChanged;
				void RaiseAfterStateChanged();
				int currentCommandIndex;
				CppShared::ITuringCommand ^ currentCommand;
				
			public:
				/// <summary></summary>
				virtual event EventHandler ^ AfterStateChanged
				{
					void add(EventHandler ^ handler) { this->afterStateChanged += handler; }
					void remove(EventHandler ^ handler) { this->afterStateChanged -= handler; }
				}

				/// <summary></summary>
				virtual property CppShared::ITuringCommandList^ CommandList
				{
					CppShared::ITuringCommandList^ get() { return this->commandList; };
	
				private: 
					void set(CppShared::ITuringCommandList^ value) { this->commandList = value; };
				}

				/// <summary></summary>
				virtual property cli::array<wchar_t>^ Tape
				{
					cli::array<wchar_t>^ get() { return this->tape; }
				}

				/// <summary></summary>
				virtual	property int TapePosition
				{
					int get() { return this->tapePosition; }
				}

				/// <summary></summary>
				virtual property CppShared::MovementValues NextMove
				{
					CppShared::MovementValues get() { return this->nextMove; };
				}

				/// <summary></summary>
				virtual property wchar_t CurrentTapeChar
				{
					wchar_t get() { return this->Tape == nullptr ? '?' : this->Tape[this->TapePosition]; };
				}

				/// <summary></summary>
				virtual property bool Terminated
				{
					bool get() { return this->terminated; }
				}

				/// <summary></summary>
				virtual property bool Ready
				{
					bool get() { return this->ready; }
				}

				virtual property int CurrentCommandIndex
				{
					int get() { return this->currentCommandIndex; }
				}

				virtual property CppShared::ITuringCommand ^ CurrentCommand
				{
					CppShared::ITuringCommand ^ get() { return this->currentCommand; }
				}

				/// <summary></summary>
				virtual void Initialize(CppShared::ITuringCommandList ^ turingCommandList, System::String ^ inputString);

				/// <summary></summary>
				virtual void Load(System::String ^ filename, System::String ^ inputString);

				/// <summary>Wiederholt 'Step' solange wie 'true' zurückgegeben wird</summary>
				virtual void Start();

				/// <summary>Führt den nächsten TuringCommand aus.</summary>
				/// <returns>Gibt true zurück, wenn ein weiterer Step ausgeführt werden kann.</returns>
				///	<seealso cref="Start()">Verwende Start() um die TuringLogic</seealso>
				virtual bool Step();

				/// <summary>Setzt den Zustand der TuringLogic auf Initialwerte zurück.</summary>
				virtual void Reset();
			};
		}
	}
}