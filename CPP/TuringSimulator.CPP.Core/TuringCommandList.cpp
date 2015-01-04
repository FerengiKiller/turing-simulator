#include "StdAfx.h"
#include "TuringCommandList.h"

TuringCommandList::TuringCommandList(void)
{
}

void TuringCommandList::LoadFromFile(System::String ^filename)
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

CsShared::ITuringCommand^ TuringCommandList::SelectCommand(int state, wchar_t input)
{
	throw gcnew NotImplementedException();
}