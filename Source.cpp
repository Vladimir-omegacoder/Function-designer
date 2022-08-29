#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Coordinate_system.h"
#include "Check_box.h"
#include <iostream>





int main() {


	sf::RenderWindow Main_window(sf::VideoMode(1000, 800), "Fucntion designer");
	sf::Color BackGroundColor = sf::Color(50,39,39);
	sf::Font MainFont;
	Main_window.setVerticalSyncEnabled(true);
	MainFont.loadFromFile("D:/My projects/Development projects/Function designer/x64/Fonts/calibri.ttf"); //choose the path to your font
	
	Button ShowFunc = Button(sf::Vector2f(400, 600), sf::Vector2f(200, 100), sf::Color(66, 97, 61));
	ShowFunc.SetTextAttributes("Draw function", 20, MainFont);
	Button ClearField = Button(sf::Vector2f(100, 600), sf::Vector2f(200, 100), sf::Color(176, 59, 59));
	ClearField.SetTextAttributes("Clear", 20, MainFont);

	Coordinate_system CordSys = Coordinate_system(sf::Vector2f(50, 50), sf::Vector2f(600, 500));
	CordSys.DigitFont = MainFont;
	CordSys.FunctionScope = CordSys.MaxScope;


	float CheckBoxSize = 25;
	Check_box CheckShowGrid = Check_box(sf::Vector2f(700, 100), sf::Vector2f(CheckBoxSize, CheckBoxSize));
	sf::Text ShowGrid = sf::Text("Show grid", MainFont, CheckBoxSize - 5);
	ShowGrid.setPosition(700 + CheckBoxSize + 10, 100);

	Check_box CheckShowDigits = Check_box(sf::Vector2f(700, 200), sf::Vector2f(CheckBoxSize, CheckBoxSize));
	sf::Text ShowDigits = sf::Text("Show digits", MainFont, CheckBoxSize - 5);
	ShowDigits.setPosition(700 + CheckBoxSize + 10, 200);

	Check_box CheckShowSegments = Check_box(sf::Vector2f(700, 300), sf::Vector2f(CheckBoxSize, CheckBoxSize));
	sf::Text ShowSegments = sf::Text("Show segments", MainFont, CheckBoxSize - 5);
	ShowSegments.setPosition(700 + CheckBoxSize + 10, 300);

	



	
	while (Main_window.isOpen()) {


		sf::Event Main_event;


		//Background
		Main_window.clear(BackGroundColor);

		//Coordinate system
		Main_window.draw(CordSys);

		//Buttons
		Main_window.draw(ShowFunc);
		Main_window.draw(ClearField);

		//Checkboxes and text
		Main_window.draw(CheckShowGrid);
		Main_window.draw(ShowGrid);

		Main_window.draw(CheckShowDigits);
		Main_window.draw(ShowDigits);

		Main_window.draw(CheckShowSegments);
		Main_window.draw(ShowSegments);

		//Display
		Main_window.display();


		while (Main_window.pollEvent(Main_event)) {


			if (Main_event.type == sf::Event::Closed) {

				Main_window.close();

			}

			
			if (Main_event.type == sf::Event::MouseMoved) {

				if (ShowFunc.CursorInsideButton(sf::Vector2f(Main_event.mouseMove.x, Main_event.mouseMove.y))) {

					if (!ShowFunc.GetState()) {

						ShowFunc.SetActive();
						break;

					}

				}
				else {

					if (ShowFunc.GetState()) {

						ShowFunc.SetNotActive();
						break;

					}

				}

				if (ClearField.CursorInsideButton(sf::Vector2f(Main_event.mouseMove.x, Main_event.mouseMove.y))) {

					if (!ClearField.GetState()) {

						ClearField.SetActive();
						break;

					}

				}
				else {

					if (ClearField.GetState()) {

						ClearField.SetNotActive();
						break;

					}

				}


				if (CheckShowGrid.CursorInsideCheckBox(sf::Vector2f(Main_event.mouseMove.x, Main_event.mouseMove.y))) {

					if (!CheckShowGrid.GetState()) {

						CheckShowGrid.SetActiveLook();
						break;

					}

				}
				else {

					if (CheckShowGrid.GetState()) {

						CheckShowGrid.SetNotActiveLook();
						break;

					}

				}

				if (CheckShowDigits.CursorInsideCheckBox(sf::Vector2f(Main_event.mouseMove.x, Main_event.mouseMove.y))) {

					if (!CheckShowDigits.GetState()) {

						CheckShowDigits.SetActiveLook();
						break;

					}

				}
				else {

					if (CheckShowDigits.GetState()) {

						CheckShowDigits.SetNotActiveLook();
						break;

					}

				}

				if (CheckShowSegments.CursorInsideCheckBox(sf::Vector2f(Main_event.mouseMove.x, Main_event.mouseMove.y))) {

					if (!CheckShowSegments.GetState()) {

						CheckShowSegments.SetActiveLook();
						break;

					}

				}
				else {

					if (CheckShowSegments.GetState()) {

						CheckShowSegments.SetNotActiveLook();
						break;

					}

				}

			}
			

			if (Main_event.type == sf::Event::MouseButtonPressed) {

				if (Main_event.text.unicode == sf::Mouse::Button::Left) {

					if (ShowFunc.GetState()) {

						CordSys.ShowFunction = true;
						break;

					}
					if (ClearField.GetState()) {

						CordSys.ShowFunction = false;
						break;

					}


					if (CheckShowGrid.GetState()) {

						CheckShowGrid.CheckBoxClick();
						CordSys.ShowGrid = CheckShowGrid.Checked;
						break;

					}

					if (CheckShowDigits.GetState()) {

						CheckShowDigits.CheckBoxClick();
						CordSys.ShowDigits = CheckShowDigits.Checked;
						break;

					}

					if (CheckShowSegments.GetState()) {

						CheckShowSegments.CheckBoxClick();
						CordSys.ShowSegments = CheckShowSegments.Checked;
						break;

					}
				}

			}
			
		}

		

	}



	return 0;

}







