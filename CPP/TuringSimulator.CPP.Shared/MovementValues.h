// <copyright file="MovementValues.h" company="Privat">
//   Copyright (c) Sascha Schwegelbauer. All rights reserved.
// </copyright>

#pragma once

namespace TuringSimulator
{
	namespace CPP
	{
		namespace Shared
		{
			public enum class MovementValues
			{
				Undefined = -1,
				
				/// <summary>Stop</summary>
				S = 0,
				
				/// <summary>Right</summary>
				R = 1,
				
				/// <summary>Left</summary>
				L = 2 // Left
			};
		}
	}
}