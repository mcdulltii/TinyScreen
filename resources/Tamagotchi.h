#ifndef Tamagotchi_H
#define Tamagotchi_H

#include <TinyScreen.h>

#define BUTTON_DELAY 300

// Display
#define PET_SCREEN 0
#define STATS_SCREEN 1

void DrawScreen(unsigned char frame, const unsigned char *SPRITE_XY, const unsigned char *const *SPRITE_ARR, int numFrames);
void DrawSprite(long SpritePointer, unsigned char SpriteSize_X, unsigned char SpriteSize_Y, unsigned char x, unsigned char y, unsigned char line_n);
void DrawPet();
void DrawPetDeath();

// Sprite
#define ALPHA 0xFE
#define BACKGROUND 0x00
#define PET_FRAME_DELAY 100
#define PET_DEATH_DELAY 2000
#define MAX_DEATH_ANIM 5

// Status
#define X_CORD 26
#define BARHEIGHT 15
#define Y_HUNGER 3
#define Y_HEALTH 23
#define Y_HAPPINESS 43

#define MAXHUNGER 70
#define MAXHEALTH 70
#define MAXHAPPINESS 70
#define HUNGER_REG 5
#define HEALTH_REG 5
#define HAPPINESS_REG 5
#define HUNGER_DEG 1
#define HEALTH_DEG 1
#define HAPPINESS_DEG 1
#define HEALTH_THRESHOLD 35
#define HAPPINESS_THRESHOLD 35

#define TICK_RATE 200

#define HUNGER_COLOUR TS_8b_Yellow
#define HEALTH_COLOUR TS_8b_Red
#define HAPPINESS_COLOR TS_8b_Green

void DrawBitmapHunger();
void DrawBitmapHealth();
void DrawBitmapHappiness();

void DrawStatus(int currentHunger, int currentHealth, int currentHappiness);
void StatusActions(int *currentHunger, int *currentHealth, int *currentHappiness, int isPetScreen);
void StatusDegen(int *currentHunger, int *currentHealth, int *currentHappiness, int isStatusScreen);

// Dialogue
#define NUM_DIALOGUE_CYCLES 10000
#define DIALOGUE_FRAME_DELAY 100
#define DIALOGUE_DELAY 1000
#define DIALOGUE_THRESHOLD 45

#define HUNGER_DIALOGUE 0
#define HEALTH_DIALOGUE 1
#define HAPPINESS_DIALOGUE 2

void DisplayDialogue(int *currentHunger, int *currentHealth, int *currentHappiness);
void DrawDialogue(int dialogue);

#endif
