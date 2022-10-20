#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>                   // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h> 		// For message box
#include "QUASAR.h"
#include <stdlib.h>
#include <time.h>


// Function That Initializes Required Allegro Functions & Game Functions
void initializeAllegroandGame(){
    /* Allegro Functions */
	al_init();                      // Initialize Allegro

	al_init_font_addon();           // Initialize Font Add Ons
    al_init_ttf_addon();

	al_install_keyboard();          // Install Keyboard
	al_install_mouse();             // Install Mouse
}

// Function That Closes The Program Once The "ESC" Key Is Pressed
void waitForExit(ALLEGRO_DISPLAY *display) {

    // Waits until the "ESC" Key Is Pressed
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE *event_queue;

    event_queue = al_create_event_queue();
	if (!event_queue) {
		al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
      	return;
	}
    al_install_keyboard();
	al_register_event_source(event_queue, al_get_display_event_source(display));
 	al_register_event_source(event_queue, al_get_keyboard_event_source());
    while (1) {
        al_wait_for_event(event_queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            return;
        if (event.type == ALLEGRO_EVENT_KEY_DOWN  &&  event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            return;
    }
}
