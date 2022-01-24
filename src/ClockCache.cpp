/*
 Name:		ClockCache.cpp
 Created:	5/29/2021 9:01:07 PM
 Author:	Robert
 Editor:	http://www.visualmicro.com
*/

#include "ClockCache.h"
#include <ADM.h>

	ClockCache::ClockCache()
		: Clock(millis())
	{
	}
	ClockCache::ClockCache(uint32_t _inMillis)
	{
		Clock = _inMillis;
	}
	ClockCache& ClockCache::operator = (const ClockCache& _inClock)
	{
		Clock = _inClock.Clock;
		return *this;
	}
	void ClockCache::Mark()
	{
		Clock = millis();
	}
	uint32_t ClockCache::Delta()
	{
		return millis() - Clock;
	}
	uint32_t ClockCache::DeltaThenMark()
	{
		mDelta = millis() - Clock;
		Clock = millis();
		return mDelta;
	}
	ClockCache ClockCache::operator-(ClockCache& _inClock)
	{
		return ClockCache(this->Clock - _inClock.Clock);
	}
	uint32_t ClockCache::LastDelta()
	{
		return uint32_t();
	}
	PreciseClockCache::PreciseClockCache()
		: Clock(micros())
	{
	}

	void PreciseClockCache::Mark()
	{
		Clock = micros();
	}
	uint32_t PreciseClockCache::Delta()
	{		
		return micros() - Clock;
	}
	uint32_t PreciseClockCache::DeltaThenMark()
	{
		uint32_t mDelta = micros() - Clock;
		Clock = micros();	
		return mDelta;
	}

	VelocityClockCache::VelocityClockCache()
		:	Clock(micros())
	{
	}
	VelocityClockCache::operator volatile uint32_t()
	{
		return Clock;
	}
	void VelocityClockCache::Mark()
	{
		Clock = micros();
	}
	volatile uint32_t VelocityClockCache::Delta()
	{
		volatile uint32_t delta = uint32_t(micros() - Clock);
		return delta;
	}
	volatile uint32_t VelocityClockCache::DeltaThenMark()
	{
		volatile uint32_t delta = uint32_t(micros() - Clock);
		Clock = micros();
		return delta;
	}
