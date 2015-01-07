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
				
			public:
				virtual event EventHandler ^ AfterStateChanged
				{
					void add(EventHandler ^ handler) { this->afterStateChanged += handler; }
					void remove(EventHandler ^ handler) { this->afterStateChanged -= handler; }
				}

				virtual property CppShared::ITuringCommandList^ CommandList
				{
					CppShared::ITuringCommandList^ get() { return this->commandList; };

				private: 
					void set(CppShared::ITuringCommandList^ value) { this->commandList = value; };
				}

				virtual property cli::array<wchar_t>^ Tape
				{
					cli::array<wchar_t>^ get() { return this->tape; }
				}

				virtual	property int TapePosition
				{
					int get() { return this->tapePosition; }
				}

				virtual property CppShared::MovementValues NextMove
				{
					CppShared::MovementValues get() { return this->nextMove; };
				}

				virtual property wchar_t CurrentTapeChar
				{
					wchar_t get() { return this->Tape[this->TapePosition]; };
				}

				virtual property bool Terminated
				{
					bool get() { return this->terminated; }
				}

				virtual property bool Ready
				{
					bool get() { return this->ready; }
				}

				virtual void Initialize(CppShared::ITuringCommandList ^ turingCommandList, System::String ^ inputString);

				virtual void Load(System::String ^ filename, System::String ^ inputString);

				virtual void Start();

				virtual bool Step();

				virtual void Reset();
			};
		}
	}
}