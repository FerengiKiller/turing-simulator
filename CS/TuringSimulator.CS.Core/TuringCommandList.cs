namespace TuringSimulator.CS.Core
{
	using System;
	using System.Collections.Generic;
	using System.IO;
	using System.Linq;
	using System.Text;
	using Shared;

	public class TuringCommandList : List<ITuringCommand>, ITuringCommandList<ITuringCommand>
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
	}
}