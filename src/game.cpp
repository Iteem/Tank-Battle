#include "game.hpp"
#include "shared.hpp"
#include "state.hpp"

#include "introState.hpp"
#include "menuState.hpp"
#include "gameState.hpp"

Game::Game(int argc, char **argv)
{
}

Game::~Game()
{
}

int Game::run(void)
{
    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "Bla");
    Shared shared(app);
    State *state;

    state = new IntroState(shared);
    state->init();

    while(true)
    {
        switch(state->update())
        {
            case State::NoChange:
                break;

            case State::Menu:
                state->destroy();
                delete state;
                state = new MenuState(shared);
                state->init();
                break;

            case State::Game:
                state->destroy();
                delete state;
                state = new GameState(shared);
                state->init();
                break;

            default:
                delete state;
                return 0;
        }

        state->draw();
    }
}
