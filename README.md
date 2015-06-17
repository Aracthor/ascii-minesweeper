# PLEASE DO NOT JUDGE ME ON THE CODE !

I did this deminor a long time ago, I was very unexperimented, and I didn't do most of basic stability checks (malloc's return for instance) because i just wanted to do it fast.

I coded this without IDE, with only a VI (not VIM, VI) without any configuration file. I had to did myself even indentation.

So please, if you are looking for clear and clean code, go to look at another repository.

Else, please compile and run my deminor:

    gcc *.c -o deminor
    ./deminor [width=X] [height=X] [mines=X]

 - `width` will set col numbers.
 - `height` will set row numbers.
 - `mines` will set mines number, so directly difficulty. It have to be less than your tiles number, of course.

Note that mines will be generated on your first tile selection, so you cannot lose on first click.

