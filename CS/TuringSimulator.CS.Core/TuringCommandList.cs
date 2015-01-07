namespace TuringSimulator.CS.Core
{
	using System;
	using System.Collections.Generic;
	using System.IO;
	using System.Linq;
	using System.Text;
	using TuringSimulator.CPP.Shared;

	/// <summary>Implementiert eine Liste von ITuringCommands</summary>
	/// <remarks>
	/// Keine Prüfung auf mehrere, identische Steps (keine wirkliche Einschränkung)
	/// </remarks>
	public class TuringCommandList : List<ITuringCommand>, ITuringCommandList
	{
		public ITuringCommandList LoadFromFile(string filename)
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

			return this;
		}

		public ITuringCommand SelectCommand(int state, char input)
		{
			return this.FirstOrDefault(x => x.Z0 == state && x.GZ == input);
		}
	}
}