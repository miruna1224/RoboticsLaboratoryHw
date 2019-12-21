
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
