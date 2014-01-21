#include "FpsCounter.h"


FpsCounter::FpsCounter(void)
{
	m_clock.restart();
}


FpsCounter::~FpsCounter(void)
{
}

void FpsCounter::countFrame()
{
	m_frameTime = m_clock.getElapsedTime() - m_lastTime;
	m_lastTime = m_clock.getElapsedTime();
}

float FpsCounter::getFps()
{
	return 1/(m_frameTime.asSeconds());
}
float FpsCounter::getRoundedFps()
{
	return std::ceil(getFps());
}