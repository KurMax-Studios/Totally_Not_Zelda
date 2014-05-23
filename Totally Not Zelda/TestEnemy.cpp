#include "TestEnemy.h"


TestEnemy::TestEnemy(void)
{
	m_velocity = sf::Vector2f(0, 1);
	m_spriteName = "TEST_ENEMY";
}


TestEnemy::~TestEnemy(void)
{
}

void TestEnemy::update()
{
	m_position += m_velocity;
}
