#include "DebugOverlay.h"


DebugOverlay::DebugOverlay(void) : FONT("LSANS.TTF")
{
}


DebugOverlay::~DebugOverlay(void)
{
}

sf::Font& DebugOverlay::initFont()
{
	if (!m_font.loadFromFile(FONT))
	{
		std::cout << "Failed to load font" << "\n";
		exit(2);
	}
	return m_font;
}

void DebugOverlay::updateText(std::string textString, sf::Text &text)
{
	//setting text in another function so it can be used in an update loop
	text.setString(textString);
}

void DebugOverlay::styleText(sf::Font &font, sf::Text &text)
{
	
	// select the font
	text.setFont(font); // font is a sf::Font

	// set the character size
	text.setCharacterSize(12); // in pixels, not points!

	// set the color
	text.setColor(sf::Color::Red);

	// set the text style
	text.setStyle(sf::Text::Bold);

	// set position besides of map TODO REDO SO ITS NOT STATIC NUMBERS
	text.setPosition(0, 0);
}
void DebugOverlay::init()
{
	styleText(initFont(), m_fps);
}
void DebugOverlay::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(m_fps);
}