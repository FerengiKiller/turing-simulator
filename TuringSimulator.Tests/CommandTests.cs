using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TuringSimulator.Tests
{
	using CS.Core;
	using NUnit.Framework;

	[TestFixture]
	public class CommandTests
	{
		[Test]
		public void TestLoad()
		{
			var commandList = new TuringCommandList();
			commandList.LoadFromFile(@"..\..\..\_Resources\InverseInput.tur");
			Assert.AreEqual(3, commandList.Count);

		}
	}
}
