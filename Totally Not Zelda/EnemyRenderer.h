#pragma once
#include <iostream>
#include <map>
#include "SFML\Graphics.hpp"
#include "Enemy.h"
#include "EnemyManager.h"
class EnemyRenderer : public sf::Drawable
{
public:
	EnemyRenderer(EnemyManager&);
	~EnemyRenderer(void);

	void init();
	void update();
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	EnemyManager& m_enemyManager;

	std::map<std::string, sf::Texture> m_textures;
};