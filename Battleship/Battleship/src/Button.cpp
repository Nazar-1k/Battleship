#include "Button.h"

Button::Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor)
{
	text.setString(t);
	text.setFillColor(textColor);
	text.setCharacterSize(charSize);

	button.setSize(size);
	button.setFillColor(bgColor);
}

void Button::sentFont(sf::Font& font)
{
	text.setFont(font);
}

void Button::setBackColor(sf::Color color)
{
	button.setFillColor(color);
}

void Button::setTextColor(sf::Color color)
{
	text.setFillColor(color);
}

void Button::setPosition(sf::Vector2f pos)
{
	button.setPosition(pos);

	float xPos = (pos.x + button.getGlobalBounds().width / 3.f - (text.getGlobalBounds().width / 3));
	float yPos = (pos.y + button.getGlobalBounds().height / 3.f - (text.getGlobalBounds().height / 2)-7);
	text.setPosition({ xPos , yPos });
}

void Button::drawTo(sf::RenderWindow& window)
{
	window.draw(button);
	window.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow& window)
{
	if (button.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		return true;
	}
	else return false;
}