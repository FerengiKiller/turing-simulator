// <copyright file="TuringCommand.cpp" company="Privat">
//   Copyright (c) Sascha Schwegelbauer. All rights reserved.
// </copyright>

#include "StdAfx.h"
#include "TuringCommand.h"

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Core
		{
			using namespace System;
			using namespace System::Text::RegularExpressions;
			namespace CppShared = TuringSimulator::CPP::Shared;

			TuringCommand::TuringCommand(System::String^ rawData)
			{
				this->Initialize(rawData);
			}

			void TuringCommand::Initialize(System::String ^ rawData)
			{
				Match^ regEx = Regex::Match(rawData, TuringSimulator::CPP::Shared::Generic::CommandParseRegex, RegexOptions::IgnoreCase | RegexOptions::IgnorePatternWhitespace);
				if ( !regEx->Success )
					throw gcnew FormatException("Kommandozeichenfolge konnte nicht gelesen werden: " + rawData);
				
				this->Z0 = Int32::Parse(regEx->Groups["Z0"]->Value);
				this->GZ = Convert::ToChar(regEx->Groups["GZ"]->Value);
				this->Z1 = Int32::Parse(regEx->Groups["Z1"]->Value);
				this->SZ = Convert::ToChar(regEx->Groups["SZ"]->Value);
				this->MOV = safe_cast<CppShared::MovementValues>(Enum::Parse(CppShared::MovementValues::typeid, regEx->Groups["MOV"]->Value));
				this->Raw = rawData;
			}
		}
	}
}