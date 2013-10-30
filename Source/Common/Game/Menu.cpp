#include "Menu.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include <string>

Menu::Menu()
{
	set(MENU_TITLE_MAIN, false);
}

Menu::Menu(const std::string menuName)
{

	m_Textures.push_back(new Button(BUTTON_SINGLE_PLAYER));
	m_Textures.push_back(new Button(BUTTON_TWO_PLAYER));
	m_Textures.push_back(new Button(BUTTON_CREDITS));
	m_Textures.push_back(new Button(BUTTON_EXIT));
	m_Textures.push_back(new Button(BUTTON_SPLASH));
	m_Textures.push_back(new Button(BUTTON_RESUME));
	m_Textures.push_back(new Button(BUTTON_RESTART));
	m_Textures.push_back(new Button(BUTTON_GAME_SETTINGS));

	m_Textures.push_back(new Button(BUTTON_TIME_LIMIT_1));
	m_Textures.push_back(new Button(BUTTON_TIME_LIMIT_3));
	m_Textures.push_back(new Button(BUTTON_TIME_LIMIT_5));

	m_Textures.push_back(new Button(BUTTON_UNLIMITED));

	m_Textures.push_back(new Button(BUTTON_SCORE_LIMIT_3));
	m_Textures.push_back(new Button(BUTTON_SCORE_LIMIT_5));
	m_Textures.push_back(new Button(BUTTON_SCORE_LIMIT_9));

	m_Textures.push_back(new Button(BUTTON_EASY));
	m_Textures.push_back(new Button(BUTTON_MEDIUM));
	m_Textures.push_back(new Button(BUTTON_HARD));

	m_Textures.push_back(new Button(BUTTON_MOUSE));
	m_Textures.push_back(new Button(BUTTON_KEYBOARD_1));
	m_Textures.push_back(new Button(BUTTON_KEYBOARD_2));

	m_Textures.push_back(new Button(BUTTON_BACK));
	m_Textures.push_back(new Button(BUTTON_START));
	m_Textures.push_back(new Button(BUTTON_MAIN_MENU));

	m_Background = new OpenGLTexture(MENU_BACKGROUND_MAIN);

	if(menuName == MENU_TITLE_MAIN)
	{
		set(MENU_TITLE_MAIN, false);
	}
	else if(menuName == MENU_TITLE_SPLASH)
	{
		set(MENU_TITLE_SPLASH, true);
	}
	else if(menuName == MENU_TITLE_PAUSE)
	{
		set(MENU_TITLE_PAUSE, false);
	}
	else if(menuName == MENU_TITLE_SETTINGS_SP)
	{
		set(MENU_TITLE_SETTINGS_SP, false);
	}
	else if(menuName == MENU_TITLE_SETTINGS_MP)
	{
		set(MENU_TITLE_SETTINGS_MP, false);
	}
	else if(menuName == MENU_TITLE_CREDITS)
	{
		set(MENU_TITLE_CREDITS, false);
	}
	else if(menuName == MENU_TITLE_GAMEOVER)
	{
		set(MENU_TITLE_GAMEOVER, false);
	}
}

Menu::~Menu()
{
	// Delete background texture
	if(m_Background != NULL)
	{
		delete m_Background;
		m_Background = NULL;
	}

	// Delete all textures in the vector
	for(int i = 0; i < m_Textures.size(); i++)
    {
        delete m_Textures.at(i);
        m_Textures.at(i) = NULL;
    }
	
	m_Textures.clear();
}

void Menu::handleKeyboardInput(int aKeyCode)
{
	//TODO; finish this shit
	switch(aKeyCode)
	{
		
	}
}

void Menu::checkCollision(float x, float y)
{
	//TODO: cycle through buttons and check collision when mouse is clicked
	for(int i = 0; i < m_Textures.size(); i++)
	{
		// IF the button is active
		if(m_Textures.at(i)->isActive())
		{
			// If collision occured
			if(m_Textures.at(i)->checkCollision(x, y))
			{
				// Get the name of the button
				if(m_Textures.at(i)->getName() == BUTTON_SPLASH)
				{
					// Go to main menu
					set(MENU_TITLE_MAIN, true);
				}
				else if(m_Textures.at(i)->getName() == BUTTON_SINGLE_PLAYER)
				{
					// Go to single player game setting menu
					set(MENU_TITLE_SETTINGS_SP, true);
				}
				else if(m_Textures.at(i)->getName() == BUTTON_TWO_PLAYER)
				{
					// go to two player game settings menu
					set(MENU_TITLE_SETTINGS_MP, true);
				}
				else if(m_Textures.at(i)->getName() == BUTTON_CREDITS)
				{
					// go to the credits
					set(MENU_TITLE_CREDITS, true);
				}
				else if(m_Textures.at(i)->getName() == BUTTON_RESUME)
				{
					// close the menu
					setActive(false);
				}
				else if(m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_1)
				{
					// Show the next time texture
					m_Textures.at(i)->setActive(false);
					for(int i = 0; i < m_Textures.size(); i++)
					{
						if(m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_3)
						{
							m_Textures.at(i)->setActive(true);
							return;
						}
					}
				}
				else if(m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_3)
				{
					// Show the next time texture
					m_Textures.at(i)->setActive(false);
					for(int i = 0; i < m_Textures.size(); i++)
					{
						if(m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_5)
						{
							m_Textures.at(i)->setActive(true);
							return;
						}
					}
				}
				else if(m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_5)
				{
					// Show the next time texture
					m_Textures.at(i)->setActive(false);
					for(int i = 0; i < m_Textures.size(); i++)
					{
						if(m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_1)
						{
							m_Textures.at(i)->setActive(true);
							return;
						}
					}
				}
				else if(m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_3)
				{
					// Show the next time texture
					m_Textures.at(i)->setActive(false);
					for(int i = 0; i < m_Textures.size(); i++)
					{
						if(m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_5)
						{
							m_Textures.at(i)->setActive(true);
							return;
						}
					}
				}
				else if(m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_5)
				{
					// Show the next time texture
					m_Textures.at(i)->setActive(false);
					for(int i = 0; i < m_Textures.size(); i++)
					{
						if(m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_9)
						{
							m_Textures.at(i)->setActive(true);
							return;
						}
					}
				}
				else if(m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_9)
				{
					// Show the next time texture
					m_Textures.at(i)->setActive(false);
					for(int i = 0; i < m_Textures.size(); i++)
					{
						if(m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_3)
						{
							m_Textures.at(i)->setActive(true);
							return;
						}
					}
				}
				else if(m_Textures.at(i)->getName() == BUTTON_EASY)
				{
					// Show the next time texture
					m_Textures.at(i)->setActive(false);
					for(int i = 0; i < m_Textures.size(); i++)
					{
						if(m_Textures.at(i)->getName() == BUTTON_MEDIUM)
						{
							m_Textures.at(i)->setActive(true);
							return;
						}
					}
				}
				else if(m_Textures.at(i)->getName() == BUTTON_MEDIUM)
				{
					// Show the next time texture
					m_Textures.at(i)->setActive(false);
					for(int i = 0; i < m_Textures.size(); i++)
					{
						if(m_Textures.at(i)->getName() == BUTTON_HARD)
						{
							m_Textures.at(i)->setActive(true);
							return;
						}
					}
				}
				else if(m_Textures.at(i)->getName() == BUTTON_HARD)
				{
					// Show the next time texture
					m_Textures.at(i)->setActive(false);
					for(int i = 0; i < m_Textures.size(); i++)
					{
						if(m_Textures.at(i)->getName() == BUTTON_EASY)
						{
							m_Textures.at(i)->setActive(true);
							return;
						}
					}
				}
				else if(m_Textures.at(i)->getName() == BUTTON_MOUSE)
				{
					// Show the next time texture
					m_Textures.at(i)->setActive(false);
					for(int i = 0; i < m_Textures.size(); i++)
					{
						if(m_Textures.at(i)->getName() == BUTTON_KEYBOARD_1)
						{
							m_Textures.at(i)->setActive(true);
							return;
						}
					}
				}
				else if(m_Textures.at(i)->getName() == BUTTON_KEYBOARD_1)
				{
					// Show the next time texture
					m_Textures.at(i)->setActive(false);
					for(int i = 0; i < m_Textures.size(); i++)
					{
						if(m_Textures.at(i)->getName() == BUTTON_KEYBOARD_2)
						{
							m_Textures.at(i)->setActive(true);
							return;
						}
					}
				}
				else if(m_Textures.at(i)->getName() == BUTTON_KEYBOARD_2)
				{
					// Show the next time texture
					m_Textures.at(i)->setActive(false);
					for(int i = 0; i < m_Textures.size(); i++)
					{
						if(m_Textures.at(i)->getName() == BUTTON_MOUSE)
						{
							m_Textures.at(i)->setActive(true);
							return;
						}
					}
				}
				else if(m_Textures.at(i)->getName() == BUTTON_EXIT)
				{
					//quit
				}
				else if(m_Textures.at(i)->getName() == BUTTON_START)
				{
					setActive(false);
				}
				else if(m_Textures.at(i)->getName() == BUTTON_BACK)
				{
					if(getTitle() == MENU_TITLE_CREDITS)
					{
						set(MENU_TITLE_MAIN, true);
					}
					else if(getTitle() == MENU_TITLE_SETTINGS_SP)
					{
						set(MENU_TITLE_MAIN, true);
					}
					else if(getTitle() == MENU_TITLE_SETTINGS_MP)
					{
						set(MENU_TITLE_MAIN, true);
					}
				}
			}
		}
	}
}
 
void Menu::paint()
{
	OpenGLRenderer::getInstance()->drawTexture(m_Background, 0.0f, 0.0f);

	for(int i = 0; i < m_Textures.size(); i++)
	{
		// Draw all active buttons
		if(m_Textures.at(i)->isActive())
		{
			m_Textures.at(i)->paint();
		}
	}
}

void Menu::set(const std::string menuName, bool active)
{
	// Set the menu state
	setActive(active);

	// Deactivate all the buttons
	for(int i = 0; i < m_Textures.size(); i++)
	{
		m_Textures.at(i)->setActive(false);
	}

	if(menuName == MENU_TITLE_MAIN)
	{
		m_Title = MENU_TITLE_MAIN;

		// Activate the required button
		for(int i = 0; i < m_Textures.size(); i++)
		{
			if(m_Textures.at(i)->getName() == BUTTON_SINGLE_PLAYER)
			{
				m_Textures.at(i)->setPosition( 300.0f, 250.0f);
				m_Textures.at(i)->setActive(true);
			}

			if(m_Textures.at(i)->getName() == BUTTON_TWO_PLAYER)
			{
				m_Textures.at(i)->setPosition( 300.0f, 350.0f);
				m_Textures.at(i)->setActive(true);
			}

			if(m_Textures.at(i)->getName() == BUTTON_CREDITS)
			{
				m_Textures.at(i)->setPosition( 300.0f, 450.0f);
				m_Textures.at(i)->setActive(true);
			}

			if(m_Textures.at(i)->getName() == BUTTON_EXIT)
			{
				m_Textures.at(i)->setPosition( 300.0f, 550.0f);
				m_Textures.at(i)->setActive(true);
			}
		}

		// Delete existing texture before creating the new one
		if(m_Background != NULL)
		{
			delete m_Background;
			m_Background = NULL;
		}

		m_Background = new OpenGLTexture(MENU_BACKGROUND_MAIN);

		return;
	}
	else if(menuName == MENU_TITLE_SPLASH)
	{
		m_Title = MENU_TITLE_SPLASH;
		
		// Activate the button
		for(int i = 0; i < m_Textures.size(); i++)
		{
			if(m_Textures.at(i)->getName() == BUTTON_SPLASH)
			{
				m_Textures.at(i)->setPosition( 325.0f, 550.0f);
				m_Textures.at(i)->setActive(true);
			}

		}

		// Delete existing texture before creating the new one
		if(m_Background != NULL)
		{
			delete m_Background;
			m_Background = NULL;
		}

		m_Background = new OpenGLTexture(MENU_BACKGROUND);

		return;
	}
	else if(menuName == MENU_TITLE_PAUSE)
	{
		m_Title = MENU_TITLE_PAUSE;
		
		// Activate the required buttons
		for(int i = 0; i < m_Textures.size(); i++)
		{

			if(m_Textures.at(i)->getName() == BUTTON_RESUME)
			{
				m_Textures.at(i)->setPosition( 380.0f, 250.0f);
				m_Textures.at(i)->setActive(true);
			}

			if(m_Textures.at(i)->getName() == BUTTON_RESTART)
			{
				m_Textures.at(i)->setPosition( 370.0f, 350.0f);
				m_Textures.at(i)->setActive(true);
			}

			if(m_Textures.at(i)->getName() == BUTTON_GAME_SETTINGS)
			{
				m_Textures.at(i)->setPosition( 300.0f, 450.0f);
				m_Textures.at(i)->setActive(true);
			}

			if(m_Textures.at(i)->getName() == BUTTON_EXIT)
			{
				m_Textures.at(i)->setPosition( 300.0f, 550.0f);
				m_Textures.at(i)->setActive(true);
			}

		}

		if(m_Background != NULL)
		{
			delete m_Background;
			m_Background = NULL;
		}

		m_Background = new OpenGLTexture(MENU_BACKGROUND);

		return;
	}
	else if(menuName == MENU_TITLE_SETTINGS_SP)
	{
		m_Title = MENU_TITLE_SETTINGS_SP;

		// Activate the required buttons
		for(int i = 0; i < m_Textures.size(); i++)
		{
			/*
			if(m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_1 || m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_3 
				|| m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_5 || m_Textures.at(i)->getName() == BUTTON_UNLIMITED
				|| m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_3 || m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_5
				|| m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_9 || m_Textures.at(i)->getName() == BUTTON_EASY
				|| m_Textures.at(i)->getName() == BUTTON_MEDIUM || m_Textures.at(i)->getName() == BUTTON_HARD
				|| m_Textures.at(i)->getName() == BUTTON_MOUSE || m_Textures.at(i)->getName() == BUTTON_KEYBOARD_1
				|| m_Textures.at(i)->getName() == BUTTON_KEYBOARD_2 || m_Textures.at(i)->getName() == BUTTON_BACK
				|| m_Textures.at(i)->getName() == BUTTON_START)
			{
				m_Textures.at(i)->setActive(true);
			}
			*/

			if(m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_1)
			{
				m_Textures.at(i)->setPosition(420, 200);
				m_Textures.at(i)->setActive(true);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_3)
			{
				m_Textures.at(i)->setPosition(420, 200);
				m_Textures.at(i)->setActive(false);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_5)
			{
				m_Textures.at(i)->setPosition(420, 200);
				m_Textures.at(i)->setActive(false);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_3)
			{
				m_Textures.at(i)->setPosition(450, 295);
				m_Textures.at(i)->setActive(true);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_5)
			{
				m_Textures.at(i)->setPosition(450, 295);
				m_Textures.at(i)->setActive(false);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_9)
			{
				m_Textures.at(i)->setPosition(450, 295);
				m_Textures.at(i)->setActive(false);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_EASY)
			{
				m_Textures.at(i)->setPosition(410, 375);
				m_Textures.at(i)->setActive(true);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_MEDIUM)
			{
				m_Textures.at(i)->setPosition(410, 375);
				m_Textures.at(i)->setActive(false);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_HARD)
			{
				m_Textures.at(i)->setPosition(410, 375);
				m_Textures.at(i)->setActive(false);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_MOUSE)
			{
				m_Textures.at(i)->setPosition(350, 465);
				m_Textures.at(i)->setActive(true);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_KEYBOARD_1)
			{
				m_Textures.at(i)->setPosition(350, 465);
				m_Textures.at(i)->setActive(false);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_KEYBOARD_2)
			{
				m_Textures.at(i)->setPosition(350, 465);
				m_Textures.at(i)->setActive(false);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_START)
			{
				m_Textures.at(i)->setPosition(750, 665);
				m_Textures.at(i)->setActive(true);
			}

		}

		// Delete existing texture before creating the new one
		if(m_Background != NULL)
		{
			delete m_Background;
			m_Background = NULL;
		}

		m_Background = new OpenGLTexture(MENU_BACKGROUND_SINGLE_PLAYER);
		
		return;
		
	}
	else if(menuName == MENU_TITLE_SETTINGS_MP)
	{
		m_Title = MENU_TITLE_SETTINGS_MP;

		// Activate the required buttons
		for(int i = 0; i < m_Textures.size(); i++)
		{
			/*
			if(m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_1 || m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_3 
				|| m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_5 || m_Textures.at(i)->getName() == BUTTON_UNLIMITED
				|| m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_3 || m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_5
				|| m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_9 || m_Textures.at(i)->getName() == BUTTON_START
				|| m_Textures.at(i)->getName() == BUTTON_MOUSE || m_Textures.at(i)->getName() == BUTTON_KEYBOARD_1
				|| m_Textures.at(i)->getName() == BUTTON_KEYBOARD_2 || m_Textures.at(i)->getName() == BUTTON_BACK)
			{
				m_Textures.at(i)->setActive(true);
			}
			*/

			if(m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_1)
			{
				m_Textures.at(i)->setPosition(420, 200);
				m_Textures.at(i)->setActive(true);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_3)
			{
				m_Textures.at(i)->setPosition(420, 200);
				m_Textures.at(i)->setActive(false);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_TIME_LIMIT_5)
			{
				m_Textures.at(i)->setPosition(420, 200);
				m_Textures.at(i)->setActive(false);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_3)
			{
				m_Textures.at(i)->setPosition(450, 295);
				m_Textures.at(i)->setActive(true);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_5)
			{
				m_Textures.at(i)->setPosition(450, 295);
				m_Textures.at(i)->setActive(false);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_SCORE_LIMIT_9)
			{
				m_Textures.at(i)->setPosition(450, 295);
				m_Textures.at(i)->setActive(false);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_EASY)
			{
				m_Textures.at(i)->setPosition(410, 375);
				m_Textures.at(i)->setActive(true);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_MEDIUM)
			{
				m_Textures.at(i)->setPosition(410, 375);
				m_Textures.at(i)->setActive(false);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_HARD)
			{
				m_Textures.at(i)->setPosition(410, 375);
				m_Textures.at(i)->setActive(false);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_MOUSE)
			{
				m_Textures.at(i)->setPosition(350, 465);
				m_Textures.at(i)->setActive(true);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_KEYBOARD_1)
			{
				m_Textures.at(i)->setPosition(350, 465);
				m_Textures.at(i)->setActive(false);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_KEYBOARD_2)
			{
				m_Textures.at(i)->setPosition(350, 465);
				m_Textures.at(i)->setActive(false);
			}
			else if(m_Textures.at(i)->getName() == BUTTON_START)
			{
				m_Textures.at(i)->setPosition(750, 665);
				m_Textures.at(i)->setActive(true);
			}

		}

		// Delete existing texture before creating the new one
		if(m_Background != NULL)
		{
			delete m_Background;
			m_Background = NULL;
		}

		m_Background = new OpenGLTexture(MENU_BACKGROUND_MULTIPLAYER);

		return;
		
	}
	else if(menuName == MENU_TITLE_CREDITS)
	{
		m_Title = MENU_TITLE_CREDITS;

		// Activate the required buttons
		for(int i = 0; i < m_Textures.size(); i++)
		{
			if(m_Textures.at(i)->getName() == BUTTON_BACK)
			{
				m_Textures.at(i)->setActive(true);
			}
		}

		// Delete existing texture before creating the new one
		if(m_Background != NULL)
		{
			delete m_Background;
			m_Background = NULL;
		}

		m_Background = new OpenGLTexture(MENU_BACKGROUND_CREDITS);

		return;
		
	}
	else if(menuName == MENU_TITLE_GAMEOVER)
	{
		m_Title = MENU_TITLE_GAMEOVER;

		// Activate the required buttons
		for(int i = 0; i < m_Textures.size(); i++)
		{
			if(m_Textures.at(i)->getName() == BUTTON_RESTART || m_Textures.at(i)->getName() == BUTTON_MAIN_MENU)
			{
				m_Textures.at(i)->setActive(true);
			}
		}

		// Delete existing texture before creating the new one
		if(m_Background != NULL)
		{
			delete m_Background;
			m_Background = NULL;
		}

		m_Background = new OpenGLTexture(MENU_BACKGROUND_GAME_OVER);

		return;
	}
}

std::string Menu::getTitle()
{
	return m_Title;
}

bool Menu::getIsActive()
{
	return m_Active;
}

void Menu::setActive(bool state)
{
	m_Active = state;
}







Button::Button(const char* texture)
{
	m_Texture = new OpenGLTexture(texture);
	m_Name = texture;
	m_Active = false;
	m_X = 0.0f;
	m_Y = 0.0f;
}

Button::~Button()
{
	if(m_Texture != NULL)
	{
		delete m_Texture;
		m_Texture = NULL;
	}
}

void Button::paint()
{
	OpenGLRenderer::getInstance()->drawTexture(m_Texture, m_X, m_Y);
}

bool Button::checkCollision(float x, float y)
{
	if(x < m_X || x > m_X + m_Texture->getTextureWidth() || 
		y < m_Y || y > m_Y + m_Texture->getTextureHeight())
	{
		return false;
	}
	return true;
}

void Button::setPosition(float x, float y)
{
	m_X = x;
	m_Y = y;
}

std::string Button::getName()
{
	return m_Name;
}

void Button::setName(std::string name)
{
	m_Name = name;
}

bool Button::isActive()
{
	return m_Active;
}

void Button::setActive(bool state)
{
	m_Active = state;
}

float Button::getX()
{
	return m_X;
}

void Button::setX(float x)
{
	m_X = x;
}

float Button::getY()
{
	return m_Y;
}

void Button::setY(float y)
{
	m_Y = y;
}