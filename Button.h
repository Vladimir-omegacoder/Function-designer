#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Button : public sf::Drawable {


protected:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

	sf::RectangleShape rectshape;
	sf::Text text;

	sf::Color OutlineColor = sf::Color(186, 117, 159);
	sf::Color TextColor = sf::Color::White;

	float Outline = -3;
	bool Active = false;
	

	void ActiveButtonLook();
	void DeactiveButtonLook();
	
	


public:

	Button(sf::Vector2f pos, sf::Vector2f size, sf::Color color);

	void SetTextAttributes(sf::String text, unsigned int character_size, sf::Font& font);
	
	void SetActive();

	void SetNotActive();

	bool CursorInsideButton(sf::Vector2f pos);

	bool GetState() {
		return Active;
	}

	void ButtonClick();




	


};