#include "gameState.hpp"

GameState::GameState(Shared &shared) :
State(shared)
{
}
GameState::~GameState()
{
}

void GameState::init(void)
{

}

void GameState::destroy(void)
{
}

void GameState::pause(void)
{
}

void GameState::resume(void)
{
}

State::Next GameState::update(void)
{
    sf::Event event;
    while(app.GetEvent(event))
    {
        if(event.Type == sf::Event::Closed)
        {
            return State::Quit;
        }
        if(event.Type == sf::Event::KeyPressed)
        {
            if(event.Key.Code == sf::Key::Escape)
            {
                return State::Menu;
            }
        }
    }

    return State::NoChange;
}

void GameState::draw(void) const
{
    app.Clear();
}
