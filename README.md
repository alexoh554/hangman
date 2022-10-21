# Hangman
C++ classic "hangman" game run in console.

## Description
Hangman is a word guessing game where the user is prompted to guess a letter or word. Each wrong guess adds an element to the hangman drawing. Too many wrong guesses and the game ends. The user wins the game by typing out the correct word. 

There are three difficulties in the game and three corresponding word banks for each difficulty. Words may be added to the word bank by simply adding a new line followed by the word in "*difficulty".txt".

### Screenshots
![Screenshot](/static/intro.png?raw=true)
![Screenshot](/static/incorrect_guess.png?raw=true)
![Screenshot](/static/correct_guess.png?raw=true)
![Screenshot](/static/game_won.png?raw=true)
![Screenshot](/static/game_lost.png?raw=true)


## Getting started
### Installation
* In the command line run:
```
https://github.com/alexoh554/hangman.git
```

* Compile:
```
g++ -std=c++11 main.cpp play.cpp menu.cpp class.cpp -o main
```

* Run:
```
./main
```

## License
* [License](LICENSE.md)

