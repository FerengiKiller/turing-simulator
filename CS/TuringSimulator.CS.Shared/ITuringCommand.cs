namespace TuringSimulator.CS.Shared
{
	public static class Constants
	{
		public static char Terminate = '#';
	}

	public enum MovementValues
	{
		Undefined = -1,

		/// <summary>Stop</summary>
		S = 0,

		/// <summary>Right</summary>
		R = 1,

		/// <summary>Left</summary>
		L = 2, // Left
	}

	public interface ITuringCommand
	{
		System.Int32 Line { get; set; }

		System.Int32 Z0 { get; set; }

		char GZ { get; set; }

		System.Int32 Z1 { get; set; }

		char SZ { get; set; }

		MovementValues MOV { get; set; }
	}
}
