/// Implementierung der Turing-Logik
/// Einschränkungen:
/// * Das Speicherband (TuringLogic->Tape) ist nicht unendlich lang in beide Richtungen

#pragma once
namespace CsShared = TuringSimulator::CS::Shared;

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Core
		{
			public ref class TuringLogic : public CsShared::ITuringLogic
			{
			private:
				CsShared::ITuringCommandList^ commandList;
				cli::array<wchar_t>^ tape;
				int tapePosition;
				CsShared::MovementValues nextMove;
				bool terminated;
				
			public:
				TuringLogic(void);

				virtual property CsShared::ITuringCommandList^ CommandList
				{
					CsShared::ITuringCommandList^ get() { return this->commandList; };

				private: 
					void set(CsShared::ITuringCommandList^ value) { this->commandList = value; };
				}

				virtual property cli::array<wchar_t>^ Tape
				{
					cli::array<wchar_t>^ get() { return this->tape; }
				}

				virtual	property int TapePosition
				{
					int get() { return this->tapePosition; }
				}

				virtual property CsShared::MovementValues NextMove
				{
					CsShared::MovementValues get() { return this->nextMove; };
				}

				virtual property wchar_t CurrentTapeChar
				{
					wchar_t get() { return this->Tape[this->TapePosition]; };
				}

				virtual property bool Terminated
				{
					bool get() { return this->terminated; }
				}

				virtual void Initialize(CsShared::ITuringCommandList ^ turingCommandList, System::String ^ inputString);

				virtual void Start();

				virtual bool Step();

				virtual void Reset();
			};
		}
	}
}