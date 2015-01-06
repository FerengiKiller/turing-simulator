namespace TuringSimulator.CS.Shared
{
	using System;

	public interface ITuringLogic
	{
		ITuringCommandList CommandList { get; }

		event EventHandler AfterStateChanged;

		char[] Tape { get; }

		int TapePosition { get; }

		MovementValues NextMove { get; }

		char CurrentTapeChar { get; }

		bool Terminated { get; }

		void Initialize(ITuringCommandList turingCommandList, string inputString);

		void Load(string filename, string inputString);

		void Start();

		bool Step();

		void Reset();
	}
}