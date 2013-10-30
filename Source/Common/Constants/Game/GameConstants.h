#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H
#include <string>

//Game Constants
extern const char* GAME_SCREEN_NAME;
extern const double GAME_OVER_TIMER;
extern const double GAME_SCORE_INFO_TIMER;
extern const double GAME_SCORE_INFO_FADE_OUT_TIME;
extern const short GAME_MAX_SCORE;

//Ball Constants
extern const float GAME_BALL_RADIUS_PERCENTAGE;
extern const float GAME_BALL_DEFAULT_SPEED;
extern const float GAME_BALL_SPEED_INCREMENT;
extern const char* GAME_BALL_TYPE;

//Paddle Constants
extern const float GAME_PADDLE_WIDTH_PERCENTAGE;
extern const float GAME_PADDLE_HEIGHT_PERCENTAGE;
extern const float GAME_LEFT_PADDLE_X_PERCENTAGE;
extern const float GAME_RIGHT_PADDLE_X_PERCENTAGE;
extern const float GAME_PADDLE_Y_PERCENTAGE;
extern const float GAME_PADDLE_ACCELERATION;
extern const float GAME_PADDLE_MAX_SPEED;
extern const char* GAME_PADDLE_TYPE;

//Menu constants
extern const std::string MENU_TITLE_MAIN;
extern const std::string MENU_TITLE_SPLASH;
extern const std::string MENU_TITLE_PAUSE;
extern const std::string MENU_TITLE_SETTINGS_SP;
extern const std::string MENU_TITLE_SETTINGS_MP;
extern const std::string MENU_TITLE_CREDITS;
extern const std::string MENU_TITLE_GAMEOVER;

#endif 