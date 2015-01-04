namespace TuringSimulator.CS.Shared
{
	using System;
	using System.Collections.Generic;
	using System.Linq;
	using System.Text;

	public interface ITuringCommandList<T>
	{
		int Count { get; }

		T this[Int32 index] { get; set; }

		void LoadFromFile(string filename);
	}
}