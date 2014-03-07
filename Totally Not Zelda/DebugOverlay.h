#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
class DebugOverlay : public sf::Drawable
{
private:
	const char* FONT;
	sf::Font m_font;
public:
	sf::Text m_fps;

	DebugOverlay(void);
	~DebugOverlay(void);
	sf::Font& initFont();
	void styleText(sf::Font &font, sf::Text &text);
	void updateText(std::string textString, sf::Text &text);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};