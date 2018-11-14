/*#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace sf;

void update_state();
void render_frame();

RenderWindow window;

RectangleShape shape;

const float FRAME_TIME = 1.0f / 10.0f;

int main()
{
	window.create(VideoMode(800, 600), "SFML Example");

	Clock clock;

	shape.setPosition(350, 250);
	shape.setSize(Vector2f(100, 100));
	shape.setFillColor(Color::Green);

	float accumulatedTime = 0;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float dt = clock.restart().asSeconds();
		accumulatedTime += dt;
		while (accumulatedTime >= FRAME_TIME)
		{
			update_state();
			accumulatedTime -= FRAME_TIME;
		}

		render_frame();
		window.display();
	}

	return 0;
}

void update_state()
{
	Vector2f pos = shape.getPosition();

	if (Keyboard::isKeyPressed(Keyboard::Left))
		pos.x -= 30;
	if (Keyboard::isKeyPressed(Keyboard::Right))
		pos.x += 30;
	if (Keyboard::isKeyPressed(Keyboard::Up))
		pos.y -= 30;
	if (Keyboard::isKeyPressed(Keyboard::Down))
		pos.y += 30;

	shape.setPosition(pos);
}

void render_frame()
{
	window.clear();
	window.draw(shape);
}*/