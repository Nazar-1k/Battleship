# Battleship
The mini game is written the library (SFML)

# About this game

This is a very interesting idea for a game, but with my ideas (I wanted to implement a manual arrangement of cells, but after doing a certain part I realized that the arrangement options only increase (too huge scales and probably not even 100,000 lines will be enough to describe it) and I came to conclusion that ideally I will not make this game) therefore, I postponed this game for an indefinite term, let's tell and show what I implemented at this stage:

# Window
![image](https://user-images.githubusercontent.com/82716260/218277560-71bb6b5d-c021-4df0-aa52-3fbb524d2a73.png)
We have a simple menu with buttons (to start the game, information "which is not there", and to exit the game) and two fields for the player and the enemy.

![image](https://user-images.githubusercontent.com/82716260/218277760-4dbb7d0f-6bd0-45d7-b060-35ea12538d35.png)
The game has hovers, on buttons and on cells on the field.
![image](https://user-images.githubusercontent.com/82716260/218277926-c6ce19b6-9126-4c80-b1a2-635ac411d9f9.png)
I'll tell you a little about the manual setting, when we choose it, that's when the problems begin, because the variability of creating ships is so great, it brought me to tears...
Let's talk about the good thing, I managed to implement a linear arrangement, that is, if we first create a four-deck ship, then three.... then everything will work perfectly, in other cases, the work is undefined.

The advantage of my development is the creation of boats, here I analyzed all possible options and this is probably the only reason why I left this project in the repository, more details about the creation of boats below.

	//All_options_for_creating_ship 
										// 
										//[ ] - single deck ship
										//[][] - double deck ship
										//[][][] - three deck ship
										//[][][][] - four deck ship
										//[X] - The place where we add the deck
					// The coordinates of the ship are always from the right if it is horizontal, and from above if it is vertical

					//Create 1 - deck ship
					// X
		
          //Create 2 - deck horizontally ship
          // []X

          // X[]

          //Create 2 - deck vertically ship
          // [ ]
          // [X]

          // [X]
          // [ ]





          //Create 3 - deck horizontally ship
          // [][]X

          // X[][]

          // []X[]



          //Create 3 - deck vertically ship
          // [X]
          // [ ]
          // [ ]

          // [ ]
          // [X]
          // [ ]

          // [ ]
          // [ ]
          // [X]



          //Create 4 - deck horizontally ship
          // [][][]X

          // X[][][]

          // []X[][]

          // [][]X[]

          //Creat 4 - deck vertically ship
          // [X]
          // [ ]
          // [ ]
          // [ ]

          // [ ]
          // [X]
          // [ ]
          // [ ]

          // [ ]
          // [ ]
          // [X]
          // [ ]

          // [ ]
          // [ ]
          // [ ]
          // [X]
# When will be the final result
Never...., you need to respect your time and not stand in one place.

if anyone wants to continue my creation good luck.

										
