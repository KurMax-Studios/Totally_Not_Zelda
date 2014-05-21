#pragma once
#include "SFML\Graphics.hpp"
#include "Enemy.h"
#include "EnemyManager.h"
class EnemyRenderer : public sf::Drawable
{
public:
	EnemyRenderer(EnemyManager&);
	~EnemyRenderer(void);
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	EnemyManager& m_enemyManager;
};