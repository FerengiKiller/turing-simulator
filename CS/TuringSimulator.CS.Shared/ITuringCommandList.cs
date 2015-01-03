namespace TuringSimulator.CS.Shared
{
	using System;
	using System.Collections.Generic;
	using System.Linq;
	using System.Text;

	public interface ITuringCommandList
	{
		int Count { get; }

		void LoadFromFile(string filename);
	}
}