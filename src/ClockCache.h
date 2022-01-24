/*
 Name:		ClockCache.h
 Created:	5/29/2021 9:01:07 PM
 Author:	Robert
 Editor:	http://www.visualmicro.com
*/

#ifndef _ClockCache_h
#define _ClockCache_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

	class ClockCache
	{
	public:
		ClockCache();
		operator uint32_t() { return Clock; }
		ClockCache& operator = (const ClockCache&);
		/// <summary> Stores current Millis value </summary>
		void Mark();
		/// <summary> Returns difference between now and last Mark. </summary>
		uint32_t Delta();
		uint32_t DeltaThenMark();
		uint32_t LastDelta();
		ClockCache operator - (ClockCache&);
		ClockCache(uint32_t);

	private:
		uint32_t Clock;
		uint32_t mDelta;
	};
	/*	Uses Volatiles for Encoder Use Safety	*/
	class PreciseClockCache
	{
	public:
		PreciseClockCache();
		//		Implicitly returns Delta()
		operator uint32_t() { return Delta(); }
		void Mark();
		uint32_t Delta();
		uint32_t DeltaThenMark();

	private:
		uint32_t Clock = 0;
	};

	class VelocityClockCache
	{
	public:
		VelocityClockCache();
		operator volatile uint32_t();
		void Mark();
		volatile uint32_t Delta();
		volatile uint32_t DeltaThenMark();
	private:
		volatile uint32_t Clock = 0;
	};





#endif

