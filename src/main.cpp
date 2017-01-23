/*
 * Robot Flier
 * A.D.S. Games
 * 03/01/2016
 * Robots in space!
 */
#include <string>
#include <time.h>

#include "state.h"
#include "init.h"
#include "intro.h"
#include "menu.h"
#include "game.h"
#include "mouseListener.h"
#include "keyListener.h"
#include "globals.h"

// Events
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE* event_queue = NULL;
ALLEGRO_TIMER* timer = NULL;

// Mouse Updater
mouseListener m_listener;
keyListener k_listener;

// Closing or naw
bool closing = false;

// Current state object
state *currentState = NULL;

// Delete game state and free state resources
void clean_up(){
  delete currentState;
}

// Change game screen
void change_state(){
  //If the state needs to be changed
  if( nextState != STATE_NULL ){
    //Delete the current state
    if( nextState != STATE_EXIT ){
      delete currentState;
    }

    //Change the state
    switch( nextState ){
      case STATE_INIT:
        currentState = new init();
        break;
      case STATE_INTRO:
        currentState = new intro();
        break;
      case STATE_MENU:
        currentState = new menu();
        break;
      case STATE_GAME:
        currentState = new game();
        break;
      case STATE_EXIT:
        closing = true;
        break;
      default:
        currentState = new menu();
    }

    //Change the current state ID
    stateID = nextState;

    //NULL the next state ID
    nextState = STATE_NULL;
  }
}

// Sets up game
void setup(){
  // Init allegro 5
  al_init();

  al_install_keyboard();
  al_install_mouse();

  al_init_font_addon();
  al_init_ttf_addon();

  al_init_image_addon();
  al_init_primitives_addon();

  al_install_audio();
  al_init_acodec_addon();
  al_reserve_samples( 20);

  // Initializing
  timer = al_create_timer(1.0 / MAX_FPS);
  display = al_create_display( SCREEN_W, SCREEN_H);

  event_queue = al_create_event_queue();

  al_register_event_source( event_queue, al_get_display_event_source(display));
  al_register_event_source( event_queue, al_get_timer_event_source(timer));
  al_register_event_source( event_queue, al_get_keyboard_event_source());

  al_clear_to_color( al_map_rgb(0,0,0));
  al_flip_display();
  al_start_timer(timer);

  // Creates a random number generator (based on time)
  srand( time(NULL));

  // Game state
  stateID = STATE_NULL;
  nextState = STATE_NULL;

  // Clear settings
  for( int i = 0; i < 11; i++){
    settings[i] = false;
  }
}

// Universal update
void update(){
  ALLEGRO_EVENT ev;
  al_wait_for_event(event_queue, &ev);

  if(ev.type == ALLEGRO_EVENT_TIMER){
    change_state();
    k_listener.update();
    currentState -> update();
  }
  else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
    closing = true;
  }
  else if(ev.type == ALLEGRO_EVENT_KEY_DOWN || ev.type == ALLEGRO_EVENT_KEY_UP){
    k_listener.on_event( ev.type, ev.keyboard.keycode);
  }
  if(al_is_event_queue_empty(event_queue)){
    al_clear_to_color(al_map_rgb(0,0,0));
    currentState -> draw();
    al_flip_display();
  }

  // Update mouse listener vars
  m_listener.update();
  k_listener.update();

  // Debug console toggle
  if( keyListener::keyPressed[ALLEGRO_KEY_F12])
    settings[SETTING_DEBUG] = (settings[SETTING_DEBUG] + 1) % 2;

  // Check joystick
  // poll_joystick();
}

// main function of program
int main( int argc, char* argv[]){
  // Setup game
  setup();

  // Copy over the command line args
  for (int i = 1; i < argc; i++){
    if( strcmp(argv[i], "mega") == 0)
      settings[SETTING_MEGA] = true;
    else if( strcmp(argv[i], "supershake") == 0)
      settings[SETTING_SUPERSHAKE] = true;
    else if( strcmp(argv[i], "merrychristmas") == 0)
      settings[SETTING_CHRISTMAS] = true;
    std::cout << argv[i];
  }

  //Set the current state ID
  stateID = STATE_INIT;

  //Set the current game state object
  currentState = new init();

  // Loop
  while( !closing){
    update();
  }
  return 0;
}
