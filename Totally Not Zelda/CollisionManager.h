#pragma once
#include "Player.h"
#include "Map.h"
#include "EnemyManager.h"
class CollisionManager
{
public:
	CollisionManager(Player&, Map&, EnemyManager&);
	~CollisionManager(void);
	void update();
private:
	void checkCollisions();
	void checkBounds();
	void checkTerrain();
	Player& m_player;
	Map& m_map;
	EnemyManager& m_enemyManager;
};

