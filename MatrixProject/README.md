
Video for game : 
	- download from github
	- see here : https://youtu.be/UiuMEOOBR2g


Strange Pacman game : 

 	1. ) Representation of matrixes leds :
		- pacman - represented by a blinking point (led )
		- walls - permanent red leds
		- fruits - red points which dissapear fast
	2.) Logic :
		- you, strange pacman, should eat the fruits to gain +20 score
		- if you don't eat fruits your score increment with 2 in 31 seconds
		- the game have 10 levels and the scope is to win 
		- you lose if you hit walls and do not move in at least 0.5 seconds
		- because the walls and the speed are the only difficulties, i encrease
		the fruits speed
		- the level will change if you make a score % 95
		- your speed encrease from level to level
		- you can move only on the right. left. up. and down.
		- you can see in the time you play lives and score, and after you level
		up, in level up  animation you can see your level
	3.) Menu : 
		- menu have the next submenu :
			- start game -> to start playing
			- highscores -> to see first 3 highscores
			- settings -> to modify difficulty :	
				- hard -> very fast without delay
				- medium -> 200 initial move delay, 20 delay untill 
				speed value as hard, after 0 delay
				- easy -> 200 initial move delay, 10 delay untill 
				speed values as hard, after 0 delay
			- credits -> persons who contributes to this game 
				* shell in progress *
	4. ) Options (what i would like to add ):
		- music
		- bombs : will explode after 25 + bomb_index seconds after spawn and will
			destroy the "leds" near by, if pacman is there, you will lose
			a life or lose
		- easter eggs with :
			- ciphers
			- codes for bigger score in game
			- funny animations
			
			
			
- LCD animations : : 			

			
 - Heart animationc : 
 ![heart](https://user-images.githubusercontent.com/36522518/71325427-3dc30580-24f5-11ea-8ac9-deba078355c4.png)


- Phantom animation :
![phantom](https://user-images.githubusercontent.com/36522518/71325442-92668080-24f5-11ea-8a71-14f5c132326f.png)



- how to play : 
	 - you should use the joystick to navigate in menu and switch button from joystick
	 to select a submenu
	 - in start game -> joystick to move 
	 - in credits and highscore - when0 selected will last enough time to read
	 - in settings -> right or up to change difficulty , left or down more thant 4 seconds to come back to menu



- harware component : 
	- Used : 
		- 2 led matrixes
		- 2 drivers
		- 1 lcd
		- 3 resistors
		- a lot of cables
		- 1 joystick
		- 4 breadboards
	 - Upgrade (maybe ) :
		- loudspeaker
		- more cables
		- 1 resistor
		- leds
		- buttons
		

 - hardware scheme : 
 	![hardwareModel](https://user-images.githubusercontent.com/36522518/71325459-eec9a000-24f5-11ea-9e81-cc8e9afef552.jpg)

 	

	
