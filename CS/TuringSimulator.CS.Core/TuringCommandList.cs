namespace TuringSimulator.CS.Core
{
	using System;
	using System.Collections.Generic;
	using System.IO;
	using System.Linq;
	using System.Text;
	using Shared;

	public class TuringCommandList : List<ITuringCommand>, ITuringCommandList
	{
		public void LoadFromFile(string filename)
		{
			this.Clear();

			try
			{
				var lines = File.ReadAllLines(filename);
				foreach ( var line in lines )
				{
					var newCommand = new TuringCommand(line);
					this.Add(newCommand);
				}
			}
			catch ( Exception )
			{
				this.Clear();
				throw;
			}
		}

		public ITuringCommand SelectCommand(int state, char input)
		{
			return this.SingleOrDefault(x => x.Z0 == state && x.GZ == input);
		}
	}
}