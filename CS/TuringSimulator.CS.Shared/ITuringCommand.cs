namespace TuringSimulator.CS.Shared
{
	public static class Constants
	{
		private static char Terminate = '#';
	}

	public enum MovementValues
	{
		/// <summary>Stop</summary>
		S = 0,

		/// <summary>Right</summary>
		R = 1,

		/// <summary>Left</summary>
		L = 2, // Left
	}

	public interface ITuringCommand
	{
		int Line { get; set; }

		int Z0 { get; set; }

		char GZ { get; set; }

		int Z1 { get; set; }

		char SZ { get; set; }

		MovementValues MOV { get; set; }
	}
}
