#pragma once

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Core
		{
			/// <summary>Implementiert ITuringCommand</summary>
			/// <remarks>
			/// </remarks>
			public ref class TuringCommand : public TuringSimulator::CPP::Shared::ITuringCommand
			{
			private:
				System::Int32 line;
				System::Int32 z0;
				wchar_t gz;
				System::Int32 z1;
				wchar_t sz;
				TuringSimulator::CPP::Shared::MovementValues mov;
				System::String ^ raw;

			public:
				TuringCommand(System::String^ rawLine);

				virtual property System::Int32 Line
				{
					System::Int32 get() { return this->line; };
					void set(System::Int32 value) { this->line = value; };
				}
				
				virtual property System::Int32 Z0
				{
					System::Int32 get() { return this->z0; };
					void set(System::Int32 value) { this->z0 = value; };
				}
				
				virtual property wchar_t GZ
				{
					wchar_t get() { return this->gz; };
					void set(wchar_t value) { this->gz = value; };
				}
				
				virtual property System::Int32 Z1
				{
					System::Int32 get() { return this->z1; };
					void set(System::Int32 value) { this->z1 = value; };
				}

				virtual property wchar_t SZ
				{
					wchar_t get() { return this->sz; };
					void set(wchar_t value) { this->sz = value; };
				}

				virtual property System::String ^ Raw
				{
					System::String ^ get() { return this->raw; };

				private:
					void set(System::String ^ value) { this->raw = value; };
				}

				virtual property TuringSimulator::CPP::Shared::MovementValues MOV
				{
					TuringSimulator::CPP::Shared::MovementValues get() { return this->mov; };
					void set(TuringSimulator::CPP::Shared::MovementValues value) { this->mov = value; };
				}
				
				virtual System::String^ TuringCommand::ToString() override
				{
					return System::String::Format("{0}", this->Raw);
				}
			};
		}
	}
}