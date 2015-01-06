namespace TuringSimulator.CS.Shared
{
	using System;
	using System.Collections.Generic;
	using System.Linq;
	using System.Text;

	public interface ITuringCommandList
	{
		int Count { get; }

		ITuringCommand this[Int32 index] { get; set; }

		ITuringCommandList LoadFromFile(string filename);

		ITuringCommand SelectCommand(int state, char input);
	}
}