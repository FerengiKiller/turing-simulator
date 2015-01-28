// <copyright file="TuringSimulator.CPP.GUI.cpp" company="Privat">
//   Copyright (c) Sascha Schwegelbauer. All rights reserved.
// </copyright>

#include "stdafx.h"
#include "FormMain.h"

using namespace TuringSimulatorCPPGUI;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew FormMain());
	return 0;
}
