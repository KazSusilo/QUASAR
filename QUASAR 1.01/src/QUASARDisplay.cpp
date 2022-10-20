#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>                       // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h> 		// for message box
#include "QUASAR.h"
#include <stdlib.h>
#include <time.h>

void leaderBoard(int deathCount, ALLEGRO_FONT *font2){
    // Variables For High Scores
    int highScores [11];
    int score = 0;
    int i = 0;
    int j = 0;
    int tempScore1 = 0;
    int tempScore2 = 0;
    bool scoreMet = false;

    ALLEGRO_BITMAP *scorePage = nullptr;
    scorePage = al_load_bitmap("HighScoresPage.png");

    FILE *HighScores;
    // Opens HighScores File To Read Information
    HighScores = fopen("HighScores.txt", "r");

    // Populates Array With High Scores
    while (i < 10){
        fscanf(HighScores, "%d", &score);
        highScores[i] = score;
        i++;
    }
    // Closes HighScores File
    fclose(HighScores);

    // Integrates Current Score Into High Scores Assuming The Score Is In The Top 10
    tempScore1 = deathCount;
    while (j < 10){
        i = 0;
        while (i < 10){
            if (tempScore1 > highScores[i]){
                tempScore2 = highScores[i];
                highScores[i] = tempScore1;
                break;
            }
            i++;
        }
        tempScore1 = tempScore2;
        tempScore2 = 0;
        j++;
    }
    // Opens HighScores.txt To Write To It
    HighScores = fopen("HighScores.txt", "w");

    i = 0;
    while (i < 10){
        fprintf(HighScores, "\n");
        fprintf(HighScores, "%d", highScores[i]);
        i++;
    }
    // Closes HighScores.txt
    fclose(HighScores);

    // Displays Backdrop For The Leaderboards
    al_draw_bitmap(scorePage, 0, 0, 0);

    // Displays The Top Ten Scores As Well As Your Score
    al_draw_textf(font2, WHITE, 200, 350, ALLEGRO_ALIGN_LEFT, "1. %d", highScores[0]);
    al_draw_textf(font2, WHITE, 400, 350, ALLEGRO_ALIGN_LEFT, "2. %d", highScores[1]);
    al_draw_textf(font2, WHITE, 600, 350, ALLEGRO_ALIGN_LEFT, "3. %d", highScores[2]);
    al_draw_textf(font2, WHITE, 800, 350, ALLEGRO_ALIGN_LEFT, "4. %d", highScores[3]);
    al_draw_textf(font2, WHITE, 1000, 350, ALLEGRO_ALIGN_LEFT, "5. %d", highScores[4]);

    al_draw_textf(font2, WHITE, 200, 450, ALLEGRO_ALIGN_LEFT, "6. %d", highScores[5]);
    al_draw_textf(font2, WHITE, 400, 450, ALLEGRO_ALIGN_LEFT, "7. %d", highScores[6]);
    al_draw_textf(font2, WHITE, 600, 450, ALLEGRO_ALIGN_LEFT, "8. %d", highScores[7]);
    al_draw_textf(font2, WHITE, 800, 450, ALLEGRO_ALIGN_LEFT, "9. %d", highScores[8]);
    al_draw_textf(font2, WHITE, 1000,450, ALLEGRO_ALIGN_LEFT, "10. %d", highScores[9]);

    al_draw_textf(font2, WHITE, 640, 600, ALLEGRO_ALIGN_CENTRE, "Your Score: %d", deathCount);
    al_draw_text(font2, WHITE, 1280, 0, ALLEGRO_ALIGN_RIGHT, "ESC");

    al_flip_display();
}
