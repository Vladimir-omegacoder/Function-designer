#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Check_box : public sf::Drawable
{
private:

	bool State = false;

	sf::RectangleShape Shape;

	sf::VertexArray Mark = sf::VertexArray(sf::PrimitiveType::TrianglesStrip);

public:

	float OutlineThickness = -1;

	sf::Color Color = sf::Color::White;
	sf::Color OutlineColor = sf::Color::Black;
	sf::Color MarkColor = sf::Color::Black;
	sf::Color ActiveColor = sf::Color(186, 117, 159);;

	bool Checked = true;



	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	Check_box(sf::Vector2f pos, sf::Vector2f size);

	bool CursorInsideCheckBox(sf::Vector2f pos);

	void SetActiveLook();

	void SetNotActiveLook();

	bool GetState();

	void CheckBoxClick();
};

