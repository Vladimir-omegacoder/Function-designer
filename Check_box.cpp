#include "Check_box.h"


Check_box::Check_box(sf::Vector2f pos, sf::Vector2f size) {

	this->Shape.setSize(size);
	this->Shape.setOutlineThickness(this->OutlineThickness);

	this->Shape.setPosition(pos);

	this->Shape.setFillColor(this->Color);
	this->Shape.setOutlineColor(this->OutlineColor);





	float sx = this->Shape.getPosition().x;
	float sy = this->Shape.getPosition().y;

	float x = this->Shape.getSize().x;
	float y = this->Shape.getSize().y;

	sf::Vertex t = sf::Vertex();

	t.color = this->MarkColor;


	t.position = sf::Vector2f(sx, sy + y / 3);
	this->Mark.append(t);

	t.position = sf::Vector2f(sx, sy + y * 2 / 3);
	this->Mark.append(t);

	t.position = sf::Vector2f(sx + x / 3, sy + y * 2 / 3);
	this->Mark.append(t);

	t.position = sf::Vector2f(sx + x / 3, sy + y);
	this->Mark.append(t);

	t.position = sf::Vector2f(sx + x, sy);
	this->Mark.append(t);

	t.position = sf::Vector2f(sx + x, sy + y / 3);
	this->Mark.append(t);


}


void Check_box::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	target.draw(this->Shape);

	if (this->Checked) {

		target.draw(this->Mark);

	}



}


bool Check_box::CursorInsideCheckBox(sf::Vector2f pos) {

	if (pos.x >= this->Shape.getPosition().x && pos.x <= this->Shape.getPosition().x + this->Shape.getSize().x) {

		if (pos.y >= this->Shape.getPosition().y && pos.y <= this->Shape.getPosition().y + this->Shape.getSize().y) {

			return true;

		}

	}

	return false;

}


void Check_box::SetActiveLook() {

	State = true;

	Shape.setOutlineColor(ActiveColor);

}


void Check_box::SetNotActiveLook() {

	State = false;

	Shape.setOutlineColor(OutlineColor);

}


bool Check_box::GetState() {

	return this->State;

}


void Check_box::CheckBoxClick() {

	Checked = !Checked;

}