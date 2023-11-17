// zavd_94.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Character {
public:
    char symbol;
    int size;
    string font;

    Character(char symbol_, int size_, string font_) : symbol(symbol_), size(size_), font(font_) {}
};

class CharacterFactory {
private:
    map<char, Character*> characters;

public:
    Character* getCharacter(char key, int size, string font) {
        if (characters.find(key) == characters.end()) {
            characters[key] = new Character(key, size, font);
        }
        return characters[key];
    }
};

int main() {
    CharacterFactory* factory = new CharacterFactory();

    string text = "Hello, world!";
    int size = 12;
    string font = "Arial";

    for (char& c : text) {
        Character* character = factory->getCharacter(c, size, font);
        cout << "Symbol: " << character->symbol << ", Size: " << character->size << ", Font: " << character->font << endl;
    }

    delete factory;
}
