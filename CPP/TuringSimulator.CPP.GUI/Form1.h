#pragma once


namespace TuringSimulatorCPPGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			this->logic = gcnew TuringSimulator::CPP::Core::TuringLogic();
			this->logic->AfterStateChanged += gcnew System::EventHandler(this, &Form1::afterStateChangedHandler);
			//
			//TODO: Add the constructor code here
			//
		}

		virtual property TuringSimulator::CPP::Shared::ITuringLogic ^ Logic
		{
			TuringSimulator::CPP::Shared::ITuringLogic ^ get() { return this->logic; }
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblTapePosition;
	private: System::Windows::Forms::TextBox^  tbTapePosition;
	protected: 

	private:
		TuringSimulator::CPP::Shared::ITuringLogic ^ logic;

		void afterStateChangedHandler(System::Object^  sender, System::EventArgs^  e)
		{
			this->statusStrip1->Text = "!";
			this->tbTapePosition->Text = Convert::ToString(this->Logic->TapePosition);
			this->btnStart->Enabled = this->Logic->Ready;
			this->btnStep->Enabled = this->Logic->Ready;
		}

	private: System::Windows::Forms::Button^  btnStart;
	protected: 
	private: System::Windows::Forms::Button^  btnStep;
	private: System::Windows::Forms::Button^  btnReset;
	private: System::Windows::Forms::TextBox^  tbTape;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  dateiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmiOpen;

	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  beendenToolStripMenuItem;
	private: System::Windows::Forms::Label^  lblTape;

	private:
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
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(30, 51);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(75, 23);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &Form1::btnStart_Click);
			// 
			// btnStep
			// 
			this->btnStep->Location = System::Drawing::Point(111, 51);
			this->btnStep->Name = L"btnStep";
			this->btnStep->Size = System::Drawing::Size(75, 23);
			this->btnStep->TabIndex = 1;
			this->btnStep->Text = L"Step";
			this->btnStep->UseVisualStyleBackColor = true;
			this->btnStep->Click += gcnew System::EventHandler(this, &Form1::btnStep_Click);
			// 
			// btnReset
			// 
			this->btnReset->Location = System::Drawing::Point(192, 51);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(75, 23);
			this->btnReset->TabIndex = 2;
			this->btnReset->Text = L"Reset";
			this->btnReset->UseVisualStyleBackColor = true;
			this->btnReset->Click += gcnew System::EventHandler(this, &Form1::btnReset_Click);
			// 
			// tbTape
			// 
			this->tbTape->Location = System::Drawing::Point(30, 133);
			this->tbTape->Name = L"tbTape";
			this->tbTape->Size = System::Drawing::Size(254, 20);
			this->tbTape->TabIndex = 3;
			this->tbTape->Text = L"0110#";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 239);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(528, 22);
			this->statusStrip1->TabIndex = 4;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->dateiToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(528, 24);
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
			this->tsmiOpen->Click += gcnew System::EventHandler(this, &Form1::tsmiOpen_Click);
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
			this->lblTape->Location = System::Drawing::Point(30, 114);
			this->lblTape->Name = L"lblTape";
			this->lblTape->Size = System::Drawing::Size(32, 13);
			this->lblTape->TabIndex = 6;
			this->lblTape->Text = L"Band";
			// 
			// lblTapePosition
			// 
			this->lblTapePosition->AutoSize = true;
			this->lblTapePosition->Location = System::Drawing::Point(30, 160);
			this->lblTapePosition->Name = L"lblTapePosition";
			this->lblTapePosition->Size = System::Drawing::Size(44, 13);
			this->lblTapePosition->TabIndex = 7;
			this->lblTapePosition->Text = L"Position";
			// 
			// tbTapePosition
			// 
			this->tbTapePosition->Location = System::Drawing::Point(30, 177);
			this->tbTapePosition->Name = L"tbTapePosition";
			this->tbTapePosition->ReadOnly = true;
			this->tbTapePosition->Size = System::Drawing::Size(44, 20);
			this->tbTapePosition->TabIndex = 8;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(528, 261);
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
			this->Name = L"Form1";
			this->Text = L"Turing Simulator";
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

			this->Logic->Load(dialog->FileName, this->tbTape->Text);
		}
};
}