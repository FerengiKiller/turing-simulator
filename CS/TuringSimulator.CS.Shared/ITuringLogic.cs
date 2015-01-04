namespace TuringSimulator.CS.Shared
{
	using System;

	public interface ITuringLogic
	{
		ITuringCommandList CommandList { get; }

		int Position { get; }

		MovementValues NextMove { get; }

		char CurrentTapeChar { get; }

		bool Terminated { get; }

		void Initialize(ITuringCommandList turingCommandList, string inputString);

		void Start();

		bool Step();

		void Reset();
	}
}