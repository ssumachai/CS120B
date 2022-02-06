<h3 align="center">"Oh that's Pitiful"</h3>
<p align="center">A <i>Genshin Impact</i> Wish Pity Simulator</p>
<p align="center">Author: Sumachai Suksanguan, SSID 862012882 </p>

# Premise

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

| Rarity                      | Drop Rate   |
| --------------------------- | ----------- |
| 5* Character                | 0.6%        |
| 4* Character/Weapon         | 5.1%        |
| 3* Character                | 94.3%       |

As you can see, the drop rate for a 5-Star Rarity Character is less than 1%!  Even 4-Stars are rare at roughly 5%, which is why there is a built in fail-safe that helps players
obtain the characters they want.  The way the official documentation describes it is (Don't bother reading this, as there is a TLDR immediately below):

> For Event Wish "Gentry of Hermitage": Base probability of winning 5-star character = 0.600%; consolidated probability (incl. guarantee) = 1.600%; guaranteed to win 5-star 
character at least once per 90 attempts. The first time you win a 5-star item in this event wish, there is a 50.000% chance it will be the promotional character "Vago Mundo" 
Zhongli (Geo). If the first 5-star character you win in this event wish is not the promotional character, then the next 5-star character you win is guaranteed to be the 
promotional character.

> For Event Wish "Gentry of Hermitage": Base probability of winning 4-star item = 5.100%; base probability of winning 4-star character = 2.550%, and base probability of winning 
4-star weapon = 2.550%; consolidated probability (incl. guarantee) of winning 4-star item = 13.000%; guaranteed to win 4-star or above item at least once per 10 attempts; 
probability of winning 4-star item through the guarantee = 99.400%, and probability of winning 5-star item through the guarantee = 0.600%.
The first time you win a 4-star item in this event wish, there is a 50.000% chance it will be one of the featured characters "Juvenile Galant" Xingqiu (Hydro), 
"Uncrowned Lord of the Ocean" Beidou (Electro), and "Wise Innocence" Yanfei (Pyro). If the first 4-star item you win in this event wish is not one of the featured characters, 
then the next 4-star item you win is guaranteed to be a featured character. When you win a featured 4-star item, the probability of obtaining each featured 4-star character 
is equal between all of them.

Let's translate this into something that people can actually understand though...essentially, if you wish 9 times and haven't received a 4 star yet, it is GUARANTEED that your
10th wish will be a 4-Star!  Likewise, if you have wished 89 times and haven't received a 5-Star Character yet, it is GUARANTEED that your 90th wish will be the 5-Star!  For
fairness, your pity for those respective draws is reset once obtaining a 4* or 5*

## 50/50

So now that drop rates have been explained, onto the next part. What players often call the "50/50" is an ingame mechanic that messes with your draws just a little bit.  Essentially
on every banner, there are "featured" characters, and then the base characters.  Everytime you receive a 4* or 5* unit, there is a 50% that the unit will be the featured unit.
In the event that you receive the non-featured unit, the next unit you receive will be the featured unit.  This is commonly known as "Losing the 50/50 and having Guarantee".
Attaining the character without obtaining a non-featured unit first is commonly know as "Winning the 50/50"

# CS120B Implementation

What I plan to create using this logic and game-of-chance, is a Pity simulator with a GUI that uses several additional hardware to simulate the wishing experience as similarily
as possible.  The machine will allow players to wish in increments of 1 and 10, to see if they can obtain the characters they want.  The aim is for players to be able to simulate
on my machine before they use their real resources to wish in the actual game.  It's essentially a glorified slot machine, but it's something I have fun with, so I figured I would
do this.

## Hardware Components

The machine isn't going to be too hard to implement physically, as most of the logic will come from the Pity system, and user input will be fairly simiplified.  As a result, I intend
to use the following:

- Computing
  - Elegoo UNO R3
  - ATMega1284 Microcontroller
    - Will Most likely have to use due to sheer amount of input/output needed
- Inputs
  - 1 Wish and 10 Wish Button
    - Pushing Both Buttons will Reset the Counter
  - Joystick
    - Used to Navigate Menus
- Outputs
  - Nokia 5110 LCD Screen
    - Used to display Character/Item Render (will be primitive)
  - Multiple Colored LEDs to simulate character rarity
    - Blue: 3-Star
    - Purple: 4-Star
    - Gold: 5-Star
  - LED Screen
    - Will display Character/Item Name + Rarity
    - Will display Respective Pity/Guarantee when in Menu Selection

<p align="center"><img src="https://media.discordapp.net/attachments/890667694045667388/939994991034531850/image.png?width=1437&height=710"/></p>
<p align="center">Note: Pin assumption is based on what I currently have seen online as recommended number of ports, and is Subject to Change</p>

## Basic Functionality

The baseline version of my Pity Simulator will be a single-user experience.  The machine will start off in the default menu, which will give users the option of either wishing
or checking their current pity/guarantee.  The joystick will be used to navigate the menu, via directional cues, while pressing the joystick will select that menu option.

When wishing, users may either press the "1 Wish" Button to wish a single time, or the "10 Wish" button to do a multiwish.  All wish animations are done separately, and can be
skipped by pressing the same button again.  If the user presses both the "1 Wish" and "10 Wish" button at the same time, they will be prompted with the request to Reset.  Pressing
the joystick will confirm that reset, and any other input will cancel it.

<p align="center"><img src="https://media.discordapp.net/attachments/890667694045667388/939997525409169408/image.png?width=1023&height=709"/></p>
<p align="center">Note: This is a proposed output of how the Nokia 5110 and LED Display will render</p>

## Complexities

1. Using a Nokia 5110 LCD Screen to display the Character Wish Screen
2. Using complex variable array that continues varying Character/Weapons/Pity
  - Note: Code will be Object Oriented, as most characters that are "obtainable" will have to store the name, rarity, and image to be displayed
3. Using a Joystick to navigate between Menus


