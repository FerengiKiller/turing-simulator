#pragma once

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Core
		{
			public ref class TuringCommand : public TuringSimulator::CS::Shared::ITuringCommand
			{
			private:
				System::Int32 line;
				System::Int32 z0;
				wchar_t gz;
				System::Int32 z1;
				wchar_t sz;
				TuringSimulator::CS::Shared::MovementValues mov;

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

				virtual property TuringSimulator::CS::Shared::MovementValues MOV
				{
					TuringSimulator::CS::Shared::MovementValues get() { return this->mov; };
					void set(TuringSimulator::CS::Shared::MovementValues value) { this->mov = value; };
				}
			};
		}
	}
}