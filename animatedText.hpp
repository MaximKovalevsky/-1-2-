#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class animatedText
{
private:
	sf::Font font;
	sf::Text text;

public:
	float x0, y0;
	int vx0,vy0;
	animatedText() = default;
	animatedText(float X, float Y,int vx, int vy)
	{
		x0 = X;
		y0 = Y;
		vx0 = vx;
		vy0 = vy;
		text.setPosition(x0, y0);
	}

	void animatedText::setText(int characterSize, sf::Color color)
	{
		font.loadFromFile("1.otf");
		text.setFont(font);
		text.setString("sesh");
		text.setCharacterSize(characterSize);
		text.setFillColor(color);
		text.setStyle(sf::Text::Bold);

	}
	void speedOfText(double t)
	{
		float x = x0 + vx0 * t;
		float y = y0 + vy0 * t;
		x0 = x;
		y0 = y;
		text.setPosition(x, y);
	}
	void animatedText::drawText(sf::RenderWindow& window)
	{
		window.draw(text);
	}


};