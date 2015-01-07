namespace TuringSimulator.Tests
{
	using System;
	using System.Reflection;
	using CPP.Shared;
	using NUnit.Framework;

	[TestFixture]
	public class CommandTests
	{
		/// <summary>Testet die C# - Implementierung von ITuringCommandList bzw. ITuringCommand</summary>
		[Test]
		public void LoadParseCS()
		{
			var commandList = new CS.Core.TuringCommandList();
			this.LoadAndValidate(commandList);
		}

		/// <summary>Testet die C++ - Implementierung von ITuringCommandList bzw. ITuringCommand</summary>
		[Test]
		public void LoadParseCPP()
		{
			var commandList = new CPP.Core.TuringCommandList();
			this.LoadAndValidate(commandList);
		}

		[Test]
		public void TestStartCS()
		{
			this.TestStart(new CS.Core.TuringLogic());
		}

		[Test]
		public void TestStartCPP()
		{
			this.TestStart(new CPP.Core.TuringLogic());
		}

		[Test]
		public void StepCS()
		{
			this.Step(new CS.Core.TuringLogic());
		}

		[Test]
		public void StepCPP()
		{
			this.Step(new CPP.Core.TuringLogic());
		}

		private void TestStart(ITuringLogic logic)
		{
			logic.Load(@"..\..\..\_Resources\InverseInput.tur", "0110#");
			logic.Start();
			Assert.AreEqual("1001#", logic.Tape);
		}

		private void Step(ITuringLogic logic)
		{
			logic.Load(@"..\..\..\_Resources\InverseInput.tur", "0110#");
			Assert.AreEqual(MovementValues.Undefined, logic.NextMove);

			logic.Step();
			Assert.AreEqual(0, logic.TapePosition);
			Assert.AreEqual('1', logic.CurrentTapeChar);
			Assert.AreEqual(MovementValues.R, logic.NextMove);
			Assert.AreEqual(false, logic.Terminated);

			logic.Step();
			Assert.AreEqual(1, logic.TapePosition);
			Assert.AreEqual('0', logic.CurrentTapeChar);
			Assert.AreEqual(false, logic.Terminated);

			logic.Step();
			Assert.AreEqual(2, logic.TapePosition);
			Assert.AreEqual('0', logic.CurrentTapeChar);
			Assert.AreEqual(false, logic.Terminated);

			logic.Step();
			Assert.AreEqual(3, logic.TapePosition);
			Assert.AreEqual('1', logic.CurrentTapeChar);
			Assert.AreEqual(false, logic.Terminated);

			logic.Step();
			Assert.AreEqual(4, logic.TapePosition);
			Assert.AreEqual(false, logic.Terminated);
			Assert.AreEqual("1001#", logic.Tape);

			logic.Step();
			Assert.AreEqual(true, logic.Terminated);
		}

		/// <summary>Überprüft die Lade- bzw. Parseroutinen von ITuringCommandList bzw. ITuringCommand</summary>
		/// <param name="commandList"></param>
		private void LoadAndValidate(ITuringCommandList commandList)
		{
			// Vordefinierte Testdatei mit drei Datensätzen laden
			commandList.LoadFromFile(@"..\..\..\_Resources\InverseInput.tur");

			// Sicherstellen, dass auch 3 Datensätze geladen wurden
			Assert.AreEqual(3, commandList.Count);

			// 0,0->0,1,R
			Assert.AreEqual(0, commandList[0].Z0);
			Assert.AreEqual('0', commandList[0].GZ);
			Assert.AreEqual(0, commandList[0].Z1);
			Assert.AreEqual('1', commandList[0].SZ);
			Assert.AreEqual(MovementValues.R, commandList[0].MOV);

			// 0,1->0,0,R
			Assert.AreEqual(0, commandList[1].Z0);
			Assert.AreEqual('1', commandList[1].GZ);
			Assert.AreEqual(0, commandList[1].Z1);
			Assert.AreEqual('0', commandList[1].SZ);
			Assert.AreEqual(MovementValues.R, commandList[1].MOV);

			// 0,#->0,#,S
			Assert.AreEqual(0, commandList[2].Z0);
			Assert.AreEqual('#', commandList[2].GZ);
			Assert.AreEqual(0, commandList[2].Z1);
			Assert.AreEqual('#', commandList[2].SZ);
			Assert.AreEqual(MovementValues.S, commandList[2].MOV);
		}
	}
}
