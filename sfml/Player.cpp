#include "Player.h"	
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>



Player::Player()
{		

	if (!backgroundTexture.loadFromFile("resim1.bmp"))
		std::cout << "yukelenemedi";					//arkaplan göstergesi
	
	if (!backgroundImage.loadFromFile("resim1.bmp"))
		std::cout << "yuklenemedi";

	if (!benzinGosterge.loadFromFile("benzin.bmp"))
		std::cout << "yuklenemedi";

	if (!sicaklikGosterge.loadFromFile("sicakliksinyal.bmp"))
		std::cout << "yuklenemedi";
	
	if (!absGosterge.loadFromFile("abs.bmp"))
		std::cout << "yuklenemedi";

	sicaklikGostergeSprite.setTexture(sicaklikGosterge);
	benzinGostergeSprite.setTexture(benzinGosterge);
	backgroundSprite.setTexture(backgroundTexture);	
	absGostergeSprite.setTexture(absGosterge);

	ibreHýz.setSize(sf::Vector2f(100,5));
	ibreHýz.setRotation(160);
	ibreHýz.setPosition(sf::Vector2f(622, 278));

	ibreHararet.setSize(sf::Vector2f(100, 5));
	ibreHararet.setRotation(160);
	ibreHararet.setPosition(182, 278);

	ibreBenzin.setSize(sf::Vector2f(25, 3));
	ibreBenzin.setRotation(320);
	ibreBenzin.setPosition(456, 164);

	ibreSicaklik.setSize(sf::Vector2f(25, 3));
	ibreSicaklik.setRotation(220);
	ibreSicaklik.setPosition(348, 164);

	absGostergeSprite.setPosition(235, 260);

}


Player::~Player()
{
}


void Player::draw(sf::RenderWindow &window) {

	sf::Event event;

	window.draw(backgroundSprite);
	window.draw(ibreHýz);
	window.draw(ibreHararet);
	window.draw(ibreBenzin);
	window.draw(ibreSicaklik);

	if (ibreBenzin.getRotation() < 250) {

		window.draw(benzinGostergeSprite);
		benzinGostergeSprite.setPosition(440, 185);
		

	}

	if (ibreSicaklik.getRotation() > 310) {

		window.draw(sicaklikGostergeSprite);
		sicaklikGostergeSprite.setPosition(340, 185);

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
		window.draw(absGostergeSprite);

}
void Player::hizArtir() {

	ibreHýz.setRotation(ibreHýz.getRotation() + 0.05);
	ibreHararet.setRotation(ibreHararet.getRotation() + 0.02);
	ibreBenzin.setRotation(ibreBenzin.getRotation() - 0.005);
	ibreSicaklik.setRotation(ibreSicaklik.getRotation() + 0.005);

	if (ibreHýz.getRotation()>16 && ibreHýz.getRotation()<160) {

		ibreHýz.setRotation(16);

	}

	if (ibreHararet.getRotation() > 16 && ibreHararet.getRotation() < 160) {

		ibreHararet.setRotation(16);

	}

	if (ibreBenzin.getRotation() < 220) {

		ibreBenzin.setRotation(220);


	}

	if (ibreSicaklik.getRotation() > 320) {

		ibreSicaklik.setRotation(320);

	}


}

void Player::hizAzalt() {

	ibreHýz.setRotation(ibreHýz.getRotation() - 0.05);
	ibreHararet.setRotation(ibreHararet.getRotation() - 0.01);

	if (ibreHýz.getRotation() > 16 && ibreHýz.getRotation() < 160) {

		ibreHýz.setRotation(160);

	}

	if (ibreHararet.getRotation() > 16 && ibreHararet.getRotation() < 160) {

		ibreHararet.setRotation(160);
		
	}

	

}

void Player::hizBosta() {

	ibreHýz.setRotation(ibreHýz.getRotation() - 0.0065);
	ibreHararet.setRotation(ibreHararet.getRotation() - 0.01);
	ibreSicaklik.setRotation(ibreSicaklik.getRotation() - 0.003);

	if (ibreHýz.getRotation() > 16 && ibreHýz.getRotation() < 160) {

		ibreHýz.setRotation(160);

	}

	if (ibreHararet.getRotation() > 16 && ibreHararet.getRotation() < 160) {

		ibreHararet.setRotation(160);

	}

	if (ibreSicaklik.getRotation() < 220) {

		ibreSicaklik.setRotation(220);

	}


}

void Player::sagSinyal() {

	sf::Image sagSinyal;
	
	if (!sagSinyal.loadFromFile("sagsinyal.bmp"))

		std::cout << "dasfas";

	sayac++;

	if (sayac %2 != 0) {

		backgroundTexture.update(sagSinyal,510,128);

	}

	else if (sayac%2==0){

		backgroundTexture.update(backgroundImage, 0, 0);

	}


}

void Player::arabaKilit() {

	sf::Image arabaKilit;

	if (!arabaKilit.loadFromFile("arabakilit.bmp"))

		std::cout << "dafdsf";

	sayac++;

	if (sayac % 2 != 0) {

		backgroundTexture.update(arabaKilit, 535, 315);

	}

	else if (sayac % 2 == 0){

		backgroundTexture.update(backgroundImage, 0, 0);
		
	}
}

void Player::solSinyal() {

	sf::Image solSinyal;

	if (!solSinyal.loadFromFile("solsinyal.bmp"))
		std::cout << "yuklenemedi";
	
	sayac++;

	if (sayac % 2 != 0) {

		backgroundTexture.update(solSinyal,260,128);

	}

	else if (sayac % 2 == 0){

		backgroundTexture.update(backgroundImage, 0, 0);

	}

}

void Player::yakitDoldur() {

	ibreBenzin.setRotation(315);

}

void Player::fren() {

	sf::Image fren;
	if (!fren.loadFromFile("brake.bmp"))
		std::cout << "yuklenemedi";

	sayac++;

	if (sayac % 2 != 0) {

		backgroundTexture.update(fren, 155, 345);
	
	}

	else if (sayac % 2 == 0) {

		backgroundTexture.update(backgroundImage, 0, 0);

	}

}

void Player::yolFari() {

	sf::Image yolFari;

	if (!yolFari.loadFromFile("solfar.bmp"))
		std::cout << "yujlenemedi";

	sayac++;

	if (sayac % 2 != 0) {

		backgroundTexture.update(yolFari, 525, 345);

	}

	else if (sayac % 2 == 0){

		backgroundTexture.update(backgroundImage, 0, 0);

	}


}

void Player::sisFari() {

	sf::Image sisFari;

	if (!sisFari.loadFromFile("sagfar.bmp"))
		std::cout << "yuklenemedi";

	sayac++;

	if (sayac % 2 != 0) {

		backgroundTexture.update(sisFari, 560, 345);

	}

	else if (sayac % 2 == 0) {
	
		backgroundTexture.update(backgroundImage, 0, 0);

	}

}

 
