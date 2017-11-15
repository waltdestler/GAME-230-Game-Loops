//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
//#include <SFML/System.hpp>
//#include <SFML/OpenGL.hpp>
//#include <SFML/Main.hpp>
//
//using namespace sf;
//
//void update_state(float dt);
//void render_frame();
//
//RenderWindow window;
//View view;
//Vector2f viewCenter;
//
//Texture bgTex;
//RectangleShape bg;
//
//CircleShape shape;
//
//float shakeTimeLeft = 0;
//
//int main()
//{
//	window.create(VideoMode(800, 600), "SFML Example");
//
//	bgTex.loadFromFile("grass.jpg");
//	bg.setPosition(-2048, -2048);
//	bg.setSize(Vector2f(4096, 4096));
//	bg.setTexture(&bgTex);
//
//	Clock clock;
//
//	shape.setPosition(0, 0);
//	shape.setRadius(25);
//	shape.setOrigin(25, 25);
//	shape.setFillColor(Color::Red);
//
//	view.setSize(window.getSize().x, window.getSize().y);
//	viewCenter = shape.getPosition();
//	view.setCenter(viewCenter);
//
//	while (window.isOpen())
//	{
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//				window.close();
//			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
//				shakeTimeLeft = 1;
//		}
//
//		float dt = clock.restart().asSeconds();
//
//		update_state(dt);
//		render_frame();
//		window.display();
//	}
//
//	return 0;
//}
//
//template<typename T>
//T lerp(T start, T end, float t)
//{
//	return start + (end - start) * t;
//}
//
//float rand_float()
//{
//	return (float)rand() / RAND_MAX * 2 - 1;
//}
//
//void update_state(float dt)
//{
//	Vector2f pos = shape.getPosition();
//
//	if (Keyboard::isKeyPressed(Keyboard::Left))
//		pos.x -= 300 * dt;
//	if (Keyboard::isKeyPressed(Keyboard::Right))
//		pos.x += 300 * dt;
//	if (Keyboard::isKeyPressed(Keyboard::Up))
//		pos.y -= 300 * dt;
//	if (Keyboard::isKeyPressed(Keyboard::Down))
//		pos.y += 300 * dt;
//
//	shape.setPosition(pos);
//
//	Vector2f targetCenter = shape.getPosition();
//	viewCenter += (targetCenter - viewCenter) * 2.0f * dt;
//
//	Vector2f shake(0, 0);
//	if (shakeTimeLeft > 0)
//	{
//		shake.x = 10 * rand_float() * shakeTimeLeft;
//		shake.y = 10 * rand_float() * shakeTimeLeft;
//		shakeTimeLeft -= dt / 0.5f;
//	}
//
//	view.setCenter(viewCenter + shake);
//}
//
//void render_frame()
//{
//	window.clear();
//	window.setView(view);
//	window.draw(bg);
//	window.draw(shape);
//}