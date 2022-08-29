#pragma once
#include "Coordinate_system.h"
#include <list>
#include <iostream>
#include <math.h>
#include <string.h>



void Coordinate_system::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	target.draw(Field);

	if (ShowSegments) {

		if (ShowSegments && ShowGrid && ShowDigits) {

			sf::RectangleShape grid;
			sf::RectangleShape segment;

			sf::Text digits = sf::Text("", DigitFont, DigitSize);
			digits.setFillColor(sf::Color::Blue);

			for (float i = 1; i * Scale < Field.getSize().x / 2; ++i) {


				grid.setSize(sf::Vector2f(GridThickness, Field.getSize().y));
				grid.setFillColor(GridColor);

				grid.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - GridThickness) / 2 + Scale * i, Field.getPosition().y));
				target.draw(grid);
				grid.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - GridThickness) / 2 - Scale * i, Field.getPosition().y));
				target.draw(grid);



				segment.setSize(SegemntSize);
				segment.setFillColor(AxesColor);

				segment.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.x) / 2 + Scale * i, Field.getPosition().y + (Field.getSize().y - SegemntSize.y) / 2));
				target.draw(segment);
				segment.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.x) / 2 - Scale * i, Field.getPosition().y + (Field.getSize().y - SegemntSize.y) / 2));
				target.draw(segment);



				digits.setString(std::to_string(int(i)));
				digits.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y) / 2 + Scale * i, Field.getPosition().y + (Field.getSize().y - SegemntSize.y) / 2 + SegemntSize.y * 0.75));
				target.draw(digits);

				digits.setString(std::to_string(-int(i)));
				digits.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y * 2) / 2 - Scale * i, Field.getPosition().y + (Field.getSize().y - SegemntSize.y) / 2 + SegemntSize.y * 0.75));
				target.draw(digits);

			}

			for (float i = 1; i * Scale < Field.getSize().y / 2; ++i) {

				grid.setSize(sf::Vector2f(Field.getSize().x, GridThickness));
				grid.setFillColor(GridColor);

				grid.setPosition(sf::Vector2f(Field.getPosition().x, Field.getPosition().y + (Field.getSize().y - GridThickness) / 2 + Scale * i));
				target.draw(grid);
				grid.setPosition(sf::Vector2f(Field.getPosition().x, Field.getPosition().y + (Field.getSize().y - GridThickness) / 2 - Scale * i));
				target.draw(grid);



				segment.setSize(sf::Vector2f(SegemntSize.y, SegemntSize.x));
				segment.setFillColor(AxesColor);

				segment.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y) / 2, Field.getPosition().y + (Field.getSize().y - SegemntSize.x) / 2 + Scale * i));
				target.draw(segment);
				segment.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y) / 2, Field.getPosition().y + (Field.getSize().y - SegemntSize.x) / 2 - Scale * i));
				target.draw(segment);



				digits.setString(std::to_string(int(i)));
				digits.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - digits.getCharacterSize()) / 2 - SegemntSize.y, Field.getPosition().y + (Field.getSize().y - SegemntSize.y * 2) / 2 - Scale * i));
				target.draw(digits);

				digits.setString(std::to_string(-int(i)));
				digits.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y * 2) / 2 - SegemntSize.y, Field.getPosition().y + (Field.getSize().y - SegemntSize.y * 2) / 2 + Scale * i));
				target.draw(digits);

			}

			target.draw(X_axis);
			target.draw(Y_axis);

			if (ShowFunction) {


				sf::VertexArray Graph = sf::VertexArray(sf::LineStrip);

				bool t = true;

				for (float i = FunctionScope.x; i < FunctionScope.y && t; i += 1 / Scale) {

					float Y = CalculateY(i);

					sf::Vector2f pos = sf::Vector2f(Field.getPosition().x + (Field.getGlobalBounds().width + abs(i) / i * CoordinateAxisThickness) / 2 + i * Scale, Field.getPosition().y + (Field.getGlobalBounds().height - abs(Y) / Y * CoordinateAxisThickness) / 2 - Y * Scale);

					if (pos.x > Field.getGlobalBounds().left && pos.x < Field.getGlobalBounds().left + Field.getGlobalBounds().width) {

						if (pos.y > Field.getGlobalBounds().top && pos.y < Field.getGlobalBounds().top + Field.getGlobalBounds().height) {

							//std::cout << i << "\t" << CalculateY(i) << std::endl;
							Graph.append(sf::Vertex(pos, GraphColor));
							continue;

						}

					}

					bool t = false;

				}

				target.draw(Graph);

			}

			return;

		}

		if (ShowSegments && ShowDigits) {

			sf::RectangleShape segment;
			sf::Text digits = sf::Text("", DigitFont, DigitSize);
			digits.setFillColor(sf::Color::Blue);


			for (float i = 1; i * Scale < Field.getSize().x / 2; ++i) {

				segment.setSize(SegemntSize);
				segment.setFillColor(AxesColor);

				segment.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.x) / 2 + Scale * i, Field.getPosition().y + (Field.getSize().y - SegemntSize.y) / 2));
				target.draw(segment);
				segment.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.x) / 2 - Scale * i, Field.getPosition().y + (Field.getSize().y - SegemntSize.y) / 2));
				target.draw(segment);



				digits.setString(std::to_string(int(i)));
				digits.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y) / 2 + Scale * i, Field.getPosition().y + (Field.getSize().y - SegemntSize.y) / 2 + SegemntSize.y * 0.75));
				target.draw(digits);

				digits.setString(std::to_string(-int(i)));
				digits.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y * 2) / 2 - Scale * i, Field.getPosition().y + (Field.getSize().y - SegemntSize.y) / 2 + SegemntSize.y * 0.75));
				target.draw(digits);

			}

			for (float i = 1; i * Scale < Field.getSize().y / 2; ++i) {

				segment.setSize(sf::Vector2f(SegemntSize.y, SegemntSize.x));
				segment.setFillColor(AxesColor);

				segment.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y) / 2, Field.getPosition().y + (Field.getSize().y - SegemntSize.x) / 2 + Scale * i));
				target.draw(segment);
				segment.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y) / 2, Field.getPosition().y + (Field.getSize().y - SegemntSize.x) / 2 - Scale * i));
				target.draw(segment);



				digits.setString(std::to_string(int(i)));
				digits.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - digits.getCharacterSize()) / 2 - SegemntSize.y, Field.getPosition().y + (Field.getSize().y - SegemntSize.y * 2) / 2 - Scale * i));
				target.draw(digits);

				digits.setString(std::to_string(-int(i)));
				digits.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y * 2) / 2 - SegemntSize.y, Field.getPosition().y + (Field.getSize().y - SegemntSize.y * 2) / 2 + Scale * i));
				target.draw(digits);

			}

			target.draw(X_axis);
			target.draw(Y_axis);

			if (ShowFunction) {


				sf::VertexArray Graph = sf::VertexArray(sf::LineStrip);

				bool t = true;

				for (float i = FunctionScope.x; i < FunctionScope.y && t; i += 1 / Scale) {

					float Y = CalculateY(i);

					sf::Vector2f pos = sf::Vector2f(Field.getPosition().x + (Field.getGlobalBounds().width + abs(i) / i * CoordinateAxisThickness) / 2 + i * Scale, Field.getPosition().y + (Field.getGlobalBounds().height - abs(Y) / Y * CoordinateAxisThickness) / 2 - Y * Scale);

					if (pos.x > Field.getGlobalBounds().left && pos.x < Field.getGlobalBounds().left + Field.getGlobalBounds().width) {

						if (pos.y > Field.getGlobalBounds().top && pos.y < Field.getGlobalBounds().top + Field.getGlobalBounds().height) {

							Graph.append(sf::Vertex(pos, GraphColor));
							continue;

						}

					}

					bool t = false;

				}

				target.draw(Graph);

			}

			return;

		}

		if (ShowSegments && ShowGrid) {

			sf::RectangleShape grid;
			sf::RectangleShape segment;


			for (float i = 1; i * Scale < Field.getSize().x / 2; ++i) {


				grid.setSize(sf::Vector2f(GridThickness, Field.getSize().y));
				grid.setFillColor(GridColor);

				grid.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - GridThickness) / 2 + Scale * i, Field.getPosition().y));
				target.draw(grid);
				grid.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - GridThickness) / 2 - Scale * i, Field.getPosition().y));
				target.draw(grid);



				segment.setSize(SegemntSize);
				segment.setFillColor(AxesColor);

				segment.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.x) / 2 + Scale * i, Field.getPosition().y + (Field.getSize().y - SegemntSize.y) / 2));
				target.draw(segment);
				segment.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.x) / 2 - Scale * i, Field.getPosition().y + (Field.getSize().y - SegemntSize.y) / 2));
				target.draw(segment);

			}

			for (float i = 1; i * Scale < Field.getSize().y / 2; ++i) {

				grid.setSize(sf::Vector2f(Field.getSize().x, GridThickness));
				grid.setFillColor(GridColor);

				grid.setPosition(sf::Vector2f(Field.getPosition().x, Field.getPosition().y + (Field.getSize().y - GridThickness) / 2 + Scale * i));
				target.draw(grid);
				grid.setPosition(sf::Vector2f(Field.getPosition().x, Field.getPosition().y + (Field.getSize().y - GridThickness) / 2 - Scale * i));
				target.draw(grid);



				segment.setSize(sf::Vector2f(SegemntSize.y, SegemntSize.x));
				segment.setFillColor(AxesColor);

				segment.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y) / 2, Field.getPosition().y + (Field.getSize().y - SegemntSize.x) / 2 + Scale * i));
				target.draw(segment);
				segment.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y) / 2, Field.getPosition().y + (Field.getSize().y - SegemntSize.x) / 2 - Scale * i));
				target.draw(segment);

			}

			target.draw(X_axis);
			target.draw(Y_axis);

			if (ShowFunction) {


				sf::VertexArray Graph = sf::VertexArray(sf::LineStrip);

				bool t = true;

				for (float i = FunctionScope.x; i < FunctionScope.y && t; i += 1 / Scale) {

					float Y = CalculateY(i);

					sf::Vector2f pos = sf::Vector2f(Field.getPosition().x + (Field.getGlobalBounds().width + abs(i) / i * CoordinateAxisThickness) / 2 + i * Scale, Field.getPosition().y + (Field.getGlobalBounds().height - abs(Y) / Y * CoordinateAxisThickness) / 2 - Y * Scale);

					if (pos.x > Field.getGlobalBounds().left && pos.x < Field.getGlobalBounds().left + Field.getGlobalBounds().width) {

						if (pos.y > Field.getGlobalBounds().top && pos.y < Field.getGlobalBounds().top + Field.getGlobalBounds().height) {

							Graph.append(sf::Vertex(pos, GraphColor));
							continue;

						}

					}

					bool t = false;

				}

				target.draw(Graph);

			}

			return;

		}

		if (ShowSegments) {

			sf::RectangleShape segment;


			for (float i = 1; i * Scale < Field.getSize().x / 2; ++i) {

				segment.setSize(SegemntSize);
				segment.setFillColor(AxesColor);

				segment.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.x) / 2 + Scale * i, Field.getPosition().y + (Field.getSize().y - SegemntSize.y) / 2));
				target.draw(segment);
				segment.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.x) / 2 - Scale * i, Field.getPosition().y + (Field.getSize().y - SegemntSize.y) / 2));
				target.draw(segment);

			}

			for (float i = 1; i * Scale < Field.getSize().y / 2; ++i) {

				segment.setSize(sf::Vector2f(SegemntSize.y, SegemntSize.x));
				segment.setFillColor(AxesColor);

				segment.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y) / 2, Field.getPosition().y + (Field.getSize().y - SegemntSize.x) / 2 + Scale * i));
				target.draw(segment);
				segment.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y) / 2, Field.getPosition().y + (Field.getSize().y - SegemntSize.x) / 2 - Scale * i));
				target.draw(segment);

			}

			target.draw(X_axis);
			target.draw(Y_axis);

			if (ShowFunction) {


				sf::VertexArray Graph = sf::VertexArray(sf::LineStrip);

				bool t = true;

				for (float i = FunctionScope.x; i < FunctionScope.y && t; i += 1 / Scale) {

					float Y = CalculateY(i);

					sf::Vector2f pos = sf::Vector2f(Field.getPosition().x + (Field.getGlobalBounds().width + abs(i) / i * CoordinateAxisThickness) / 2 + i * Scale, Field.getPosition().y + (Field.getGlobalBounds().height - abs(Y) / Y * CoordinateAxisThickness) / 2 - Y * Scale);

					if (pos.x > Field.getGlobalBounds().left && pos.x < Field.getGlobalBounds().left + Field.getGlobalBounds().width) {

						if (pos.y > Field.getGlobalBounds().top && pos.y < Field.getGlobalBounds().top + Field.getGlobalBounds().height) {

							Graph.append(sf::Vertex(pos, GraphColor));
							continue;

						}

					}

					bool t = false;

				}

				target.draw(Graph);

			}

			return;

		}

	}

	if (ShowDigits) {

		if (ShowDigits && ShowGrid) {

			sf::RectangleShape grid;
			sf::Text digits = sf::Text("", DigitFont, DigitSize);
			digits.setFillColor(sf::Color::Blue);

			for (float i = 1; i * Scale < Field.getSize().x / 2; ++i) {


				grid.setSize(sf::Vector2f(GridThickness, Field.getSize().y));
				grid.setFillColor(GridColor);

				grid.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - GridThickness) / 2 + Scale * i, Field.getPosition().y));
				target.draw(grid);
				grid.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - GridThickness) / 2 - Scale * i, Field.getPosition().y));
				target.draw(grid);



				digits.setString(std::to_string(int(i)));
				digits.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y) / 2 + Scale * i, Field.getPosition().y + (Field.getSize().y - SegemntSize.y) / 2 + SegemntSize.y * 0.75));
				target.draw(digits);

				digits.setString(std::to_string(-int(i)));
				digits.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y * 2) / 2 - Scale * i, Field.getPosition().y + (Field.getSize().y - SegemntSize.y) / 2 + SegemntSize.y * 0.75));
				target.draw(digits);

			}

			for (float i = 1; i * Scale < Field.getSize().y / 2; ++i) {

				grid.setSize(sf::Vector2f(Field.getSize().x, GridThickness));
				grid.setFillColor(GridColor);

				grid.setPosition(sf::Vector2f(Field.getPosition().x, Field.getPosition().y + (Field.getSize().y - GridThickness) / 2 + Scale * i));
				target.draw(grid);
				grid.setPosition(sf::Vector2f(Field.getPosition().x, Field.getPosition().y + (Field.getSize().y - GridThickness) / 2 - Scale * i));
				target.draw(grid);



				digits.setString(std::to_string(int(i)));
				digits.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - digits.getCharacterSize()) / 2 - SegemntSize.y, Field.getPosition().y + (Field.getSize().y - SegemntSize.y * 2) / 2 - Scale * i));
				target.draw(digits);

				digits.setString(std::to_string(-int(i)));
				digits.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y * 2) / 2 - SegemntSize.y, Field.getPosition().y + (Field.getSize().y - SegemntSize.y * 2) / 2 + Scale * i));
				target.draw(digits);

			}

			target.draw(X_axis);
			target.draw(Y_axis);

			if (ShowFunction) {


				sf::VertexArray Graph = sf::VertexArray(sf::LineStrip);

				bool t = true;

				for (float i = FunctionScope.x; i < FunctionScope.y && t; i += 1 / Scale) {

					float Y = CalculateY(i);

					sf::Vector2f pos = sf::Vector2f(Field.getPosition().x + (Field.getGlobalBounds().width + abs(i) / i * CoordinateAxisThickness) / 2 + i * Scale, Field.getPosition().y + (Field.getGlobalBounds().height - abs(Y) / Y * CoordinateAxisThickness) / 2 - Y * Scale);

					if (pos.x > Field.getGlobalBounds().left && pos.x < Field.getGlobalBounds().left + Field.getGlobalBounds().width) {

						if (pos.y > Field.getGlobalBounds().top && pos.y < Field.getGlobalBounds().top + Field.getGlobalBounds().height) {

							Graph.append(sf::Vertex(pos, GraphColor));
							continue;

						}

					}

					bool t = false;

				}

				target.draw(Graph);

			}

			return;

		}

		if (ShowDigits) {

			sf::Text digits = sf::Text("", DigitFont, DigitSize);
			digits.setFillColor(sf::Color::Blue);

			for (float i = 1; i * Scale < Field.getSize().x / 2; ++i) {

				digits.setString(std::to_string(int(i)));
				digits.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y) / 2 + Scale * i, Field.getPosition().y + (Field.getSize().y - SegemntSize.y) / 2 + SegemntSize.y * 0.75));
				target.draw(digits);

				digits.setString(std::to_string(-int(i)));
				digits.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y * 2) / 2 - Scale * i, Field.getPosition().y + (Field.getSize().y - SegemntSize.y) / 2 + SegemntSize.y * 0.75));
				target.draw(digits);

			}

			for (float i = 1; i * Scale < Field.getSize().y / 2; ++i) {

				digits.setString(std::to_string(int(i)));
				digits.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - digits.getCharacterSize()) / 2 - SegemntSize.y, Field.getPosition().y + (Field.getSize().y - SegemntSize.y * 2) / 2 - Scale * i));
				target.draw(digits);

				digits.setString(std::to_string(-int(i)));
				digits.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - SegemntSize.y * 2) / 2 - SegemntSize.y, Field.getPosition().y + (Field.getSize().y - SegemntSize.y * 2) / 2 + Scale * i));
				target.draw(digits);

			}

			target.draw(X_axis);
			target.draw(Y_axis);

			if (ShowFunction) {


				sf::VertexArray Graph = sf::VertexArray(sf::LineStrip);

				bool t = true;

				for (float i = FunctionScope.x; i < FunctionScope.y && t; i += 1 / Scale) {

					float Y = CalculateY(i);

					sf::Vector2f pos = sf::Vector2f(Field.getPosition().x + (Field.getGlobalBounds().width + abs(i) / i * CoordinateAxisThickness) / 2 + i * Scale, Field.getPosition().y + (Field.getGlobalBounds().height - abs(Y) / Y * CoordinateAxisThickness) / 2 - Y * Scale);

					if (pos.x > Field.getGlobalBounds().left && pos.x < Field.getGlobalBounds().left + Field.getGlobalBounds().width) {

						if (pos.y > Field.getGlobalBounds().top && pos.y < Field.getGlobalBounds().top + Field.getGlobalBounds().height) {

							Graph.append(sf::Vertex(pos, GraphColor));
							continue;

						}

					}

					bool t = false;

				}

				target.draw(Graph);

			}

			return;

		}

	}

	if (ShowGrid) {

		sf::RectangleShape grid;

		for (float i = 1; i * Scale < Field.getSize().x / 2; ++i) {

			grid.setSize(sf::Vector2f(GridThickness, Field.getSize().y));
			grid.setFillColor(GridColor);

			grid.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - GridThickness) / 2 + Scale * i, Field.getPosition().y));
			target.draw(grid);
			grid.setPosition(sf::Vector2f(Field.getPosition().x + (Field.getSize().x - GridThickness) / 2 - Scale * i, Field.getPosition().y));
			target.draw(grid);

		}

		for (float i = 1; i * Scale < Field.getSize().y / 2; ++i) {

			grid.setSize(sf::Vector2f(Field.getSize().x, GridThickness));
			grid.setFillColor(GridColor);

			grid.setPosition(sf::Vector2f(Field.getPosition().x, Field.getPosition().y + (Field.getSize().y - GridThickness) / 2 + Scale * i));
			target.draw(grid);
			grid.setPosition(sf::Vector2f(Field.getPosition().x, Field.getPosition().y + (Field.getSize().y - GridThickness) / 2 - Scale * i));
			target.draw(grid);

		}

		target.draw(X_axis);
		target.draw(Y_axis);

		if (ShowFunction) {


			sf::VertexArray Graph = sf::VertexArray(sf::LineStrip);

			bool t = true;

			for (float i = FunctionScope.x; i < FunctionScope.y && t; i += 1 / Scale) {

				float Y = CalculateY(i);

				sf::Vector2f pos = sf::Vector2f(Field.getPosition().x + (Field.getGlobalBounds().width + abs(i) / i * CoordinateAxisThickness) / 2 + i * Scale, Field.getPosition().y + (Field.getGlobalBounds().height - abs(Y) / Y * CoordinateAxisThickness) / 2 - Y * Scale);

				if (pos.x > Field.getGlobalBounds().left && pos.x < Field.getGlobalBounds().left + Field.getGlobalBounds().width) {

					if (pos.y > Field.getGlobalBounds().top && pos.y < Field.getGlobalBounds().top + Field.getGlobalBounds().height) {

						Graph.append(sf::Vertex(pos, GraphColor));
						continue;

					}

				}

				bool t = false;

			}

			target.draw(Graph);

		}

		return;

	}

	if (ShowFunction) {


		sf::VertexArray Graph = sf::VertexArray(sf::LineStrip);

		bool t = true;

		for (float i = FunctionScope.x; i < FunctionScope.y && t; i += 1 / Scale) {

			float Y = CalculateY(i);

			sf::Vector2f pos = sf::Vector2f(Field.getPosition().x + (Field.getGlobalBounds().width + abs(i) / i * CoordinateAxisThickness) / 2 + i * Scale, Field.getPosition().y + (Field.getGlobalBounds().height - abs(Y) / Y * CoordinateAxisThickness) / 2 - Y * Scale);

			if (pos.x > Field.getGlobalBounds().left && pos.x < Field.getGlobalBounds().left + Field.getGlobalBounds().width) {

				if (pos.y > Field.getGlobalBounds().top && pos.y < Field.getGlobalBounds().top + Field.getGlobalBounds().height) {

					Graph.append(sf::Vertex(pos, GraphColor));
					continue;

				}

			}

			bool t = false;

		}

		target.draw(Graph);
		return;

	}

}


Coordinate_system::Coordinate_system(sf::Vector2f pos, sf::Vector2f size) {

	Field.setPosition(pos);
	Field.setSize(size);
	Field.setFillColor(FieldColor);

	X_axis.setSize(sf::Vector2f(Field.getGlobalBounds().width, CoordinateAxisThickness));
	X_axis.setPosition(sf::Vector2f(pos.x, pos.y + (Field.getGlobalBounds().height - CoordinateAxisThickness) / 2));
	X_axis.setFillColor(AxesColor);

	Y_axis.setSize(sf::Vector2f(CoordinateAxisThickness, Field.getGlobalBounds().height));
	Y_axis.setPosition(sf::Vector2f(pos.x + (Field.getGlobalBounds().width - CoordinateAxisThickness) / 2, pos.y));
	Y_axis.setFillColor(AxesColor);

	MaxScope = sf::Vector2f(-Field.getSize().x / Scale / 2, Field.getSize().x / Scale / 2);

}


float Coordinate_system::CalculateY(float x, std::string function) {


	if (!function.empty()) {



	}





	return pow(x, x);

}






