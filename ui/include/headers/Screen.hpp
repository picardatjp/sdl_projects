#ifndef SCREEN_H
#define SCREEN_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

// our game class that handles basically everything
class Screen
{
private:
    // true if the game is running, false if not
    bool isRunning;
    // our game window
    SDL_Window *window;
    int WINDOW_HEIGHT = 600;
    int WINDOW_WIDTH = 900;

public:
    // constructor and destructor
    Screen();
    ~Screen();

    // init declaration, this starts up the game
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    // handles events
    void handleEvents();
    // updates game objects
    void update();
    // refreshes screen with updated info
    void render();
    // cleans game memory and stops SDL
    void clean();

    // returns whether the game is currently running or not
    bool running() { return isRunning; }

    int getWinHeight() { return WINDOW_HEIGHT; }
    int getWinWidth() { return WINDOW_WIDTH; }

    // our game renderer
    static SDL_Renderer *renderer;
};

#endif