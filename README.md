## PLEASE DO NOT JUDGE ME ON THE CODE !

I did this deminor a long time ago, I was very unexperimented, and I didn't do most of basic stability checks (malloc's return for instance) because i just wanted to do it fast.

I coded this without IDE, with only a VI (not VIM, VI) without any configuration file. I had to did myself even indentation.

So please, if you are looking for clear and clean code, go to look at another repository.

Else, you can compile and run my deminor.


### Compilation & Installation

To locally compile the program, and allow you to test it, you just have to make it:

    make

If you have strange tastes and get addicted to it, you can install it on your machine to start another game whenever and wherever you want:

    make install

It will only take 20 ko of memory on your computer. So do it without remorse.


### Synopsis

    ./deminor [width=X] [height=X] [mines=X]

 - `width` will set col numbers.
 - `height` will set row numbers.
 - `mines` will set mines number, so directly difficulty. It have to be less than your tiles number, of course.

Note that mines will be generated on your first tile selection, so you cannot lose on first click.


### Commands

Use [Z] on a tile when you are sure there is no mine on a tile.  
If you were wrong, that's bad for you. Else, the tile will reveal, and if there are no close mine, every bounded tile will reveal too.

Use [X] on a tile when you think there is a mine. It will write a '!' on it, and forbid you to reveal it by accident with [Z].  
Use [X] again on a mine-marked tile to unselect it and reset it as unknow tile.


### Win

Note that this is not a finished game: if you reveal the entire board, nothing will happen.
At least you can have a personal satisfaction, or take a screenshot of your terminal to boast besides your friends.
