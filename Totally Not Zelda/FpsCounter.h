#pragma once
#include <cmath>
#include "SFML\System\Clock.hpp"
class FpsCounter
{
public:
	FpsCounter(void);
	~FpsCounter(void);

	void countFrame();

	float getFps();
	float getRoundedFps();
private:
	sf::Time m_lastTime, m_frameTime;
	sf::Clock m_clock;
};

