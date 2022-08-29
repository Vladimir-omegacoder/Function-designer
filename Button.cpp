#pragma once
#include "Button.h"
#include <iostream>


Button::Button(sf::Vector2f pos, sf::Vector2f size, sf::Color color) {




	this->rectshape.setPosition(pos);
	this->rectshape.setSize(size);
	this->rectshape.setFillColor(color);


}


void Button::SetTextAttributes(sf::String text, unsigned int character_size, sf::Font &font) {

		
	this->text.setFont(font);
	this->text.setString(text);
	this->text.setCharacterSize(character_size);
	

	float Tx = this->rectshape.getPosition().x + (rectshape.getSize().x - this->text.getGlobalBounds().width) / 2 - this->text.getGlobalBounds().left;
	float Ty = this->rectshape.getPosition().y + (rectshape.getSize().y - this->text.getGlobalBounds().height) / 2 - this->text.getGlobalBounds().top;


	this->text.setPosition(sf::Vector2f(Tx, Ty));
	

}



void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const{

	target.draw(rectshape);
	target.draw(text);

}


bool Button::CursorInsideButton(sf::Vector2f pos) {

	if (pos.x >= this->rectshape.getPosition().x && pos.x <= this->rectshape.getPosition().x + this->rectshape.getSize().x) {

		if (pos.y >= this->rectshape.getPosition().y && pos.y <= this->rectshape.getPosition().y + this->rectshape.getSize().y) {

			return true;

		}

	}

	return false;

}


void Button::SetActive() { //make button active

	this->Active = true;
	this->ActiveButtonLook();

}


void Button::SetNotActive() { //make button NOT active

	this->Active = false;
	this->DeactiveButtonLook();

}


void Button::ActiveButtonLook() { //do all the things needed to make button active(draw the border, bool = true, etc)

	//std::cout << "Active look" << std::endl;
	rectshape.setOutlineThickness(Outline);
	rectshape.setOutlineColor(OutlineColor);
	text.setFillColor(OutlineColor);

}


void Button::DeactiveButtonLook() { //do all the things needed to make button NOT active(draw the border, bool = false, etc)

	//std::cout << "Not active look" << std::endl;
	rectshape.setOutlineThickness(0);
	text.setFillColor(TextColor);

}


void Button::ButtonClick() {



}






