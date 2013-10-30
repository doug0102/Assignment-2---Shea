#include "GameConstants.h"


//Game Constants
const char* GAME_SCREEN_NAME = "Game";
const double GAME_OVER_TIMER = 2.0;
const double GAME_SCORE_INFO_TIMER = 2.0;
const double GAME_SCORE_INFO_FADE_OUT_TIME = 0.5;
const short GAME_MAX_SCORE = 9;

//Ball Constants
const float GAME_BALL_RADIUS_PERCENTAGE = 0.012f;
const float GAME_BALL_DEFAULT_SPEED = 250.0f;
const float GAME_BALL_SPEED_INCREMENT = 50.0f;
const char* GAME_BALL_TYPE = "Ball";

//Paddle Constants
const float GAME_PADDLE_WIDTH_PERCENTAGE = 0.025f;
const float GAME_PADDLE_HEIGHT_PERCENTAGE = 0.2f;
const float GAME_LEFT_PADDLE_X_PERCENTAGE = 0.05f;
const float GAME_RIGHT_PADDLE_X_PERCENTAGE = 0.95f;
const float GAME_PADDLE_Y_PERCENTAGE = 0.5f;
const float GAME_PADDLE_ACCELERATION = 50.0f;
const float GAME_PADDLE_MAX_SPEED = 200.0f;
const char* GAME_PADDLE_TYPE = "Paddle";

// Menu constants

const std::string MENU_TITLE_MAIN = "MENU_MAIN";
const std::string MENU_TITLE_SPLASH = "MENU_SPLASH";
const std::string MENU_TITLE_PAUSE = "MENU_PAUSE";
const std::string MENU_TITLE_SETTINGS_SP = "MENU_SETTINGS_SP";
const std::string MENU_TITLE_SETTINGS_MP = "MENU_SETTINGS_MP";
const std::string MENU_TITLE_CREDITS = "MENU_CREDITS";
const std::string MENU_TITLE_GAMEOVER = "MENU_GAMEOVER";