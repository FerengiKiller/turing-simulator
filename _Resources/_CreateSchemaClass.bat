rem Immer per VS Command Prompt starten, sonst liegt xsd.exe nicht im PATH (normalerweise im Windows SDK)

@ECHO Generiere Schema
xsd "3bit Addition.xml"

xsd /d /language:cs "3bit Addition.xsd" /eld /n:TuringSimulator