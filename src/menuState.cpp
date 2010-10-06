#include "menuState.hpp"

MenuState::MenuState(Shared &shared) :
State(shared)
{
}
MenuState::~MenuState()
{
}

void MenuState::init(void)
{
    quit = false;
	start = false;

	app.ShowMouseCursor(false);

    //create GUI
    myGUI = new sfg::GUI(sf::FloatRect(0,0,800,600));
    myGUI->LoadSkinFromFile("data/menu/skins/black.skin");

    //create Buttons
    quitButton  = sfg::Button::Create(sf::FloatRect(0, 0, 80, 35), "Quit" );
    startButton = sfg::Button::Create(sf::FloatRect(0, 0, 80, 35), "Start");

    quitButton->Clicked  = sfg::Slot<sfg::Button::ClickSlot>(&MenuState::onQuitClicked,  this);
    startButton->Clicked = sfg::Slot<sfg::Button::ClickSlot>(&MenuState::onStartClicked, this);

    sfg::AlignWidgetInRect(
		*quitButton,
		sf::FloatRect(myGUI->GetRect()),
		sfg::AlignCenter | sfg::AlignBottom,
		sf::Vector2f( 5, 5 )
	);
    sfg::AlignWidgetInRect(
		*startButton,
		sf::FloatRect(myGUI->GetRect()),
		sfg::AlignCenter | sfg::AlignTop,
		sf::Vector2f( 5, 5 )
	);

	//and add them to the GUI
	myGUI->AddWidget(quitButton);
	myGUI->AddWidget(startButton);
}

void MenuState::destroy(void)
{
    app.ShowMouseCursor(true);
    delete myGUI;
}

void MenuState::pause(void)
{
}

void MenuState::resume(void)
{
}

State::Next MenuState::update(void)
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
                return State::Quit;
            }
        }

        //update the GUI
        myGUI->HandleEvent(event);
    }

    //check if we need to quit or start the game
    if(start)
    {
        return State::Game;
    }
    if(quit)
    {
        return State::Quit;
    }

    return State::NoChange;
}

void MenuState::draw(void) const
{
    app.Clear(sf::Color::White);

    myGUI->Render(app);
}

void MenuState::onQuitClicked(sfg::Widget::Ptr widget)
{
    quit = true;
}

void MenuState::onStartClicked(sfg::Widget::Ptr widget)
{
    start = true;
}
