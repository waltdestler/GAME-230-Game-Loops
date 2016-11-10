/*#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace sf;

void update_state(float dt);
void render_frame();

RenderWindow window;
View view;

Texture bgTex;
RectangleShape bg;

RectangleShape shape;

int main()
{
	window.create(VideoMode(800, 600), "SFML Example");
	view.setSize(window.getSize().x, window.getSize().y);
	view.setCenter(50, 50);

	bgTex.loadFromFile("grass.jpg");
	bg.setPosition(-2048, -2048);
	bg.setSize(Vector2f(4096, 4096));
	bg.setTexture(&bgTex);

	Clock clock;

	shape.setPosition(0, 0);
	shape.setSize(Vector2f(100, 100));
	shape.setFillColor(Color::Red);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float dt = clock.restart().asSeconds();

		update_state(dt);
		render_frame();
		window.display();
	}

	return 0;
}

void update_state(float dt)
{
	Vector2f pos = shape.getPosition();

	if (Keyboard::isKeyPressed(Keyboard::Left))
		pos.x -= 300 * dt;
	if (Keyboard::isKeyPressed(Keyboard::Right))
		pos.x += 300 * dt;
	if (Keyboard::isKeyPressed(Keyboard::Up))
		pos.y -= 300 * dt;
	if (Keyboard::isKeyPressed(Keyboard::Down))
		pos.y += 300 * dt;

	shape.setPosition(pos);

	Vector2f targetCenter = pos + shape.getSize() / 2.0f;
	Vector2f curCenter = view.getCenter();
	curCenter += (targetCenter - curCenter) * 1.0f * dt;
	view.setCenter(curCenter);
}

void render_frame()
{
	window.clear();
	window.setView(view);
	window.draw(bg);
	window.draw(shape);
}*/