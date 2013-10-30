#ifndef MENU_H
#define MENU_H

#include <vector>

class OpenGLTexture;
class Button;

class Menu
{

public:
	Menu();
	Menu(const std::string menuName);
	~Menu();

	void handleKeyboardInput(int aKeyCode);

	void checkCollision(float x, float y);

	// Draw the textures
	void paint();

	// Set the menu for a new screen, or hide it
	void set(const std::string menuName, bool active);

	std::string getTitle();

	bool getIsActive();
	void setActive(bool state);

	/*
	int getScoreLimit();
	float getTimeLimit();
	bool getGameType();
	int getFirstPlayerControls();
	int getSecondPlayerControls();
	int getDifficulty();
	*/
private:

	// Keeps track of the current menu's name
	std::string m_Title;

	std::string m_PreviousScreen;

	// Textures used for menu items 
	std::vector<Button*> m_Textures;
	
	// True if the menu is being displayed
	bool m_Active;

	// Texture used for the menu background
	OpenGLTexture* m_Background;

	/*
	int m_ScoreLimit;
	float m_TimeLimit;
	bool m_GameType;
	int m_FirstPlayerControls;
	int m_SecondPlayerControls;
	int m_Difficulty;
	*/
};


class Button
{

public:
	Button(const char* texture);
	~Button();

	void paint();

	bool checkCollision(float x, float y);

	void setPosition(float x, float y);

	std::string getName();
	void setName(std::string name);

	bool isActive();
	void setActive(bool state);

	float getX();
	void setX(float x);

	float getY();
	void setY(float y);

private:

	OpenGLTexture* m_Texture;

	std::string m_Name;

	bool m_Active;

	float m_X;
	float m_Y;
};


#endif