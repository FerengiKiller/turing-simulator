#include "StdAfx.h"
#include "TuringCommand.h"

using namespace System;
using namespace System::Text::RegularExpressions;
namespace CsShared = TuringSimulator::CS::Shared;

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Core
		{
			TuringCommand::TuringCommand(System::String^ rawLine)
			{

				Match^ regEx = Regex::Match(rawLine, CsShared::Generic::TuringCommandParse, RegexOptions::IgnoreCase | RegexOptions::IgnorePatternWhitespace);
			if ( !regEx->Success )
				throw gcnew FormatException("Kommandozeichenfolge konnte nicht gelesen werden.");

			this->Z0 = Int32::Parse(regEx->Groups["Z0"]->Value);
			this->GZ = Convert::ToChar(regEx->Groups["GZ"]->Value);
			this->Z1 = Int32::Parse(regEx->Groups["Z1"]->Value);
			this->SZ = Convert::ToChar(regEx->Groups["SZ"]->Value);
			this->MOV = safe_cast<CsShared::MovementValues>(Enum::Parse(CsShared::MovementValues::typeid, regEx->Groups["MOV"]->Value));
			}
		}
	}
}