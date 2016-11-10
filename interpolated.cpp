/*#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace sf;

void update_state();
void render_frame(float t);

RenderWindow window;

RectangleShape shape;
Vector2f prevPos;
Vector2f nextPos;

int main()
{
	window.create(VideoMode(800, 600), "SFML Example");

	Clock clock;

	prevPos = Vector2f(350, 250);
	nextPos = prevPos;
	shape.setPosition(prevPos);
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
		while (accumulatedTime >= 0.1f)
		{
			update_state();
			accumulatedTime -= 0.1f;
		}

		float t = accumulatedTime / 0.1f;
		render_frame(t);
		window.display();
	}

	return 0;
}

void update_state()
{
	prevPos = nextPos;

	if (Keyboard::isKeyPressed(Keyboard::Left))
		nextPos.x -= 30;
	if (Keyboard::isKeyPressed(Keyboard::Right))
		nextPos.x += 30;
	if (Keyboard::isKeyPressed(Keyboard::Up))
		nextPos.y -= 30;
	if (Keyboard::isKeyPressed(Keyboard::Down))
		nextPos.y += 30;
}

template<typename T>
T lerp(T start, T end, float t)
{
	return start + (end - start) * t;
}

void render_frame(float t)
{
	window.clear();

	Vector2f pos = lerp(prevPos, nextPos, t);
	shape.setPosition(pos);
	window.draw(shape);
}*/