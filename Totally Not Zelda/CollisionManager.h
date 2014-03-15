#pragma once
#include "Player.h"
#include "Map.h"
class CollisionManager
{
public:
	CollisionManager(Player&, Map&);
	~CollisionManager(void);
	void update();
private:
	void checkCollisions();
	Player& m_player;
	Map& m_map;
};

