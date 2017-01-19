/*
 * Tools Class
 * Allan Legemaate
 * 13/01/2017
 * Functions that may be needed by multiple files
 */
#ifndef TOOLS_H
#define TOOLS_H

#include "globals.h"
#include <time.h>
#include <math.h>
#include <fstream>
#include <sstream>

// Conversions
extern std::string convertIntToString( int number);
extern int convertStringToInt( std::string newString);

// Scores
extern void updateScores( std::string scoreCopy[][2]);
extern bool check_highscore( std::string scoreCopy[][2], int score);
extern void addScore( std::string scoreCopy[][2], int newScore, std::string name);

// Keys
extern bool joy_buttonpressed();
extern bool keyboard_keypressed();

// Error handling loading functions
extern ALLEGRO_BITMAP *load_bitmap_ex( std::string file);
extern ALLEGRO_SAMPLE *load_sample_ex( std::string file);
extern ALLEGRO_SAMPLE *logg_load_ex( std::string file);

extern ALLEGRO_FONT *load_font_ex( std::string file);
extern void abort_on_error( std::string message);

// Random generator
extern int random(int newLowest, int newHighest);

// Math related functions
extern float Get2dDistance(float x1, float y1, float x2, float y2);
extern bool collision(float xMin1, float xMax1, float xMin2, float xMax2, float yMin1, float yMax1, float yMin2, float yMax2);

// Fades
extern void fade_in( ALLEGRO_BITMAP* bmp_orig, int speed);
extern void fade_out(int speed);

#endif // TOOLS_H
