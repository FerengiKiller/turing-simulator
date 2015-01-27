Turing Simulator
(C) 2014 Sascha Schwegelbauer (sas@dotnetfabrik.de)

Documentation available in english language on request, just drop me an email.

/* ----------------------------------------------------------------------------
 *  "THE BEER-WARE LICENSE" (Revision 42):
 *  Sascha Schwegelbauer<sas@dotnetfabrik.de> wrote this file.
 *  As long as you retain this notice you can do whatever you want 
 *  with this stuff. If we meet some day, and you think this stuff is worth it, 
 *  you can buy me a beer in return. Sascha Schwegelbauer
 *  Excluded are all persons related to my IS/BI studies at WINGS Wismar.
 * ---------------------------------------------------------------------------- */

1 Um was geht es?
  ===============

TuringSimulator ist eine in .NET (bzw. C++/CLI und C#) implementierte Umgebung um "Turing-Programme" (vgl. http://de.wikipedia.org/wiki/Turingmaschine) zu testen / auszuführen.

2 Schnellstart
  ============

Einfach benutzen: direkt TuringSimulator.CPP.GUI.exe starten und loslegen
Selber programmieren:
  a) eine Instanz von TuringSimulator.CPP.Core.TuringLogic oder TuringSimulator.CS.Core.TuringLogic erzeugen und benutzen.
  b) am besten den Code der Unit-Tests zur Verdeutlichung der Nutzung anschauen.
  
3 Projektstruktur
  ===============

Das Projekt ist grundlegend in C++/CLI (Namespace TuringSimulator.CPP.*) entwickelt.
Es existieren für jede ablaufrelevante Klasse Interfaces, welche sowohl von C++/CLI als auch von C# (TuringSimulator.CS.*) implementiert werden.
Es existieren in C# geschriebene, automatisierte Tests für die grundlegenden Funktionen.
Die Tests decken sowohl die C++/CLI als auch die C# - Implementierung ab.

3.1 Dateiformat für TuringCommandList bzw. TuringCommand
    ====================================================

  - Textdatei
  - eine Zeile je Turing-Kommando
  - Aufbau gemäß Projektspezifikation

3.2 Inhalt der Solution
    ===================

* TuringSimulator.CPP.Shared
  --------------------------

  Beinhaltet die Definition die von C++/CLI bzw. C# und den Tests verwendeten Interfaces und Enums.


* TuringSimulator.CPP.GUI
  -----------------------

  Auf Basis von WinForms entwickelte grafische Oberfläche, welche eine Instanz von TuringLogic erzeugt und den Benutzer interagieren lässt.

* TuringSimulator.CPP.Core
  ------------------------

  Implementierung der in CPP.Shared definierten Interfaces und damit der eigentlichen Touring-Logik in C++/CLI.



* TuringSimulator.CS.Core
  -----------------------

  C# - Portierung von TuringSimulator.CPP.Core um die Möglichkeit der sprachübergreifenden Implementierung in .NET zu demonstrieren.

* TuringSimulator.Tests
  ---------------------

  UnitTests (per NUnit, z.B. ReSharper verwenden um Tests komfortabel ausführen zu können)
  

3.3 Funktionsrelevante Klassen
    ==========================

3.3.1 TuringLogic
Beinhaltet Programmcode zur Turing-konformen Abarbeitung der in TuringLogic.CommandList geladenen Kommandos.

3.3.2 TuringCommandList
Liste aus ITuringCommand's (List<CppShared::ITuringCommand^>) um eine Datei mit mehreren Turing-Kommandos von einem Datenträger zu lesen und z.B. für TuringLogik zur Verfügung zu stellen

3.3.3 TuringCommand
Programmcode, um ein einzelnes Turing-Kommando logisch darzustellen bzw. aus einem String zu laden.