#pragma once


namespace TuringSimulatorCPPGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>Hauptformular der GUI </summary>
	public ref class FormMain : public System::Windows::Forms::Form
	{
	public:
		FormMain(void)
		{
			InitializeComponent();

			this->logic = gcnew TuringSimulator::CPP::Core::TuringLogic();
			this->logic->AfterStateChanged += gcnew System::EventHandler(this, &FormMain::afterStateChangedHandler);
		}

		virtual property TuringSimulator::CPP::Shared::ITuringLogic ^ Logic
		{
			TuringSimulator::CPP::Shared::ITuringLogic ^ get() { return this->logic; }
		}

	protected:
		~FormMain()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>Event-Handler um den aktuellen Status der TuringLogic in der GUI zu reflektieren</summary>
		/// <remarks>TODO SaS 2015-01-27: per Gelegenheit Migration auf DataBindings prüfen</remarks>
		void afterStateChangedHandler(System::Object^  sender, System::EventArgs^  e)
		{
			this->statusStrip1->Text = "!";
			this->tbTapePosition->Text = Convert::ToString(this->Logic->TapePosition);
			this->tbCurrentTapeChar->Text = Convert::ToString(this->Logic->CurrentTapeChar);
			this->tbNextMove->Text = Convert::ToString(this->Logic->NextMove);

			this->btnStart->Enabled = this->Logic->Ready;
			this->btnStep->Enabled = this->Logic->Ready;

			this->lbCommandListContent->Items->Clear();
			if ( this->Logic->Ready )
			{
				for each ( TuringSimulator::CPP::Shared::ITuringCommand ^ command in this->Logic->CommandList )
				{
					this->lbCommandListContent->Items->Add(command->ToString());
				}
			}
		}

		TuringSimulator::CPP::Shared::ITuringLogic ^ logic;
		System::Windows::Forms::Label^  lblTapePosition;
		System::Windows::Forms::TextBox^  tbTapePosition;
		System::Windows::Forms::Button^  btnStart;
		System::Windows::Forms::Button^  btnStep;
		System::Windows::Forms::Button^  btnReset;
		System::Windows::Forms::TextBox^  tbTape;
		System::Windows::Forms::StatusStrip^  statusStrip1;
		System::Windows::Forms::MenuStrip^  menuStrip1;
		System::Windows::Forms::ToolStripMenuItem^  dateiToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^  tsmiOpen;
		System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
		System::Windows::Forms::ToolStripMenuItem^  beendenToolStripMenuItem;
		System::Windows::Forms::Label^  lblTape;
	private: System::Windows::Forms::ListBox^  lbCommandListContent;
	private: System::Windows::Forms::TextBox^  tbFilename;
	private: System::Windows::Forms::Button^  btnSelectAndLoad;
	private: System::Windows::Forms::Button^  btnLoadFile;
	private: System::Windows::Forms::TextBox^  tbCurrentTapeChar;
	private: System::Windows::Forms::Label^  lblCurrentTapeChar;
	private: System::Windows::Forms::TextBox^  tbNextMove;
	private: System::Windows::Forms::Label^  lblNextMove;



		/// <summary>Required designer variable.</summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnStep = (gcnew System::Windows::Forms::Button());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->tbTape = (gcnew System::Windows::Forms::TextBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->dateiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmiOpen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->beendenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblTape = (gcnew System::Windows::Forms::Label());
			this->lblTapePosition = (gcnew System::Windows::Forms::Label());
			this->tbTapePosition = (gcnew System::Windows::Forms::TextBox());
			this->lbCommandListContent = (gcnew System::Windows::Forms::ListBox());
			this->tbFilename = (gcnew System::Windows::Forms::TextBox());
			this->btnSelectAndLoad = (gcnew System::Windows::Forms::Button());
			this->btnLoadFile = (gcnew System::Windows::Forms::Button());
			this->tbCurrentTapeChar = (gcnew System::Windows::Forms::TextBox());
			this->lblCurrentTapeChar = (gcnew System::Windows::Forms::Label());
			this->tbNextMove = (gcnew System::Windows::Forms::TextBox());
			this->lblNextMove = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(12, 105);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(75, 23);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &FormMain::btnStart_Click);
			// 
			// btnStep
			// 
			this->btnStep->Location = System::Drawing::Point(93, 105);
			this->btnStep->Name = L"btnStep";
			this->btnStep->Size = System::Drawing::Size(75, 23);
			this->btnStep->TabIndex = 1;
			this->btnStep->Text = L"Step";
			this->btnStep->UseVisualStyleBackColor = true;
			this->btnStep->Click += gcnew System::EventHandler(this, &FormMain::btnStep_Click);
			// 
			// btnReset
			// 
			this->btnReset->Location = System::Drawing::Point(174, 105);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(75, 23);
			this->btnReset->TabIndex = 2;
			this->btnReset->Text = L"Reset";
			this->btnReset->UseVisualStyleBackColor = true;
			this->btnReset->Click += gcnew System::EventHandler(this, &FormMain::btnReset_Click);
			// 
			// tbTape
			// 
			this->tbTape->Location = System::Drawing::Point(12, 167);
			this->tbTape->Name = L"tbTape";
			this->tbTape->Size = System::Drawing::Size(254, 20);
			this->tbTape->TabIndex = 3;
			this->tbTape->Text = L"0110#";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 412);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(830, 22);
			this->statusStrip1->TabIndex = 4;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->dateiToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(830, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// dateiToolStripMenuItem
			// 
			this->dateiToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->tsmiOpen, 
				this->toolStripMenuItem2, this->beendenToolStripMenuItem});
			this->dateiToolStripMenuItem->Name = L"dateiToolStripMenuItem";
			this->dateiToolStripMenuItem->Size = System::Drawing::Size(46, 20);
			this->dateiToolStripMenuItem->Text = L"Datei";
			// 
			// tsmiOpen
			// 
			this->tsmiOpen->Name = L"tsmiOpen";
			this->tsmiOpen->Size = System::Drawing::Size(120, 22);
			this->tsmiOpen->Text = L"Öffnen...";
			this->tsmiOpen->Click += gcnew System::EventHandler(this, &FormMain::tsmiOpen_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(117, 6);
			// 
			// beendenToolStripMenuItem
			// 
			this->beendenToolStripMenuItem->Name = L"beendenToolStripMenuItem";
			this->beendenToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->beendenToolStripMenuItem->Text = L"Beenden";
			// 
			// lblTape
			// 
			this->lblTape->AutoSize = true;
			this->lblTape->Location = System::Drawing::Point(9, 151);
			this->lblTape->Name = L"lblTape";
			this->lblTape->Size = System::Drawing::Size(32, 13);
			this->lblTape->TabIndex = 6;
			this->lblTape->Text = L"Band";
			// 
			// lblTapePosition
			// 
			this->lblTapePosition->AutoSize = true;
			this->lblTapePosition->Location = System::Drawing::Point(269, 151);
			this->lblTapePosition->Name = L"lblTapePosition";
			this->lblTapePosition->Size = System::Drawing::Size(44, 13);
			this->lblTapePosition->TabIndex = 7;
			this->lblTapePosition->Text = L"Position";
			// 
			// tbTapePosition
			// 
			this->tbTapePosition->Location = System::Drawing::Point(272, 167);
			this->tbTapePosition->Name = L"tbTapePosition";
			this->tbTapePosition->ReadOnly = true;
			this->tbTapePosition->Size = System::Drawing::Size(44, 20);
			this->tbTapePosition->TabIndex = 8;
			// 
			// lbCommandListContent
			// 
			this->lbCommandListContent->FormattingEnabled = true;
			this->lbCommandListContent->Location = System::Drawing::Point(491, 105);
			this->lbCommandListContent->Name = L"lbCommandListContent";
			this->lbCommandListContent->Size = System::Drawing::Size(327, 290);
			this->lbCommandListContent->TabIndex = 10;
			// 
			// tbFilename
			// 
			this->tbFilename->Location = System::Drawing::Point(12, 64);
			this->tbFilename->Name = L"tbFilename";
			this->tbFilename->Size = System::Drawing::Size(433, 20);
			this->tbFilename->TabIndex = 11;
			this->tbFilename->TextChanged += gcnew System::EventHandler(this, &FormMain::tbFilename_TextChanged);
			// 
			// btnSelectAndLoad
			// 
			this->btnSelectAndLoad->Location = System::Drawing::Point(451, 62);
			this->btnSelectAndLoad->Name = L"btnSelectAndLoad";
			this->btnSelectAndLoad->Size = System::Drawing::Size(34, 23);
			this->btnSelectAndLoad->TabIndex = 12;
			this->btnSelectAndLoad->Text = L"...";
			this->btnSelectAndLoad->UseVisualStyleBackColor = true;
			this->btnSelectAndLoad->Click += gcnew System::EventHandler(this, &FormMain::btnSelectAndLoad_Click);
			// 
			// btnLoadFile
			// 
			this->btnLoadFile->Enabled = false;
			this->btnLoadFile->Location = System::Drawing::Point(491, 62);
			this->btnLoadFile->Name = L"btnLoadFile";
			this->btnLoadFile->Size = System::Drawing::Size(75, 23);
			this->btnLoadFile->TabIndex = 13;
			this->btnLoadFile->Text = L"Laden";
			this->btnLoadFile->UseVisualStyleBackColor = true;
			this->btnLoadFile->Click += gcnew System::EventHandler(this, &FormMain::btnLoadFile_Click);
			// 
			// tbCurrentTapeChar
			// 
			this->tbCurrentTapeChar->Location = System::Drawing::Point(216, 261);
			this->tbCurrentTapeChar->Name = L"tbCurrentTapeChar";
			this->tbCurrentTapeChar->ReadOnly = true;
			this->tbCurrentTapeChar->Size = System::Drawing::Size(100, 20);
			this->tbCurrentTapeChar->TabIndex = 14;
			// 
			// lblCurrentTapeChar
			// 
			this->lblCurrentTapeChar->AutoSize = true;
			this->lblCurrentTapeChar->Location = System::Drawing::Point(216, 242);
			this->lblCurrentTapeChar->Name = L"lblCurrentTapeChar";
			this->lblCurrentTapeChar->Size = System::Drawing::Size(88, 13);
			this->lblCurrentTapeChar->TabIndex = 15;
			this->lblCurrentTapeChar->Text = L"CurrentTapeChar";
			// 
			// tbNextMove
			// 
			this->tbNextMove->Location = System::Drawing::Point(216, 339);
			this->tbNextMove->Name = L"tbNextMove";
			this->tbNextMove->ReadOnly = true;
			this->tbNextMove->Size = System::Drawing::Size(100, 20);
			this->tbNextMove->TabIndex = 16;
			// 
			// lblNextMove
			// 
			this->lblNextMove->AutoSize = true;
			this->lblNextMove->Location = System::Drawing::Point(216, 320);
			this->lblNextMove->Name = L"lblNextMove";
			this->lblNextMove->Size = System::Drawing::Size(56, 13);
			this->lblNextMove->TabIndex = 17;
			this->lblNextMove->Text = L"NextMove";
			// 
			// FormMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(830, 434);
			this->Controls->Add(this->lblNextMove);
			this->Controls->Add(this->tbNextMove);
			this->Controls->Add(this->lblCurrentTapeChar);
			this->Controls->Add(this->tbCurrentTapeChar);
			this->Controls->Add(this->btnLoadFile);
			this->Controls->Add(this->btnSelectAndLoad);
			this->Controls->Add(this->tbFilename);
			this->Controls->Add(this->lbCommandListContent);
			this->Controls->Add(this->tbTapePosition);
			this->Controls->Add(this->lblTapePosition);
			this->Controls->Add(this->lblTape);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->tbTape);
			this->Controls->Add(this->btnReset);
			this->Controls->Add(this->btnStep);
			this->Controls->Add(this->btnStart);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"FormMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Turing Simulator";
			this->Shown += gcnew System::EventHandler(this, &FormMain::FormMain_Shown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->Logic->Start();
		}
		
		System::Void btnStep_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->Logic->Step();
		}
		
		System::Void btnReset_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->Logic->Reset();
		}
		
		System::Void tsmiOpen_Click(System::Object^  sender, System::EventArgs^  e)
		{
			OpenFileDialog^ dialog = gcnew OpenFileDialog();
            dialog->Filter = "Turing-Programme|*.tur|Alle Dateien|*.*";
            if( dialog->ShowDialog() != System::Windows::Forms::DialogResult::OK )
            {
                return;
            }

			this->tbFilename->Text = dialog->FileName;
			this->Logic->Load(this->tbFilename->Text, this->tbTape->Text);
		}

		System::Void FormMain_Shown(System::Object^  sender, System::EventArgs^  e)
		{
			this->Logic->Reset();
		}
		
		System::Void tbFilename_TextChanged(System::Object^  sender, System::EventArgs^  e)
		{
			bool temp = ( !System::String::IsNullOrEmpty(tbFilename->Text) && System::IO::File::Exists(tbFilename->Text) );
			this->btnLoadFile->Enabled = temp;
		}
		
		System::Void btnLoadFile_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->Logic->Load(this->tbFilename->Text, this->tbTape->Text);
		}
		
		System::Void btnSelectAndLoad_Click(System::Object^  sender, System::EventArgs^  e)
		{
			OpenFileDialog^ dialog = gcnew OpenFileDialog();
            dialog->Filter = "Turing-Programme|*.tur|Alle Dateien|*.*";
            if( dialog->ShowDialog() != System::Windows::Forms::DialogResult::OK )
            {
                return;
            }

			this->tbFilename->Text = dialog->FileName;
			this->Logic->Load(this->tbFilename->Text, this->tbTape->Text);
		}
};
}