#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>                   // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h> 		// For message box
#include "QUASAR.h"
#include <stdlib.h>
#include <time.h>

//Randomizing the entrance that the meteors enters the screen from
int randomizeLEnt(int randEnt){
    randEnt = rand() % 5;
    return randEnt;
}
//Choosing the image file used for the object based on its entrance
char chooseImage(char imFile[], int type){
    if(type == 0){
        strcpy(imFile, "LaserLeft.png");
    }else if(type == 1){
        strcpy(imFile, "DiagLeft.png");
    }else if(type == 2){
        strcpy(imFile, "LaserTop.png");
    }else if(type == 3){
        strcpy(imFile, "DiagRight.png");
    }else if(type == 4){
        strcpy(imFile, "LaserRight.png");
    }
}
//Moving the meteor image from the left
void fromLeft(ALLEGRO_BITMAP *moveImage, ALLEGRO_BITMAP *backdrop, float v, ALLEGRO_FONT *font2, int deathCount){
    for(int x = -200; x < 200; x++){
        al_draw_bitmap(backdrop, 0,  0, 0);
        al_draw_bitmap(moveImage, x, 480, 0);
        al_draw_textf(font2, BLACK, 640, 660, ALLEGRO_ALIGN_CENTRE, "%d", deathCount);
        al_flip_display();
        al_rest(v);
    }
}
//Moving the meteor image from the top left corner
void fromDiagLeft(ALLEGRO_BITMAP *moveImage, ALLEGRO_BITMAP *backdrop, float v, ALLEGRO_FONT *font2, int deathCount){
    float x = -200;
    for(int y = -200; y < 200; y++){
        al_draw_bitmap(backdrop, 0,  0, 0);
        x = x + 1.0;
        al_draw_bitmap(moveImage, x, y, 0);
        al_draw_textf(font2, BLACK, 640, 660, ALLEGRO_ALIGN_CENTRE, "%d", deathCount);
        al_flip_display();
        al_rest(v);
    }
}
//Moving the meteor image from the top
void fromTop(ALLEGRO_BITMAP *moveImage, ALLEGRO_BITMAP *backdrop, float v, ALLEGRO_FONT *font2, int deathCount){
    for(int y = -200; y < 100; y++){
        al_draw_bitmap(backdrop, 0,  0, 0);
        al_draw_bitmap(moveImage, 570, y, 0);
        al_draw_textf(font2, BLACK, 640, 660, ALLEGRO_ALIGN_CENTRE, "%d", deathCount);
        al_flip_display();
        al_rest(v);
    }
}
//Moving the meteor image from the top right corner
void fromDiagRight(ALLEGRO_BITMAP *moveImage, ALLEGRO_BITMAP *backdrop, float v, ALLEGRO_FONT *font2, int deathCount){
    float x = 1200;
    for(int y = -200; y < 200; y++){
        al_draw_bitmap(backdrop, 0,  0, 0);
        x--;
        al_draw_bitmap(moveImage, x, y, 0);
        al_draw_textf(font2, BLACK, 640, 660, ALLEGRO_ALIGN_CENTRE, "%d", deathCount);
        al_flip_display();
        al_rest(v);
    }
}
//Moving the meteor image from the right
void fromRight(ALLEGRO_BITMAP *moveImage, ALLEGRO_BITMAP *backdrop, float v, ALLEGRO_FONT *font2, int deathCount){
    for(int x = 1200; x > 800; x--){
        al_draw_bitmap(backdrop, 0,  0, 0);
        al_draw_bitmap(moveImage, x, 480, 0);
        al_draw_textf(font2, BLACK, 640, 660, ALLEGRO_ALIGN_CENTRE, "%d", deathCount);
        al_flip_display();
        al_rest(v);
    }
}

// Destroys Bitmaps For The Main Menu
void menuRelease(ALLEGRO_BITMAP *credPage, ALLEGRO_BITMAP *credButton, ALLEGRO_BITMAP *instrucPage, ALLEGRO_BITMAP *instrucButton, ALLEGRO_BITMAP *startButton, ALLEGRO_BITMAP *backdrop){
    al_destroy_bitmap(credPage);                // Free Up Memory
    al_destroy_bitmap(credButton);
    al_destroy_bitmap(instrucPage);
    al_destroy_bitmap(instrucButton);
    al_destroy_bitmap(startButton);
    al_destroy_bitmap(backdrop);
}

void gameRelease(ALLEGRO_BITMAP *gameBackdrop, ALLEGRO_BITMAP *heroIdle, ALLEGRO_BITMAP *heroLeft, ALLEGRO_BITMAP *heroRight, ALLEGRO_BITMAP *heroTopLeft, ALLEGRO_BITMAP *heroTopRight, ALLEGRO_BITMAP *heroUp){
    al_destroy_bitmap(gameBackdrop);            // Free Up Memory
    al_destroy_bitmap(heroIdle);
    al_destroy_bitmap(heroLeft);
    al_destroy_bitmap(heroRight);
    al_destroy_bitmap(heroTopLeft);
    al_destroy_bitmap(heroTopRight);
    al_destroy_bitmap(heroUp);
}
