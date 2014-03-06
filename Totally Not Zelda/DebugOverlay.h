#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
class DebugOverlay : public sf::Drawable
{
private:
	const char* FONT;

	sf::Text m_fps;
public:
	DebugOverlay(void);
	~DebugOverlay(void);
	sf::Font initFont();
	void styleText(sf::Font font, sf::Text text);
	void updateText(std::string textString);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};