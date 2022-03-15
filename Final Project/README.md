<h1 align="center">CS/EE 120B Custom Laboratory Project Report</h1>
<h2 align="center">"Oh that's Pitiful"</h2>
<h3><p align="center">A <i>Genshin Impact</i> Wish Pity Simulator</p></h3>
<h4><p align="center">Author: Sumachai Suksanguan, SSID 862012882<br>March 15, 2022</p></h4>

# Introduction

<i>Genshin Impact</i> has taken the the mobile gaming world by storm, thanks to it's unique take on the otherwise predatory gacha-styled games that Japan
is known for.  By way of unique elemental reactive experiences, refreshing open-world gameplay, and consistent updates every 1.5 Months, the game has done well
to keep it's current audience for nearly 1.5 years now.

<p align="center"><img src="https://external-preview.redd.it/KJwns5aBukPb-saHHOHIJD0UIWkMdXddo9uL_gwHenU.jpg?width=640&crop=smart&auto=webp&s=5026122b3ee3aec46c3876a3071ee29ef8637396"/></p>
<p align="center">Note: The above image is from a recent version announcement, that incuded new updates to the game and QoL Mechanics.</p>

# What is "Pity" and why is it relevant in the scope of this class?

Many gacha games oftentimes release with a number of characters that are given to everyone.  These are often referred to you as your "free options" or starting characters.  The
unique gameplay mechanic that most of these games come with is that future characters may be obtained by "Wishing" for them (in the case of <i>Genshin Impact</i>).

By accumulating in-game resources, players can attempt to obtain a new character or weapon by using those resources to perform <b>One</b> Wish.  Unlike other games, <i>Genshin Impact</i>
has a mechanic known as "Pity" that helps guarantees players receive a high-rarity character at certain wish amounts:

## Drop Rates

Currently, in the typical limited time banner, the drop rate is as follows assuming 0 Pity (Meaning you have not attempted to pull for the new character yet):

| Rarity                      | Drop Rate   | Int Range |
| --------------------------- | ----------- | --------- |
| 5* Character                | 0.6%        | 1 - 6     |
| 4* Character/Weapon         | 5.1%        | 7 - 57    |
| 3* Character                | 94.3%       | 58 - 1000 |

As you can see, the drop rate for a 5-Star Rarity Character is less than 1%!  Even 4-Stars are rare at roughly 5%, which is why there is a built in fail-safe that helps players
obtain the characters they want.  The way the official documentation describes it is (Don't bother reading this, as there is a TLDR immediately below):

We obtain the drop rates of the objects by utilizing the `pull()` function, as well as checking global variables `five_star_pity` and `five_rate` to set drop rates accordingly.

## How Wishing Works

When the user wishes for an object, the system will use the `pull()` function and generate a random number between 1 and 1000.  The rarity of the object dropped is determined on the Int Range mentioned above.

Therefore, drawing the number, 871, will yield a three-star object.  The object is determined by another random number, that determines which random three-star item to select from the array of all available three-star objects, that info is also displayed in the serial monitor as follows:

<img src="https://media.discordapp.net/attachments/890667694045667388/953119599593930883/unknown.png"/>

> Note: That because a three star object was drawn, both 4-Star and 5-Star pity are incremented

What the user sees on screen is then this:

<img src="https://media.discordapp.net/attachments/890667694045667388/953120288122503188/IMG_4802.jpg?width=1659&height=624"/>

> Note: In `three_star.h`, the first item in the array of three-star objects is a Random Sword.


## How Pity Works

Let's translate this into something that people can actually understand though...essentially, if you wish 9 times and haven't received a 4 star yet, it is GUARANTEED that your
10th wish will be a 4-Star!  Likewise, if you have wished 89 times and haven't received a 5-Star Character yet, it is GUARANTEED that your 90th wish will be the 5-Star!  For
fairness, your pity for those respective draws is reset once obtaining a 4* or 5*

### Four-Star Pity

Example:  If the user is at 9 Pity before drawing a four star, their next object is guaranteed to be a four-star, **regardless** of what number is drawn.

<img src="https://media.discordapp.net/attachments/890667694045667388/953120740142633000/unknown.png"/>

<img src="https://media.discordapp.net/attachments/890667694045667388/953121325055098961/IMG_4803.jpg?width=1659&height=701"/>

> Note: Because the four-star pity was at 9, the 10th draw resulted in a four-star unit, even though the draw number was 761, which corresponds to a three-star unit.

As you can see, the pity system allows the user to get a guaranteed 4 star, as long as he did not pull a four star within the nine pulls leading up to the tenth.  Also note how the four-star pity was immediately reset back to 0 upon receiving a four-star unit.

### Five-Star Pity

Five-Star Pity is a bit trickier to explain, but still feasible.  Because the drop rate of a five-star character is so low, there is a built in "soft-pity" system that increases the drop rate of a five-star substantially when the user hits a center number.  This **includes** the guarantee the user has at 90 though, but this makes it so that it may potentially arrive early.

| Five-Star Pity (Wishes)     |  Drop Rate  | Int Range |
| --------------------------- | ----------- | --------- |
| 0 - 74                      | 0.6%        | 1 - 6     |
| 75                          | 20%         | 1 - 200    |
| 75+                         | 20% + 3% Each Iteration       | 1 - (230 + 30i) |
|90 | Guaranteed | Guaranteed|

> Note: *i* represents the amount of additional wishes after 75.

So while a user can still definitely get lucky with the system, it begins to make it easier on the user from 75 wishes and onwards.

Example: The user was at 74 Pity, and because the drop rate of a five-star increases for the 75th wish, they got **Yae Miko**, a five-star character on their 75th wish.

<img src="https://media.discordapp.net/attachments/890667694045667388/953123928384090214/IMG_4804.jpg?width=1659&height=613"/>

<img src="https://media.discordapp.net/attachments/890667694045667388/953124424725434378/unknown.png"/>

# Complexities

The project utilized three complexities that were as follows:
* Joystick
* Loot System
* Nokia 5110 LCD

## Joystick Implementation

The joystick was the first complexity, and served as a menu selector that interfaced with the 16x2 LCD.  The system featured it's own task designed solely for handling the joystick, with this main body of text handling most of the work:

By reading the joystick `VRx` and `VRy` inputs with analog ports, I made it so that any substantial movements in the appropriate direction were read by the system.  There is no need for omnidirectional movement, as the purpose of the joystick is to simulate arrow movement, so either up or down, and left or right.

We know the Joystick shifts into a negative position in either the x- or y-direction when its read value is nearly 0, so I just gave it a grace period of less than 200.  Likewise, positive direction is within the 1000 range, so it also has a grace period of 800 or greater.


```c++
            if(xValue < 200 && (yValue >= 200 && yValue <= 1100)){
                state = joy_left;
            }
            else if(xValue > 800 && (yValue >= 200 && yValue <= 1100)){
                state = joy_right;
            }
            else if(yValue < 200 && (xValue >= 200 && xValue <= 1100)){
                state = joy_up;
            }
            else if(yValue > 800 && (xValue >= 200 && xValue <= 1100)){
                state = joy_down;
            }
            else{
                state = joy_idle;
            }
```

The joystick was mainly used to interface with a menu, as the joystick controlled the Arrow Indicator that the user sees on screen.  When pressing the joystick, the system "selects" the option that is being pointed to by the arrow indicator.

## Loot System

The loot and object system is the heart and sole of this project, as everything revolves around it and the game logic.  To give a brief summary, there are four additional header files: `unit.h`, `three_star.h`, `four_star.h`, and `five_star.h`.

The system revolves around users obtaining objects of type `Unit`, which is defined in `unit.h`.  These units have a:
* `rarity`
* `index`
* `character_name`
* `printToDisplay()` - Print Function

They *would* have another member variable `artwork`, if the memory required for those isn't so expensive.  Giving all objects a member variable of a huge character array takes up a hefty amount of space after a while, so the work-around I developed was determining artwork via `rarity` and `index`.

As of final implementation, there are a total of __14 Obtainable Units__ in the game.  These units are down below:

Character Name  | Rarity | Index |
--------------- | ------ | ----- |
Random Sword    |   3    |   0
Random Bow      |   3    |   1
Random Claymore |   3    |   2
Random Catalyst |   3    |   3
Random Polearm  |   3    |   4
Bennett         |   4    |   0
Xinyan          |   4    |   1
Kujou Sara      |   4    |   2
Yae Miko        |   5    |   0
Klee            |   5    |   1
Jean            |   5    |   2
Qiqi            |   5    |   3
Keqing          |   5    |   4
Tartaglia       |   5    |   5



Within the `nokia_wish` state, the system determines the artwork to be used as such:
```c++
            switch(curr_unit.rarity){
                case 3:
                    display.drawBitmap(0, 0, three_art_array[curr_unit.index], 84, 48, BLACK);
                    break;
                case 4:
                    display.drawBitmap(0, 0, four_art_array[curr_unit.index], 84, 48, BLACK);
                    break;
                case 5:
                    display.drawBitmap(0, 0, five_art_array[curr_unit.index], 84, 48, BLACK);
                    break;
```

### How Does a User obtain a unit

When the user follows the prompts to do a pull, the `pull()` function is then utilized.  The `pull()` function will generate a random number between 1 and 1000, and then the temp `Unit` named `curr_unit` is then assigned the corresponding unit.  The current unit is then written to the 16x2 LCD via it's own print function, and then to the Nokia LCD via the Nokia Task Handling.

## Nokia 5110 LCD

The Nokia 5110 LCD is utilized to display the artwork of the accompanying characters, as well as serve as "Instructions" when in certain states. 

Writing text to the Nokia LCD was done via the `display.println()` function. 

Drawing images were done by:
* Converting the desired image to 84 x 48 Pixels
* Saving the image as a monochrome bitmap (File Extension `.bmp`)
* Converting the bitmap to an appropriate `const unsigned char []` via <a href="https://javl.github.io/image2cpp/">online converter</a>.
* Using the `display.drawBitmap()` function

# User Guide

For the purpose of this section, annotated notes are placed at the bottom of each picture to discribe what each LCD is currently illustrating

Upon flashing the code onto the system, the user is met with a Home Screen.

<img src="https://media.discordapp.net/attachments/890667694045667388/953131838258413638/IMG_4805.jpg?width=1659&height=678"/>

> 16x2 LCD: Menu Options<br>Nokia LCD: Title and Description

The user can then either choose to do some Wish Simulations via the first option, or check their Pity History via the second option.

## Wish Simulator

Upon selecting Wish Simulator, users may either choose to use a single wish, or ten wishes done one after the other.  The user also has the option to return to the home menu at any point by pressing the Joy-Stick.

The user may also reset their pity at any point by pressing both buttons at the same time, and confirming.

<img src="https://media.discordapp.net/attachments/890667694045667388/953133468529860668/IMG_4806.jpg?width=1659&height=689"/>

> 16x2 LCD: Indicates which Button Corresponds to Wish Count<br>Nokia LCD: Additional Commands

### 1 Pull

Users can pull for units one at a time.  After pressing the appropriate button, they will be asked to confirm they wish to use 1 Pull.

<img src="https://media.discordapp.net/attachments/890667694045667388/953133470593474560/IMG_4807.jpg?width=1659&height=618"/>

> 16x2 LCD: 1 Wish Prompt<br>Nokia LCD: Additional Instructions

<img src="https://media.discordapp.net/attachments/890667694045667388/953133464373313556/IMG_4808.jpg?width=1659&height=650"/>

> 16x2 LCD: Item Pulled<br>Nokia LCD: Item Image

After their wish, users must move up with the joystick to bring up the wish confirmation screen.

<img src="https://media.discordapp.net/attachments/890667694045667388/953133469549101056/IMG_4809.jpg?width=1659&height=702"/>

> 16x2 LCD: 1 Wish Confirmation<br>Nokia LCD: Previous Item Image

Users may then return to the initial wish-screen by pressing the joystick after their single wish has completed.

### 10 Pull

Users can pull for ten units, albeit one at a time.  After pressing the appropriate button, they will be asked to confirm they wish to use 10 Pull.

<img src="https://media.discordapp.net/attachments/890667694045667388/953133469515517962/IMG_4810.jpg?width=1659&height=602"/>

> 16x2 LCD: 10 Wish Prompt<br>Nokia LCD: Additional Instructions

<img src="https://media.discordapp.net/attachments/890667694045667388/953133463110815784/IMG_4811.jpg?width=1659&height=677"/>

> 16x2 LCD: Item Pulled. Item Number is indicated on bottom Right.<br>Nokia LCD: Item Image

After their final wish (10/10), users must move up with the joystick to bring up the wish confirmation screen.

<img src="https://media.discordapp.net/attachments/890667694045667388/953133470228557824/IMG_4812.jpg?width=1659&height=669"/>

> 16x2 LCD: 1 Wish Confirmation<br>Nokia LCD: Previous Item Image

Users may then return to the initial wish-screen by pressing the joystick after their single wish has completed.

### Reset

Users may reset their pity while in the Wish Simulator, and all they need to do is press both wish buttons at the same time.  Pressing both will cause the system to enter the initial wish screen, and then immediately take you into the reset confirmation menu:

<img src="https://media.discordapp.net/attachments/890667694045667388/953137765661429770/IMG_4814.jpg?width=1659&height=668"/>

> 16x2 LCD: Prior Pity to Reset<br>Nokia LCD: Additional Commands

<img src="https://media.discordapp.net/attachments/890667694045667388/953137764709310584/IMG_4815.jpg?width=1659&height=635"/>

> 16x2 LCD: Reset Confirmation<br>Nokia LCD: Reset Warning

<img src="https://media.discordapp.net/attachments/890667694045667388/953137769004285972/IMG_4816.jpg?width=1659&height=631"/>

> 16x2 LCD: Reset Occuring<br>Nokia LCD: Reset Warning

<img src="https://media.discordapp.net/attachments/890667694045667388/953137761819455508/IMG_4817.jpg?width=1659&height=604"/>

> 16x2 LCD: Pity after Reset<br>Nokia LCD: Additional Commands


## Pity History

Upon selecting the Pity History option, viewers can then see their pity towards four-star and five-star units respectively.  To return to the main menu, all users need to do is press the joystick:

<img src="https://media.discordapp.net/attachments/890667694045667388/953137767427244072/IMG_4813.jpg?width=1659&height=619"/>

> 16x2 LCD: Menu with Pity History Toggled<br>Nokia LCD: Addtional Commands

<img src="https://media.discordapp.net/attachments/890667694045667388/953137765661429770/IMG_4814.jpg?width=1659&height=668"/>

> 16x2 LCD: Current Pity History<br>Nokia LCD: Additional Commands

# Hardware Components Used

The system that was created was a Pity simulator with a GUI that uses several additional hardware to simulate the wishing experience as similarily as possible.

Parts Used:
- Computing
  - Elegoo UNO R3 Controller Board
- Inputs
  - x2 Buttons
  - x1 Joystick
- Outputs
  - Nokia 5110 LCD Screen
  - LCD1602 Module

 # Software Libraries Used

 The system was primarily coded with my own methods and knowledge, however additional libraries were used in order to interface with both the 16x2 LCD and the Nokia 5110 LCD.

 Libraries Used:
 - `LiquidCrystal.h`
   - Used to interface with 16x2 LCD
   - `lcd.print(F("Your Message Here"));` to print to screen
 - `SPI.h`
   - Required to interface with Nokia LCD and corresponding Libraries
 - `Adafruit_GFX.h`
   - Required to interface with Nokia LCD and corresponding libraries
 - `Adafruit_PCD8544.h`
   - Arduino Driver for interfacing with Nokia 5110 LCD
   - `display.println(F("Your Message Here));` to print to screen
   - `display.drawBitmap(0, 0, myBitmap, 84, 48, BLACK)` to draw to screen

# Wiring Diagram

## Digital Setup

<img src="https://media.discordapp.net/attachments/890667694045667388/953154592198258698/image.png?width=644&height=805"/>

## Physical Setup

<img src="https://media.discordapp.net/attachments/890667694045667388/953154979349270579/IMG_4818.jpg?width=909&height=805"/>

## Devices and Their Ports

### Nokia 5110 LCD:

PIN      | PORT       |
-------- | ---------- |
VCC      | 3.3V       |
GND      | Ground     |
SCE      | Digital 10 |
RST      | Digital 11 |
D/C      | Digital 12 |
DN<MOSI> | Analog 4   |
SCLK     | Digital 13 |
LED      | Digital 9  |

### LCD1602 Module

PIN     | PORT          | 
------- | ------------- |
VSS     | Ground        |
VDD     | 5V            |
V0      | Potentiometer |
RS      | Digital 2     |
RW      | Ground        |
E       | Digital 3     |
D0 - D3 | None Needed   |
D4 - D7 | Digital 4 - 7 |
A       | 5V            |
K       | Ground        |

### Joystick

PIN | PORT      |
--- | --------- |
GND | Ground    |
+5V | 5V        |
VRx | Analog 0  |
VRy | Analog 1  |
SW  | Digital 8 |

### Buttons

PIN     |  PORT    |
------- | -------- |
BUTTON1 | Analog 3 |
BUTTON2 | Analog 2 |

### Random Seeding (Used in `pull()`)

PIN  | PORT     |
---- | -------- |
SEED | Analog 5 |
 
# Task Diagram

There are four tasks in this system, all of which correspond to the:
* Wish System
* LCD1602 Output
* Nokia LCD Output
* Joystick Control

<img src="https://cdn.discordapp.com/attachments/890667694045667388/953165525414985838/unknown.png"/>

# SynchSM Diagrams

## Wish SM

<img src="https://media.discordapp.net/attachments/890667694045667388/953180710930382898/image.png?width=615&height=805"/>

## LCD SM

<img src="https://media.discordapp.net/attachments/890667694045667388/953185517703401472/image.png?width=645&height=806"/>

## Nokia SM

<img src="https://media.discordapp.net/attachments/890667694045667388/953187857680453652/image.png?width=725&height=805"/>

## Joystick SM

<img src="https://media.discordapp.net/attachments/890667694045667388/953189215355682846/image.png?width=499&height=806"/>