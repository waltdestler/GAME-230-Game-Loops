#include <SFML/Graphics.hpp>
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
Vector2f viewCenter;

Texture bgTex;
RectangleShape bg;

RectangleShape shape;

float shakeTimeLeft = 0;

int main()
{
	window.create(VideoMode(800, 600), "SFML Example");
	view.setSize(window.getSize().x, window.getSize().y);
	viewCenter = Vector2f(50, 50);
	view.setCenter(viewCenter);

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
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
				shakeTimeLeft = 1;
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
	viewCenter += (targetCenter - viewCenter) * 4.0f * dt;

	Vector2f shake(0, 0);
	if (shakeTimeLeft > 0)
	{
		shake = Vector2f(
			(float)rand() / RAND_MAX * 20.0f * shakeTimeLeft,
			(float)rand() / RAND_MAX * 20.0f * shakeTimeLeft);
		shakeTimeLeft -= dt * 2;
	}

	view.setCenter(viewCenter + shake);
}

void render_frame()
{
	window.clear();
	window.setView(view);
	window.draw(bg);
	window.draw(shape);
}