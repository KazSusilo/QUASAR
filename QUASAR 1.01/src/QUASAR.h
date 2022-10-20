/*****************************************************************************
 Name:      Rennison, Paige & Susilo, Alexander
 Teacher:   Ms. Cullum
 Course:    ICS3U.-02
 Date:      January 18, 2018

 Title:     QUASAR

 Purpose:   The purpose of this program is for the user to play a fun game.
*****************************************************************************/

const int SCREEN_W = 1280;       // Screen Width
const int SCREEN_H = 720;       // Screen Height

const int COL_1 = 5;                /* Work ON ACTUALY LOCATIONS STILL */
const int COL_2 = 180;           // Entry
const int COL_3 = 400;
const int ROW_1 = 180;
const int ROW_2 = 400;

//#define BACKGROUND al_map_rgb(0x09, 0x31, 0x45)
#define BACKGROUND al_map_rgb(0x09, 0x31, 0x45)
#define FOREGROUND al_map_rgb(0x3C, 0x64, 0x78)
#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0,0,0)

// Structures
struct Objects {
    int type;
    int entrance;
    ALLEGRO_BITMAP *image = nullptr;
};



// Prototypes
void initializeAllegroandGame();
void menuRelease(ALLEGRO_BITMAP *credPage, ALLEGRO_BITMAP *credButton, ALLEGRO_BITMAP *instrucPage, ALLEGRO_BITMAP *instrucButton, ALLEGRO_BITMAP *startButton, ALLEGRO_BITMAP *backdrop);

int randomizeLEnt(int randEnt);
char chooseImage(char imFile[], int type);
void fromLeft(ALLEGRO_BITMAP *moveImage, ALLEGRO_BITMAP *backdrop, float v, ALLEGRO_FONT *font2, int deathCount);
void fromDiagLeft(ALLEGRO_BITMAP *moveImage, ALLEGRO_BITMAP *backdrop, float v, ALLEGRO_FONT *font2, int deathCount);
void fromTop(ALLEGRO_BITMAP *moveImage, ALLEGRO_BITMAP *backdrop, float v, ALLEGRO_FONT *font2, int deathCount);
void fromDiagRight(ALLEGRO_BITMAP *moveImage, ALLEGRO_BITMAP *backdrop, float v, ALLEGRO_FONT *font2, int deathCount);
void fromRight(ALLEGRO_BITMAP *moveImage, ALLEGRO_BITMAP *backdrop, float v, ALLEGRO_FONT *font2, int deathCount);

void gameRelease(ALLEGRO_BITMAP *gameBackdrop, ALLEGRO_BITMAP *heroIdle, ALLEGRO_BITMAP *heroLeft, ALLEGRO_BITMAP *heroRight, ALLEGRO_BITMAP *heroTopLeft, ALLEGRO_BITMAP *heroTopRight, ALLEGRO_BITMAP *heroUp);
void leaderBoard(int deathCount, ALLEGRO_FONT *font2);
void waitForExit(ALLEGRO_DISPLAY *display);
