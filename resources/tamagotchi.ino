#include <Wire.h>
#include <SPI.h>
#include <TinyScreen.h>
#include "Tamagotchi.h"

TinyScreen display = TinyScreen(TinyScreenDefault);
int currScreen = PET_SCREEN;
int currentHunger = MAXHUNGER;
int currentHealth = MAXHEALTH;
int currentHappiness = MAXHAPPINESS;
int dialogueCycles = NUM_DIALOGUE_CYCLES;
int deathAnimCycles = MAX_DEATH_ANIM * (PET_FRAME_DELAY * 8 + PET_DEATH_DELAY);

void setup()
{
  Wire.begin(); //initialize I2C before we can initialize TinyScreen- not needed for TinyScreen+
  display.begin();
  display.setBrightness(10);

  DrawPet();
}

void loop()
{
  if (currentHunger <= 1 && currentHealth <= 1 && currentHappiness <= 1)
  {
    if (currScreen != PET_SCREEN)
    {
      currScreen = PET_SCREEN;
    }

    if (deathAnimCycles > 0)
    {
      DrawPetDeath();
      deathAnimCycles--;
    }
    else if (deathAnimCycles == 0)
    {
      RestartText();
      deathAnimCycles--;
    }
    else
    {
      GetRestart();
    }
  }
  else
  {
    StatusDegen(&currentHunger, &currentHealth, &currentHappiness, currScreen);
    StatusActions(&currentHunger, &currentHealth, &currentHappiness, !currScreen);
    GetScreenSwitch();

    if (currScreen == PET_SCREEN)
    {
      DisplayDialogue(&currentHunger, &currentHealth, &currentHappiness);
    }
  }
}

void GetScreenSwitch()
{
  if (display.getButtons(TSButtonLowerLeft))
  {
    display.clearScreen();
    if (currScreen == PET_SCREEN)
    {
      DrawStatus(currentHunger, currentHealth, currentHappiness);
      currScreen = STATS_SCREEN;
    }
    else
    {
      DrawPet();
      currScreen = PET_SCREEN;
    }
    delay(BUTTON_DELAY);
  }
}

int GetRestart()
{
  if (display.getButtons(TSButtonLowerLeft) && display.getButtons(TSButtonUpperRight))
  {
    currentHunger = MAXHUNGER;
    currentHealth = MAXHEALTH;
    currentHappiness = MAXHAPPINESS;
    dialogueCycles = NUM_DIALOGUE_CYCLES;
    deathAnimCycles = MAX_DEATH_ANIM * (PET_FRAME_DELAY * 8 + PET_DEATH_DELAY);
    DrawPet();
  }
}

void RestartText()
{
  display.clearScreen();
  display.setFont(thinPixel7_10ptFontInfo);

  display.setCursor(48 - (display.getPrintWidth("Restart") / 2), 32 - (display.getFontHeight() / 2));
  display.fontColor(TS_8b_White, TS_8b_Black);
  display.print("Restart");

  display.setCursor(0, 44);
  display.fontColor(TS_8b_White, TS_8b_Black);
  display.println("<- Press");

  display.setCursor(95 - display.getPrintWidth("Press ->"), 10);
  display.fontColor(TS_8b_White, TS_8b_Black);
  display.print("Press ->");
}
