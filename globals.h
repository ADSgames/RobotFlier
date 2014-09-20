#ifndef GLOBALS_H
#define GLOBALS_H

// Import libraries
#include <allegro.h>
#include <alpng.h>
#include <time.h>
#include <vector>
#include <fmod/fmod.h>
#include <fmod/fmod_errors.h>
#include <math.h>
#include <fstream>
#include <sstream>

using namespace std;

//Variables
extern const int robotWidth;
extern const int robotHeight;

extern int robot_x;
extern int robot_y;

extern int health;
extern unsigned int score;

extern int magneticStrength;
extern int magneticTimer;
extern int invincibleTimer;
extern bool invincible;

extern int robotDistance;
extern int energyCollected;
extern int powerupsCollected;
extern int debrisCollided;

extern bool sound;
extern bool magnetic;
extern bool debugMode;
extern bool particlesOn;

float Get2dDistance(float x1, float y1, float x2, float y2);

int random(int newLowest, int newHighest);

bool collision(float xMin1, float xMax1, float xMin2, float xMax2, float yMin1, float yMax1, float yMin2, float yMax2);

void fade_in(BITMAP* bmp_orig, int speed);
void fade_out(int speed);

#endif
