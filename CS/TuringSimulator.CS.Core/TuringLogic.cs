namespace TuringSimulator.CS.Core
{
	using System;
	using System.Collections.Generic;
	using System.Diagnostics;
	using System.Linq;
	using System.Text;
	using TuringSimulator.CPP.Shared;

	public class TuringLogic : TuringSimulator.CPP.Shared.ITuringLogic
	{
		private int tapePosition;

		private int currentState; // MZ - Maschinenzustand

		private MovementValues nextMove;

		public TuringLogic()
		{
			this.Reset();
		}

		public event EventHandler AfterStateChanged;

		public ITuringCommandList CommandList { get; private set; }

		public char[] Tape { get; private set; }

		public int TapePosition
		{
			get { return this.tapePosition; }
		}

		public MovementValues NextMove
		{
			get { return this.nextMove; }
		}

		public char CurrentTapeChar
		{
			get { return this.Tape[this.TapePosition]; }
		}

		public bool Terminated { get; private set; }

		public bool Ready { get; private set; }

		public void Initialize(ITuringCommandList turingCommandList, string inputString)
		{
			this.CommandList = turingCommandList;
			this.Tape = inputString.ToCharArray();
			this.tapePosition = 0;
			this.Terminated = false;
			this.nextMove = MovementValues.Undefined;
			this.Ready = true;

			if ( this.AfterStateChanged != null )
				this.AfterStateChanged(this, EventArgs.Empty);
		}

		public void Load(string filename, string inputString)
		{
			var turingCommandList = new TuringCommandList().LoadFromFile(filename);
			this.Initialize(turingCommandList, inputString);
		}

		public void Start()
		{
			if ( this.Tape == null )
				throw new NullReferenceException("Turing-Logik nicht initialisiert! Bitte zuerst Initialize() aufrufen.");

			while ( this.Step() )
			{
			}
		}

		public bool Step()
		{
			Debug.WriteLine(string.Format("Pre-Step : Pos: {0} | char: {1} | nMov: {2} | Tape: {3}", this.TapePosition, this.CurrentTapeChar, this.nextMove, this.Tape.Length < 50 ? new string(this.Tape) : "Tape zu lang (> 50)"));

			switch ( this.nextMove )
			{
				case MovementValues.S:
					this.Terminated = true;
					this.Ready = false;
					return false;
				case MovementValues.R:
					this.tapePosition++;
					break;
				case MovementValues.L:
					this.tapePosition--;
					break;
				case MovementValues.Undefined:
					break;
				default:
					throw new ArgumentOutOfRangeException();
			}

			var tempChar = this.CurrentTapeChar;
			var command = this.CommandList.SelectCommand(this.currentState, tempChar);
			this.currentState = command.Z1;

			// Zeichen auf Tape ggfls. ersetzen lt. Anweisung
			if ( command.SZ != '#' )
				this.Tape[this.TapePosition] = command.SZ;

			this.nextMove = command.MOV;
			Debug.WriteLine(string.Format("Post-Step: Pos: {0} | char: {1} -> {2} | Mov: {3} | Tape: {4}", this.TapePosition, tempChar, this.CurrentTapeChar, command.MOV, this.Tape.Length < 50 ? new string(this.Tape) : "Tape zu lang (> 50)"));

			if ( this.AfterStateChanged != null )
				this.AfterStateChanged(this, EventArgs.Empty);

			return true;
		}

		public void Reset()
		{
			this.tapePosition = 0;
			this.Terminated = false;
			this.Tape = null;
			this.nextMove = MovementValues.Undefined;
			this.Ready = false;

			if ( this.AfterStateChanged != null )
				this.AfterStateChanged(this, EventArgs.Empty);
		}
	}
}