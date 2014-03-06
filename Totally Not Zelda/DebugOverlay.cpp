#include "DebugOverlay.h"


DebugOverlay::DebugOverlay(void) : FONT("LSANS.TTF")
{
}


DebugOverlay::~DebugOverlay(void)
{
}

sf::Font DebugOverlay::initFont()
{
	sf::Font m_font;
	if (!m_font.loadFromFile(FONT))
	{
		std::cout << "Failed to load font" << "\n";
		exit(2);
	}
	return m_font;
}

void DebugOverlay::styleText(sf::Font font, sf::Text text)
{
	
	// select the font
	text.setFont(font); // font is a sf::Font

	// set the character size
	text.setCharacterSize(12); // in pixels, not points!

	// set the color
	text.setColor(sf::Color::Red);

	// set the text style
	text.setStyle(sf::Text::Regular);
}
void DebugOverlay::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	
}