#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>
#include <sstream>

using namespace std;
using namespace sf;

int main() {

	sf::ContextSettings antialiasing;//keskinlik
	antialiasing.antialiasingLevel = 8;

	RenderWindow window(VideoMode(800, 500),"Gosterge Simulasyon", sf::Style::Default,antialiasing);//pencere aç

	Player player;//nesne
	Yardim yardim;

	int hiz=0;
	float alinanYol = 0;

	sf::Font font;//yazý font 
	font.loadFromFile("arial.ttf");
	sf::Text hizText;
	hizText.setFont(font);
	hizText.setColor(sf::Color::White);
	hizText.setPosition(380, 335);
	sf::Text alinanYolText;
	alinanYolText.setFont(font);
	alinanYolText.setColor(sf::Color::White);
	alinanYolText.setPosition(365, 320);
	alinanYolText.setCharacterSize(12);

	sf::RectangleShape ibreHizAci;//hýz için sanal ibre
	ibreHizAci.setSize(sf::Vector2f(100, 5));
	ibreHizAci.setRotation(160);
	ibreHizAci.setPosition(sf::Vector2f(622, 278));

	while (window.isOpen())
	{

		window.setKeyRepeatEnabled(false);//keyrepeat kapalý

		Event event;  
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)// kapama tuþuna basýlýnca program kapansýn
				window.close();

		}
		
		std::stringstream ss1;
		ss1 << hiz;
		std::stringstream ss2;
		ss2 << alinanYol;

		hizText.setString(ss1.str());
		alinanYolText.setString(ss2.str());

		player.draw(window);
		
		window.draw(hizText);
		window.draw(alinanYolText);
		
		
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				
				ibreHizAci.setRotation(ibreHizAci.getRotation() + 0.05);
				float aci = ibreHizAci.getRotation();
				if (aci > 16 && aci<160) ibreHizAci.setRotation(15);
				if (aci > 160) aci = aci - 160;
				else if (aci <= 16) aci = aci + 199;

				player.hizArtir();
				
				hiz = aci;

				alinanYol =alinanYol+ (aci/12960000);

			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

				ibreHizAci.setRotation(ibreHizAci.getRotation() - 0.05);
				int aci = ibreHizAci.getRotation();
				if (aci>16 && aci < 160) ibreHizAci.setRotation(160);
				if (aci >= 160) aci = aci - 160;
				else if (aci <= 16) aci = aci + 199;

				player.hizAzalt();

				hiz = aci;

				alinanYol = alinanYol + (aci / 1296000);

			}

			else {
				ibreHizAci.setRotation(ibreHizAci.getRotation() - 0.0065);
				int aci1 = ibreHizAci.getRotation();
				if (aci1>16 && aci1 < 160) ibreHizAci.setRotation(161);
				if (aci1 >= 160) aci1 = aci1 - 160;
				else if (aci1 <= 16) aci1 = aci1 + 199;

				player.hizBosta();

				hiz = aci1;
				
			}

			
		}

		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

					player.sagSinyal();
				
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {

				player.arabaKilit();

			}
			
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

				player.solSinyal();

			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {

				player.yakitDoldur();

			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

				player.fren();

			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){

				player.yolFari();

			}
			
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)){

				player.sisFari();

			}
			
			

		}
		
		window.display();

	}
		
	
	return 0;

}