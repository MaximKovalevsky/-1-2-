
#include <iostream>
#include <SFML/Graphics.hpp>
#include "animatedText.hpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Random animation");
	window.setFramerateLimit(60);
	animatedText text1(0,-170,20,0);
	sf::Clock timer;
	sf::Texture texture;
	texture.loadFromFile("1.png");

	sf::Sprite sprite(texture);
	sprite.setScale(0.9f, 0.9f);
	sprite.setPosition(-25.f, 200.f);
	double t1 = 1;
	while (window.isOpen())
	{
		sf::Event event; 
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window.close(); 
		}
		sf::Time dt = timer.restart();
		t1 += dt.asSeconds();
		window.clear();
		window.draw(sprite);
		text1.setText(375,sf::Color::Cyan);
		text1.drawText(window);
		if (text1.x0 > 1000)
		{
			text1.x0 = -1450;
			t1 = 1;
		}
		//std::cout << text1.x0 << "\n";
		//std::cout << text1.vx0 << "\n";
		//std::cout << t << "\n";
		text1.speedOfText(t1);
		
		window.display();
	}

	return 0;
}

