#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../Screen Manager/Screen.h"

class GameObject;
class OpenGLTexture;
class Menu;

class Game : public Screen, public InputListener
{
public:
    Game();
    ~Game();
    
    //Game lifecycle methods
    void update(double delta);
    void paint();
    void reset();
    
    //Game Over method, call this when to end the game
    void gameOver();
    void leftGoal();
    void rightGoal();
    
    //Screen name, must be implemented, it's a pure
    //virtual method in the Screen class
    const char* getName();
    
    //Screen event method, inherited from the screen class
    void screenWillAppear();
    
    //GameObject Methods
    void addGameObject(GameObject* gameObject);
    GameObject* getGameObjectByType(const char* type);
    
private:

	// The game menu object
	Menu* m_GameMenu;

    //Key Events
    void keyUpEvent(int keyCode);
    void keyDownEvent(int keyCode);

	// Mouse Events
	void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	void mouseLeftClickDownEvent(float positionX, float positionY);
	void mouseLeftClickUpEvent(float positionX, float positionY);
	void mouseRightClickDownEvent(float positionX, float positionY);

	//Function to draw a number
	float drawNumber(int number, float x, float y);

	// Function to paint a timer
	void paintTimer();
    
    //Method to reset the ball, called after a goal is scored. The
    //parameter determines which direction the ball will go in
    //after a goal is scored.
    void resetBall(bool leftGoal);
    
    //Conveniance method used to paint the score info, drawn after
    //a goal is scored to update the user on the current score
    void paintScoreInfo(float alpha);
    
    //Vector to hold the GameObjects
    std::vector<GameObject*> m_GameObjects;
    
    //Texture's used for the score info
    OpenGLTexture* m_AlgonquinLogo;
    OpenGLTexture* m_ScoreInfoBackground;
    OpenGLTexture* m_ScoreInfoGoal;
    OpenGLTexture* m_ScoreInfoLeft;
    OpenGLTexture* m_ScoreInfoRight;
    OpenGLTexture** m_ScoreInfoNumbers;
	
    
    //Score Info variables
    double m_ScoreInfoTimer;
    float m_ScoreInfoAlpha;

	float m_MousePositionX;
	float m_MousePositionY;
    
	// Timer variables
	double m_GameTime;

	// Game score limit variable
	int m_ScoreLimit;

    //Score variables
    short m_LeftGoalsScored;
    short m_RightGoalsScored;


	// Textures used to draw the score
	OpenGLTexture* m_Comma;
	OpenGLTexture* m_LeftBracket;
	OpenGLTexture* m_RightBracket;
	OpenGLTexture* m_ScoreInfoTemplate;
	
};

#endif