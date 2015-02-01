// <copyright file="TuringLogic.cs" company="Private">
//   Copyright (c) Sascha Schwegelbauer. All rights reserved.
// </copyright>

namespace TuringSimulator.CS.Core
{
	using System;
	using System.Collections.Generic;
	using System.Diagnostics;
	using System.Linq;
	using System.Text;
	using TuringSimulator.CPP.Shared;

	/// <summary></summary>
	public class TuringLogic : TuringSimulator.CPP.Shared.ITuringLogic
	{
		private int tapeheadPosition;

		private int currentState; // MZ - Maschinenzustand

		private MovementValues nextMove;

		public TuringLogic()
		{
			this.Reset();
		}

		public event EventHandler AfterStateChanged;

		public event LogEventArgs LogReceived;

		public ITuringCommandList CommandList { get; private set; }

		public char[] Tape { get; private set; }

		public int TapeheadPosition
		{
			get { return this.tapeheadPosition; }
		}

		public MovementValues NextMove
		{
			get { return this.nextMove; }
		}

		public char CurrentTapeChar
		{
			get
			{
				if ( this.TapeheadPosition < 0 || this.TapeheadPosition >= this.Tape.Length )
					return '$';

				return this.Tape[this.TapeheadPosition];
			}
		}

		public bool Terminated { get; private set; }

		public bool Ready { get; private set; }

		public int? CurrentCommandIndex { get; private set; }

		public void InitializeFromFile(string filename, string inputString)
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
			this.RaiseLogReceived(string.Format("Pre-Step : State: {0} | Pos: {1} | char: {2}      | nMov: {3} | Tape: {4}", this.currentState, this.TapeheadPosition, this.CurrentTapeChar, this.nextMove, this.Tape.Length < 50 ? new string(this.Tape) : "Tape zu lang (> 50)"));

			switch ( this.nextMove )
			{
				case MovementValues.S:
					this.Terminated = true;
					this.Ready = false;
					return false;
				case MovementValues.N:
					break;
				case MovementValues.R:
					this.tapeheadPosition++;
					break;
				case MovementValues.L:
					this.tapeheadPosition--;
					break;
				case MovementValues.Undefined:
					break;
				default:
					throw new ArgumentOutOfRangeException();
			}

			var tempChar = this.CurrentTapeChar;
			this.CurrentCommandIndex = this.CommandList.GetCommandIndex(this.currentState, tempChar);
			if ( this.CurrentCommandIndex == null )
				throw new Exception("Gefordertes Kommando nicht in Liste gefunden!");

			Debug.WriteLine(string.Format("Hole Kommando mit Index {0} aus Liste...", this.CurrentCommandIndex.Value));
			var command = this.CommandList[this.CurrentCommandIndex.Value];
			
			this.currentState = command.Z1;

			// Zeichen auf Tape ggfls. ersetzen lt. Anweisung
			if ( command.SZ != '#' && command.SZ != '$' )
				this.Tape[this.TapeheadPosition] = command.SZ;

			this.nextMove = command.MOV;
			this.RaiseLogReceived(string.Format("Post-Step: State: {0} | Pos: {1} | char: {2} -> {3} |  Mov: {4} | Tape: {5}", this.currentState, this.TapeheadPosition, tempChar, this.CurrentTapeChar, command.MOV, this.Tape.Length < 50 ? new string(this.Tape) : "Tape zu lang (> 50)"));

			this.RaiseAfterStateChanged();

			return true;
		}

		public void Initialize(ITuringCommandList turingCommandList, string inputString)
		{
			this.Reset(true);
			this.CommandList = turingCommandList;
			this.Tape = inputString.ToCharArray();
			this.Ready = true;

			this.RaiseAfterStateChanged();
		}

		public void Reset()
		{
			this.Reset(false);
		}

		private void Reset(bool skipAfterStateChanged)
		{
			this.CurrentCommandIndex = null;
			this.tapeheadPosition = 0;
			this.Terminated = false;
			this.Tape = null;
			this.nextMove = MovementValues.Undefined;
			this.Ready = false;

			if ( !skipAfterStateChanged )
				this.RaiseAfterStateChanged();
		}

		/// Prüft bzw. ruft den EventHandler für AfterStateChanged auf
		/// 2015-01-06 SaS: Sollte an sich auch ohne den nullptr-check funktionieren, nur lässt sich das (nach meinem aktuellen C++/CLI - Wissen) nicht mit der Definition des Events im Interface vereinbaren
		private void RaiseAfterStateChanged()
		{
			if ( this.AfterStateChanged != null )
				this.AfterStateChanged(this, EventArgs.Empty);
		}

		private void RaiseLogReceived(string logMessage)
		{
			Debug.WriteLine(logMessage);

			if ( this.LogReceived != null )
				this.LogReceived(logMessage);
		}
	}
}