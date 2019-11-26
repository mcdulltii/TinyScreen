#include <TinyScreen.h>
#include <SPI.h>
#include <Wire.h>
#include <time.h>
#include "Tamagotchi.h"

const uint16_t BITMAP_ALPHA;

const unsigned char HeartBitmap[] = {
    BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Black, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Black, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
    BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Black, BITMAP_ALPHA, TS_8b_Black, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA,
    BITMAP_ALPHA, TS_8b_Black, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Black, TS_8b_Red, TS_8b_Red, TS_8b_White, TS_8b_White, TS_8b_Red, TS_8b_Black, BITMAP_ALPHA,
    TS_8b_Black, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_White, TS_8b_White, TS_8b_Red, TS_8b_Red, TS_8b_Black,
    TS_8b_Black, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Black,
    TS_8b_Black, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Black,
    TS_8b_Black, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Black,
    TS_8b_Black, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Black,
    BITMAP_ALPHA, TS_8b_Black, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, BITMAP_ALPHA,
    BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA,
    BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
    BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
    BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Red, TS_8b_Red, TS_8b_Red, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
    BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Red, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
    BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA};

const unsigned char HungerBitmap[] = {
    BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
    BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
    BITMAP_ALPHA, TS_8b_Black, TS_8b_Brown, TS_8b_White, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
    TS_8b_Black, TS_8b_Brown, TS_8b_White, TS_8b_White, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
    TS_8b_Black, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
    TS_8b_Black, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
    TS_8b_Black, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
    BITMAP_ALPHA, TS_8b_Black, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
    BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
    BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
    BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_Brown, TS_8b_White, TS_8b_Black, TS_8b_Black, BITMAP_ALPHA,
    BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_White, TS_8b_White, TS_8b_White, TS_8b_White, TS_8b_Black,
    BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_White, TS_8b_White, TS_8b_White, TS_8b_Black,
    BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_White, TS_8b_White, TS_8b_Black, BITMAP_ALPHA,
    BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA};

const unsigned char HappinessBitmap[] =
    {
        BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Black, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
        BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
        BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
        BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA,
        BITMAP_ALPHA, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, BITMAP_ALPHA,
        TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black,
        TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black,
        TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black,
        TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black,
        TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black,
        BITMAP_ALPHA, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, BITMAP_ALPHA,
        BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA,
        BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
        BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA,
        BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, TS_8b_Black, TS_8b_Black, TS_8b_Black, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA, BITMAP_ALPHA};

void DrawBitmapHunger()
{
  // setting up the bitmap to be at 0,0 idk why but bitmap <<< is 0 instead of >>> being 0.
  //setX(x start, x end);//set OLED RAM to x start, wrap around at x end
  display.setX(0, 0 + 15 - 1);
  //setY(y start, y end);//set OLED RAM to y start, wrap around at y end
  display.setY(1, 0 + 15 - 1);
  //now start a data transfer
  display.startData();
  //writeBuFFer(buffer,count);//optimized write oF a large buFFer oF 8 bit data.
  display.writeBuffer(HungerBitmap, 15 * 15);
  display.endTransfer();
}

void DrawBitmapHealth()
{
  // setting up the bitmap to be at 0,30 idk why but bitmap <<< is 0 instead of >>> being 0.
  //setX(x start, x end);//set OLED RAM to x start, wrap around at x end
  display.setX(0, 0 + 15 - 1);
  //setY(y start, y end);//set OLED RAM to y start, wrap around at y end
  display.setY(21, 20 + 15 - 1);
  //now start a data transfer
  display.startData();
  //writeBuFFer(buffer,count);//optimized write oF a large buFFer oF 8 bit data.
  display.writeBuffer(HeartBitmap, 15 * 15);
  display.endTransfer();
}

void DrawBitmapHappiness()
{
  // setting up the bitmap to be at 0,0 idk why but bitmap <<< is 0 instead of >>> being 0.
  //setX(x start, x end);//set OLED RAM to x start, wrap around at x end
  display.setX(0, 0 + 15 - 1);
  //setY(y start, y end);//set OLED RAM to y start, wrap around at y end
  display.setY(41, 40 + 15 - 1);
  //now start a data transfer
  display.startData();
  //writeBuFFer(buffer,count);//optimized write oF a large buFFer oF 8 bit data.
  display.writeBuffer(HappinessBitmap, 15 * 15);
  display.endTransfer();
}

void DrawStatus(int currentHunger, int currentHealth, int currentHappiness)
{
  DrawBitmapHunger();
  DrawBitmapHealth();
  DrawBitmapHappiness();
  display.setColorMode(TSColorModeBGR);

  display.drawRect(X_CORD, Y_HUNGER, currentHunger, BARHEIGHT, TSRectangleFilled, HUNGER_COLOUR);         // Hunger
  display.drawRect(X_CORD, Y_HEALTH, currentHealth, BARHEIGHT, TSRectangleFilled, HEALTH_COLOUR);         // Health
  display.drawRect(X_CORD, Y_HAPPINESS, currentHappiness, BARHEIGHT, TSRectangleFilled, HAPPINESS_COLOR); // Happiness
}

void StatusActions(int *currentHunger, int *currentHealth, int *currentHappiness, int isPetScreen)
{
  // Buttons and Regeneration Portion
  if (display.getButtons())
  {
    if (display.getButtons(TSButtonUpperLeft))
    {
      if (*currentHunger + HUNGER_REG < MAXHUNGER)
        *currentHunger += HUNGER_REG;
      else
        *currentHunger = MAXHUNGER;
      if (!isPetScreen)
        display.drawRect(X_CORD, Y_HUNGER, *currentHunger, BARHEIGHT, TSRectangleFilled, HUNGER_COLOUR);
    }
    if (display.getButtons(TSButtonUpperRight) || (*currentHunger >= HEALTH_THRESHOLD && *currentHealth != MAXHEALTH))
    {
      if (*currentHealth + HEALTH_REG < MAXHEALTH)
        *currentHealth += HEALTH_REG;
      else
        *currentHealth = MAXHEALTH;
      if (!isPetScreen)
        display.drawRect(X_CORD, Y_HEALTH, *currentHealth, BARHEIGHT, TSRectangleFilled, HEALTH_COLOUR);
    }
    if (display.getButtons(TSButtonLowerRight) || (*currentHunger >= HEALTH_THRESHOLD && *currentHealth >= HAPPINESS_THRESHOLD && *currentHappiness != MAXHAPPINESS))
    {
      if (*currentHappiness + HAPPINESS_REG < MAXHAPPINESS)
        *currentHappiness += HAPPINESS_REG;
      else
        *currentHappiness = MAXHAPPINESS;
      if (!isPetScreen)
        display.drawRect(X_CORD, Y_HAPPINESS, *currentHappiness, BARHEIGHT, TSRectangleFilled, HAPPINESS_COLOR);
    }

    delay(BUTTON_DELAY);
  }
}

void StatusDegen(int *currentHunger, int *currentHealth, int *currentHappiness, int isStatusScreen)
{
  int milliseconds = (int)millis();
  if (milliseconds % TICK_RATE == 0)
  {
    if (*currentHunger - HUNGER_DEG > 1)
      *currentHunger -= HUNGER_DEG;
    else
      *currentHunger = 1;
    if (isStatusScreen)
      display.clearWindow(X_CORD + *currentHunger, Y_HUNGER, MAXHUNGER - *currentHunger, BARHEIGHT);

    if (*currentHunger < HEALTH_THRESHOLD)
    {
      if (*currentHealth - HEALTH_DEG > 1)
        *currentHealth -= HEALTH_DEG;
      else
        *currentHealth = 1;
      if (isStatusScreen)
        display.clearWindow(X_CORD + *currentHealth, Y_HEALTH, MAXHEALTH - *currentHealth, BARHEIGHT);
    }

    if (*currentHunger < HEALTH_THRESHOLD && *currentHealth < HAPPINESS_THRESHOLD)
    {
      if (*currentHappiness - HAPPINESS_DEG > 1)
        *currentHappiness -= HAPPINESS_DEG;
      else
        *currentHappiness = 1;
      if (isStatusScreen)
        display.clearWindow(X_CORD + *currentHappiness, Y_HAPPINESS, MAXHAPPINESS - *currentHappiness, BARHEIGHT);
    }
  }
}
