#include "sfml_button.hpp"

//unsigned int Button::count = 0;

void Button::setButtonFont(sf::Font& font){//ставлю шрифт
    buttonLabel.setFont(font);
}