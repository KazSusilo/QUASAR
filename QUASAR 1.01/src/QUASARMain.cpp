/*****************************************************************************
 Name:      Rennison, Paige & Susilo, Alexander
 Teacher:   Ms. Cullum
 Course:    ICS3U.-02
 Date:      January 18, 2018

 Title:     QUASAR

 Purpose:   The purpose of this program is for the user to play a fun game.
*****************************************************************************/

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "QUASAR.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
    int posX;
    int posY;
    float FPS = 130;			// set frame rate per second

    // Initializes Allegro
    initializeAllegroandGame();

    // Declare Display & Event Queue
    ALLEGRO_DISPLAY *display = nullptr;
    ALLEGRO_FONT *font = nullptr;
    ALLEGRO_FONT *font2 = nullptr;
    ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
    ALLEGRO_TIMER *timer = nullptr;

    // Initialize Display, Font, and Event Queue
    display = al_create_display(SCREEN_W, SCREEN_H);
    font = al_load_ttf_font("Gtek Technology free promo.ttf", 36, 0);
    font2 = al_load_ttf_font("Trench.ttf", 36, 0);
	event_queue = al_create_event_queue();

	// Initialize keyboard routines
	if (!al_install_keyboard()) {
	    al_show_native_message_box(display, "Error", "Error", "failed to initialize the keyboard!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
      	return -1;
   	}

    // Set window title
	al_set_window_title(display, "QUASAR");

    // Initialize image add on
 	if (!al_init_image_addon()) {
    	al_show_native_message_box(display, "Error", "Error",
    		"Failed to initialize image addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}

	// create timer
	timer = al_create_timer(1.0 / FPS);
   	if (!timer) {
   		al_show_native_message_box(display, "Error", "Error", "Failed to create timer!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    // Declare Images For Start Screen
    ALLEGRO_BITMAP *backdrop = nullptr;
    ALLEGRO_BITMAP *instrucButton = nullptr;
    ALLEGRO_BITMAP *startButton = nullptr;
    ALLEGRO_BITMAP *credButton = nullptr;
    ALLEGRO_BITMAP *instrucPage = nullptr;
    ALLEGRO_BITMAP *credPage = nullptr;

    // Declare Images For Game
    ALLEGRO_BITMAP *gameBackdrop = nullptr;
    ALLEGRO_BITMAP *heroIdle = nullptr;
    ALLEGRO_BITMAP *heroLeft = nullptr;
    ALLEGRO_BITMAP *heroTopLeft = nullptr;
    ALLEGRO_BITMAP *heroUp = nullptr;
    ALLEGRO_BITMAP *heroTopRight = nullptr;
    ALLEGRO_BITMAP *heroRight = nullptr;

    backdrop = al_load_bitmap("BackDrop.png");                                  // Load Title Images
    startButton = al_load_bitmap("QUASAR Start Button.png");
    instrucButton = al_load_bitmap("QUASAR Instruc Button.png");
    credButton = al_load_bitmap("QUASAR Cred Button.png");
    instrucPage = al_load_bitmap("Instructions.png");
    credPage = al_load_bitmap("Credits.png");


    gameBackdrop = al_load_bitmap("HeroIdle.png");                              // Load Character Images
    heroLeft = al_load_bitmap("HeroLeft.png");
    heroTopLeft = al_load_bitmap("HeroTopLeft.png");
    heroUp = al_load_bitmap("HeroUp.png");
    heroTopRight = al_load_bitmap("HeroTopRight.png");
    heroRight = al_load_bitmap("HeroRight.png");

    al_draw_bitmap(backdrop, 0,  0, 0);                                         // Displays Main Screen When Game Is Launched
    al_flip_display();

	al_register_event_source(event_queue, al_get_display_event_source(display));// Registering Events For Queue
    al_register_event_source(event_queue, al_get_mouse_event_source());
 	al_register_event_source(event_queue, al_get_keyboard_event_source());
 	al_register_event_source(event_queue, al_get_timer_event_source(timer));

 	bool done = false;                                                          // Conditions For Certain Actions In The Menu
 	bool cursur = true;
 	bool startBut = false;
 	bool instrucBut = false;
 	bool credBut = false;
 	bool instructionPage = false;
 	bool creditsPage = false;
 	bool backBut = false;

 	while (done == false){                                                      // Main Menu Actions
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){                            // Exits The Main Menu And Starts The Game
            done = true;
        }

        else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES){                          // This Event Accounts For All Mouse Movement
            posX = ev.mouse.x;                                                  // Records The X & Y Coordinates Of The Mouse
            posY = ev.mouse.y;
            if ((instructionPage == true) || (creditsPage == true)){            // Checks To See If Either The Instructions Or Credits Page Is Open
                startBut = false;
                instrucBut = false;
                credBut = false;
                if ((posX > 0 && posX < 100) && (posY > 0 && posY < 100)){      // Checks To See If The Mouse Button Is Over The Back Button
                    backBut = true;
                }
            }
            else if ((posX > 300 && posX < 500) && (posY > 126 && posY < 326)){ // Checks To See If The Mouse Button Is Over The Instructions Button
                instrucBut = true;
                if (instrucBut == true){
                    al_draw_bitmap(instrucButton, 0, 0, 0);
                }
            }
            else if ((posX > 100 && posX < 300) && (posY > 500 && posY < 700)){ // Checks To See If The Mouse Button Is Over The Start Button
                startBut = true;
                if (startBut == true){
                    al_draw_bitmap(startButton, 0, 0, 0);
                }
            }
            else if ((posX > 1050 && posX < 1250)&& (posY > 513 && posY <713)){ // Checks To See If The Mouse Button Is Over The Credits Button
                credBut = true;
                if (credBut == true){
                    al_draw_bitmap(credButton, 0, 0, 0);
                }
            }
            else {                                                              // If The Mouse Buttons Is Over None Of The Buttons, Nothing Happens
                startBut = false;
                instrucBut = false;
                credBut = false;
                backBut = false;
                al_draw_bitmap(backdrop, 0,  0, 0);
            }
        }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){       // This Event Accounts For All Mouse Clicks
            if (ev.mouse.button & 1){
                if (startBut == true){                              // Starts Game When The Start Button Is Clicked
                    al_draw_bitmap(gameBackdrop, 0,  0, 0);
                    al_flip_display();

                    al_draw_text(font, WHITE, 640, 380, ALLEGRO_ALIGN_CENTRE, "game start!");
                    al_flip_display();
                    al_rest(2);
                    done = true;
                }
                else if (instrucBut == true){                       // Displays The Instructions Page Once The Instructions Button Is Clicked
                    instructionPage = true;
                    al_draw_bitmap(instrucPage, 0 ,0, 0);
                }
                else if (credBut = true){                           // Displays The Credits Page Once The Credits Button Is Clicked
                    creditsPage = true;
                    al_draw_bitmap(credPage, 0, 0, 0);
                }
                if (backBut == true){                               // Goes Back To The Main Menu Once The Back Button Is Clicked
                    al_draw_bitmap(backdrop, 0, 0, 0);
                    instructionPage = false;
                    creditsPage = false;
                    backBut = false;
                    instrucBut = false;
                    credBut = false;
                }
            }
        }
        al_flip_display();
 	}

    // Destroys Bitmaps From The Main Menu
 	menuRelease(credPage, credButton, instrucPage, instrucButton, startButton, backdrop);

 	srand(time(0));                             //Starting Timer + Game
    al_start_timer(timer);
 	char imagefile[30];                         //variable to hold image file name
    float x;                                    //variables used throughout for location
    float y;
    float speed = 0.001;                        //starter speed
    bool heroDead = false;                      //variable used for creating object loop
    bool objDead;
    Objects lazer;
    int deathCount = 0;

    while(heroDead == false){                   //Loop allows new laser to be created

        objDead = false;
        speed = speed - 0.001;
        FPS = FPS + 30;
        lazer.entrance = randomizeLEnt(lazer.entrance);     //using function to determine entrance path

        //Moving the laser from its random entrance
        if(lazer.entrance == 0){                                                //OBJ ENTERS FROM LEFT
            chooseImage(imagefile, lazer.entrance);                             //Calling function to chose image file
            lazer.image = al_load_bitmap(imagefile);
            fromLeft(lazer.image, gameBackdrop, speed, font2, deathCount);      //Calling function to have the object enter
            x = 200;
            while(objDead == false && heroDead == false){                       //Entering area where possible to kill object
                ALLEGRO_EVENT ev;
                al_wait_for_event(event_queue, &ev);
                if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                    ALLEGRO_EVENT ev;
                    al_wait_for_event(event_queue, &ev);
                    switch(ev.keyboard.keycode) {
                        case ALLEGRO_KEY_A:                                     //if "A" key pressed, this object loop is done
                            objDead = true;
                            deathCount++;
                            al_draw_bitmap(heroLeft, 0, 0, 0);
                            al_draw_textf(font2, BLACK, 640, 660, ALLEGRO_ALIGN_CENTRE, "%d", deathCount);
                            al_flip_display();
                            al_rest(0.3);
                            break;
                    }
                }else if(x > 350){                                              //if object reaches location, game loop is done
                    heroDead = true;
                }else if(ev.type == ALLEGRO_EVENT_TIMER) {                      //if nothing else happens, image keeps moving
                    x+=1;
                    al_draw_bitmap(gameBackdrop, 0,  0, 0);
                    al_draw_bitmap(lazer.image, x, 480, 0);
                    al_draw_textf(font2, BLACK, 640, 660, ALLEGRO_ALIGN_CENTRE, "%d", deathCount);
                    al_flip_display();
                }
            }
        }else if(lazer.entrance == 1){                                          //OBJ ENTERS FROM TOP LEFT
            chooseImage(imagefile, lazer.entrance);                             //Calling function to chose image file
            lazer.image = al_load_bitmap(imagefile);
            fromDiagLeft(lazer.image,gameBackdrop, speed, font2, deathCount);   //Calling function to have the object enter
            y = 200;
            x = 200;
            while(objDead == false && heroDead == false){                       //Entering area where possible to kill object
                ALLEGRO_EVENT ev;
                al_wait_for_event(event_queue, &ev);
                if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                    ALLEGRO_EVENT ev;
                    al_wait_for_event(event_queue, &ev);
                    switch(ev.keyboard.keycode) {
                        case ALLEGRO_KEY_Q:                                     //if "Q" key pressed, this object loop is done
                            objDead = true;
                            deathCount++;
                            al_draw_bitmap(heroTopLeft, 0, 0, 0);
                            al_draw_textf(font2, BLACK, 640, 660, ALLEGRO_ALIGN_CENTRE, "%d", deathCount);
                            al_flip_display();
                            al_rest(0.3);
                        break;
                    }
                }else if(y > 400){                                              //if object reaches location, game loop is done
                    heroDead = true;
                }else if(ev.type == ALLEGRO_EVENT_TIMER) {                      //if nothing else happens, image keeps moving
                    y+=1;
                    x+=1;
                    al_draw_bitmap(gameBackdrop, 0,  0, 0);
                    al_draw_bitmap(lazer.image, x, y, 0);
                    al_draw_textf(font2, BLACK, 640, 660, ALLEGRO_ALIGN_CENTRE, "%d", deathCount);
                    al_flip_display();
                }
            }
        }else if(lazer.entrance == 2){                                          //OBJ ENTERS FROM TOP
            chooseImage(imagefile, lazer.entrance);                             //Calling function to chose image file
            lazer.image = al_load_bitmap(imagefile);
            fromTop(lazer.image,gameBackdrop, speed, font2, deathCount);        //Calling function to have the object enter
            y = 100;

            while(objDead == false && heroDead == false){                       //Entering area where possible to kill object
                ALLEGRO_EVENT ev;
                al_wait_for_event(event_queue, &ev);
                if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                    ALLEGRO_EVENT ev;
                    al_wait_for_event(event_queue, &ev);
                    switch(ev.keyboard.keycode) {
                        case ALLEGRO_KEY_W:                                     //if "W" key pressed, this object loop is done
                            objDead = true;
                            deathCount++;
                            al_draw_bitmap(heroUp, 0, 0, 0);
                            al_draw_textf(font2, BLACK, 640, 660, ALLEGRO_ALIGN_CENTRE, "%d", deathCount);
                            al_flip_display();
                            al_rest(0.3);
                        break;
                    }
                }else if(y > 250){                                              //if object reaches location, game loop is done
                    heroDead = true;
                }else if(ev.type == ALLEGRO_EVENT_TIMER) {                      //if nothing else happens, image keeps moving
                    y+=1;
                    al_draw_bitmap(gameBackdrop, 0,  0, 0);
                    al_draw_bitmap(lazer.image, 570, y, 0);
                    al_draw_textf(font2, BLACK, 640, 660, ALLEGRO_ALIGN_CENTRE, "%d", deathCount);
                    al_flip_display();
                }
            }
        }else if(lazer.entrance == 3){                                          //OBJ ENTERS FROM TOP RIGHT
            chooseImage(imagefile, lazer.entrance);                             //Calling function to chose image file
            lazer.image = al_load_bitmap(imagefile);
            fromDiagRight(lazer.image,gameBackdrop, speed, font2, deathCount);  //Calling function to have the object enter
            y = 200;
            x = 800;

            while(objDead == false && heroDead == false){                       //Entering area where possible to kill object
                ALLEGRO_EVENT ev;
                al_wait_for_event(event_queue, &ev);
                if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                    ALLEGRO_EVENT ev;
                    al_wait_for_event(event_queue, &ev);
                    switch(ev.keyboard.keycode) {
                        case ALLEGRO_KEY_E:                                     //if "E" key pressed, this object loop is done
                            objDead = true;
                            deathCount++;
                            al_draw_bitmap(heroTopRight, 0, 0, 0);
                            al_draw_textf(font2, BLACK, 640, 660, ALLEGRO_ALIGN_CENTRE, "%d", deathCount);
                            al_flip_display();
                            al_rest(0.3);
                        break;
                    }
                }else if(y > 380){                                              //if object reaches location, game loop is done
                    heroDead = true;
                }else if(ev.type == ALLEGRO_EVENT_TIMER) {                      //if nothing else happens, image keeps moving
                    y+=1;
                    x-=1;
                    al_draw_bitmap(gameBackdrop, 0,  0, 0);
                    al_draw_textf(font2, BLACK, 640, 660, ALLEGRO_ALIGN_CENTRE, "%d", deathCount);
                    al_draw_bitmap(lazer.image, x, y, 0);
                    al_flip_display();
                }
            }
        }else if(lazer.entrance == 4){                                          //OBJ ENTERS FROM RIGHT
            chooseImage(imagefile, lazer.entrance);                             //Calling function to chose image file
            lazer.image = al_load_bitmap(imagefile);
            fromRight(lazer.image,gameBackdrop, speed, font2, deathCount);      //Calling function to have the object enter
            x = 800;

            while(objDead == false && heroDead == false){                       //Entering area where possible to kill object
                ALLEGRO_EVENT ev;
                al_wait_for_event(event_queue, &ev);
                if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                    ALLEGRO_EVENT ev;
                    al_wait_for_event(event_queue, &ev);
                    switch(ev.keyboard.keycode) {
                        case ALLEGRO_KEY_D:                                     //if "D" key pressed, this object loop is done
                            objDead = true;
                            deathCount++;
                            al_draw_bitmap(heroRight, 0, 0, 0);
                            al_draw_textf(font2, BLACK, 640, 660, ALLEGRO_ALIGN_CENTRE, "%d", deathCount);
                            al_flip_display();
                            al_rest(0.3);
                        break;
                    }
                }else if(x < 650){                                              //if object reaches location, game loop is done
                    heroDead = true;
                }else if(ev.type == ALLEGRO_EVENT_TIMER) {                      //if nothing else happens, image keeps moving
                    x-=1;
                    al_draw_bitmap(gameBackdrop, 0,  0, 0);
                    al_draw_bitmap(lazer.image, x, 480, 0);
                    al_draw_textf(font2, BLACK, 640, 660, ALLEGRO_ALIGN_CENTRE, "%d", deathCount);
                    al_flip_display();
                }
            }

        }
    }

    gameRelease(gameBackdrop, heroIdle, heroLeft, heroRight, heroTopLeft, heroTopRight, heroIdle);

    al_draw_text(font, WHITE, 640, 380, ALLEGRO_ALIGN_CENTRE, "you lost!");     //DEATH SEQUENCE
    al_flip_display();
    al_rest(2);
    leaderBoard(deathCount, font2);     // HIGHSCORE CODE
    waitForExit(display);               // Closes The Program Once The "ESC" Key Is Pressed
    al_destroy_display(display);        // Relieves Memory
    al_destroy_bitmap(lazer.image);
}
