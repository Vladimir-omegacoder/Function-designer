#pragma once
#include <SFML/Graphics.hpp>

class Coordinate_system : public sf::Drawable
{
protected:





private:




	sf::RectangleShape Field;
	sf::RectangleShape X_axis;
	sf::RectangleShape Y_axis;



	static float CalculateY(float x, std::string function = "");



public:

	sf::Font DigitFont;


	sf::Vector2f SegemntSize = sf::Vector2f(3, 9);


	float Scale = 50; //for example 10 pixels = 1 coordinate segment
	float GridThickness = 1;
	float CoordinateAxisThickness = 3;
	float DigitSize = SegemntSize.y * 2;


	sf::Color GridColor = sf::Color(120, 120, 120);
	sf::Color AxesColor = sf::Color(175, 175, 175);
	sf::Color FieldColor = sf::Color::Black;
	sf::Color GraphColor = sf::Color::Red;

	sf::Vector2f MaxScope;
	sf::Vector2f FunctionScope;


	bool ShowSegments = true;

	bool ShowGrid = true;

	bool ShowDigits = true;

	bool ShowFunction = false;



	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	Coordinate_system(sf::Vector2f pos, sf::Vector2f size);







};

