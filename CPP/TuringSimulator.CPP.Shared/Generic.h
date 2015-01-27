#pragma once
namespace TuringSimulator
{
	namespace CPP
	{
		namespace Shared
		{
			public ref class Generic
			{
			public:
//				static System::String ^ CommandParseRegex = "(?<Z0>\d*),(?<GZ>0|1|\#)\->(?<Z1>\d*),(?<SZ>0|1|\#),(?<MOV>L|R|S)";

				static property System::String ^ CommandParseRegex
				{
					System::String ^ get()
					{
						Resources::ResourceManager^ rm = gcnew Resources::ResourceManager(L"TuringSimulatorCPPShared.GenericResources", System::Reflection::Assembly::GetExecutingAssembly());
						System::String ^ s = rm->GetString(L"TuringCommandParse");
						return s;
					}
				}
			};
		}
	}
}