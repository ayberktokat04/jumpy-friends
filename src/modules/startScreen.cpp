#include "startScreen.hpp"

Vector2 gameLogoPosition = (Vector2){50.f, 50.f};
int gameLogoFontSize = 40;

void draw() {
    DrawText("Jumpy Frıends", gameLogoPosition.x, gameLogoPosition.y, gameLogoFontSize, LIGHTGRAY);
}