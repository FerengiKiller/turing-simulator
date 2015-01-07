namespace TuringSimulator.CS.Shared
{
	using System;

	public interface ITuringLogic
	{
		event EventHandler AfterStateChanged;

		ITuringCommandList CommandList { get; }

		char[] Tape { get; }

		int TapePosition { get; }

		MovementValues NextMove { get; }

		char CurrentTapeChar { get; }

		bool Terminated { get; }

		bool Ready { get; }

		void Initialize(ITuringCommandList turingCommandList, string inputString);

		void Load(string filename, string inputString);

		void Start();

		bool Step();

		void Reset();
	}
}