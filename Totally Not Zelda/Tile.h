#pragma once
class Tile
{
public:
	Tile();
	explicit Tile(int); // explecit so that we get no eccidental conversions
	~Tile(void);

	int id;
};

