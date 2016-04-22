#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
	//sf::Texture pacman0---8;
	sf::Texture pacmans[9]; //store the images in an array
	std::string names[9] = { "pacman0.png", "pacman1.png", "pacman2.png", "pacman3.png", "pacman4.png", "pacman5.png", "pacman6.png", "pacman7.png", "pacman8.png" };
	for (size_t i = 0; i < 9; ++i)
	{
		if (!pacmans[i].loadFromFile(names[i]))
		{
			std::cout << "Cannot load file.\n";
			return 1;
		}
	}

		sf::Sprite pacman;
		const float speed = 60;// 60 pixels per seconds
		pacman.setScale(0.05f, 0.05f);
		pacman.setOrigin(137.0f, 143.5f);

	sf::RenderWindow window(sf::VideoMode(320, 320), "PACMAN");

	sf::Clock clock;
	clock.restart();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event));
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		sf::Time time;
		time = clock.getElapsedTime();

		/*
		Need 4 chomp per second
		1 chomp need 16 frames
		==> 64 frames per second
		==> 1 frame need 15.625s

		*/

		switch ((time.asMilliseconds() % (16 * 16)) / 16)
		{
		case 0:pacman.setTexture(pacmans[0]); break;
		case 1:pacman.setTexture(pacmans[1]); break;
		case 2:pacman.setTexture(pacmans[2]); break;
		case 3:pacman.setTexture(pacmans[3]); break;
		case 4:pacman.setTexture(pacmans[4]); break;
		case 5:pacman.setTexture(pacmans[5]); break;
		case 6:pacman.setTexture(pacmans[6]); break;
		case 7:pacman.setTexture(pacmans[7]); break;
		case 8:pacman.setTexture(pacmans[8]); break;
		case 9:pacman.setTexture(pacmans[7]); break;
		case 10:pacman.setTexture(pacmans[6]); break;
		case 11:pacman.setTexture(pacmans[5]); break;
		case 12:pacman.setTexture(pacmans[4]); break;
		case 13:pacman.setTexture(pacmans[3]); break;
		case 14:pacman.setTexture(pacmans[2]); break;
		case 15:pacman.setTexture(pacmans[1]); break;
		}
			int const speedX = 1;
			int const speedY = 0;

		pacman.setPosition(32.0f, 32.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			pacman.setPosition(speed*time.asSeconds(), 32.0f);
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			pacman.setPosition(speed*time.asSeconds(), 32.0f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			pacman.setPosition(speed*time.asSeconds(), 32.0f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			pacman.setPosition(speed*time.asSeconds(), 32.0f);
		}
		else
		{
			clock.restart();
		}

			

		/*
		float TotalDistance = speed*time.asSeconds(); // total distance travell as the time move
		float x = speed*time.asSeconds(); // distance in x direction
		float y = speed*time.asSeconds(); // distance in y direction
		if (TotalDistance <= 240.0f)
		{
			//move 240 pixel to the right 
			pacman.setPosition(32.0f + x, 32.0f);

		}
		else if (TotalDistance <= 480.0f)
		{
			pacman.setOrigin(137.0f, 143.5f);
			pacman.setRotation(90.0f);
			//pacman.setPosition(32.0f+240.0f, 32.0f);
			// move 240 pixel downward
			// y-240.0f => minus the total distance moved previously as time pass 
			pacman.setPosition((32.0f + 240.0f), 32.0f + (y - 240.0f));
		}
		else if (TotalDistance <= 720.0f)
		{
			pacman.setOrigin(137.0f, 143.5f);
			pacman.setRotation(180.0f);
			//pacman.setPosition(32.0f + 240.0f, 32.0f + 240.0f);
			//move 240 pixel left
			// x -480.0f => minus the total distance moved previously as time pass 
			pacman.setPosition(32.0f + 240.0f - (x - 480.0f), 32.0f + 240.0f);
		}
		else if (TotalDistance <= 960.0f)
		{
			pacman.setOrigin(137.0f, 143.5f);
			pacman.setRotation(270.0f);
			//pacman.setPosition(32.0f, 32.0f + 240.0f);
			//move 240pixel up
			//y-720.0f => minus the total distance moved previuosly
			pacman.setPosition(32.0f, 32.0f + 240.0f - (y - 720.0f));

		}
		else
		{
			//reset the time
			clock.restart();
		}

		*/

		window.clear();
		window.draw(pacman);
		window.display();
	}

	return 0;
}