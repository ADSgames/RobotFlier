#include "globals.h"

//Global variables
unsigned int score;
int screenshake;
int fps;

// Data
int stats[4];
std::string scores[10][2];
int settings[11];

// Is the joystick enabled?
bool joystick_enabled = false;

// Fonts
FONT* orbitron_14;
FONT* orbitron;
