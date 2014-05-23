#include "TestEnemy.h"


TestEnemy::TestEnemy(void)
{
	m_velocity = sf::Vector2f(0, 1);
	m_spriteName = "TEST_ENEMY";
	m_size = sf::Vector2i(32, 32);
}


TestEnemy::~TestEnemy(void)
{
}

void TestEnemy::update()
{
	m_position += m_velocity;
}
