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
				/// <summary>Stop</summary>
				S = -1,
				
				/// <summary>Nicht definiert</summary>
				Undefined = 0,

				/// <summary>Right: nach Rechts bewegen</summary>
				R = 1,
				
				/// <summary>Left: nach Links bewegen</summary>
				L = 2, // Left

				/// <summary>None: keine Bewegung</summary>
				N = 3,
			};
		}
	}
}