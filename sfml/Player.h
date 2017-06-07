#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player 
{
public:
	Player();
	~Player();

	void draw(sf::RenderWindow &window);
	void hizArtir();
	void hizAzalt();
	void hizBosta();
	void sagSinyal();
	void arabaKilit();
	void solSinyal();
	void yakitDoldur();
	void fren();
	void yolFari();
	void sisFari();
	int sayac;

private:

	sf::RectangleShape ibreHýz;
	sf::RectangleShape ibreHararet;
	sf::RectangleShape ibreSicaklik;
	sf::Texture ssinyalTexture;
	sf::Sprite ssinyalSprite;
	sf::Texture sicaklikGosterge;
	sf::Sprite sicaklikGostergeSprite;
	sf::Texture absGosterge;
	sf::Sprite absGostergeSprite;
protected:

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Image backgroundImage;
	sf::RectangleShape ibreBenzin;
	sf::Texture benzinGosterge;
	sf::Sprite benzinGostergeSprite;
	sf::Texture yardimTexture;
	sf::Sprite yardimSprite;
};

class Yardim : public Player {

public:

	

};
