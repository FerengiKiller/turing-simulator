// <copyright file="TuringCommand.cs" person="Sascha Schwegelbauer" company="Private">
//   Copyright (c) Sascha Schwegelbauer. All rights reserved.
// </copyright>

namespace TuringSimulator.CS.Core
{
	using System;
	using System.Collections.Generic;
	using System.Linq;
	using System.Text;
	using Shared;

	/// <summary>
	/// The turing command.
	/// </summary>
	public class TuringCommand : ITuringCommand
	{
		public int Line { get; set; }
	}
}