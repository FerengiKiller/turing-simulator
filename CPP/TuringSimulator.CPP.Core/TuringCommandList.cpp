#include "StdAfx.h"
#include "TuringCommandList.h"



TuringSimulator::CPP::Core::TuringCommandList::TuringCommandList(void)
{
}

void TuringSimulator::CPP::Core::TuringCommandList::LoadFromFile(System::String ^filename)
{
	this->Clear();
	
	try
	{
		array<String^>^ lines = System::IO::File::ReadAllLines(filename);
		for each ( String^ line in lines )
		{
			TuringCommand^ newCommand = gcnew TuringCommand(line);
			this->Add(newCommand);
		}
	}
	catch ( Exception^ )
	{
		this->Clear();
		throw;
	}
}

CsShared::ITuringCommand^ TuringSimulator::CPP::Core::TuringCommandList::SelectCommand(int state, wchar_t input)
{
	for each ( CsShared::ITuringCommand ^ command in this )
	{
		if ( command->Z0 == state && command->GZ == input )
			return command;
	}

	return nullptr;
}