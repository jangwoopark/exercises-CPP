Mancala is a family of board games played around the world, which are also called "count-and-capture" games. In this challenge you will code a bot to play Mancala against other bots in the hackathon.

An illustration of the mancala board is given below.

img1.jpg

Game Rules

The goal is to collect more marbles (in your mancala) than your opponent does.

The Mancala 'board' is made up of 2 rows of 6 holes each.
4 marbles are placed in each of the 12 holes. The color of the marble is irrelevant.
Each player has an empty 'mancala' to the right side of the Mancala board.
The game begins with one player picking up all of the marbles in any one of the non-empty holes on his side.
Moving counter-clockwise, the player deposits one of the marbles in each hole he runs into until the marbles run out.
If you run into your own mancala, deposit one marble in it. If you run into your opponent's mancala, skip it.
If the last marble you drop is in your own mancala, you get a free turn. If the last marble you drop is in an empty hole on your side, you empty all marbles on the hole directly opposite to your hole and put it in your hole.
The game ends when all the 6 holes on one side of the Mancala board are empty.
The Player who still has marbles on his side of the board when the game ends captures all of those marbles and places it in his mancala.
Count all the marbles in each mancala. The winner is the Player with the most marbles.
picture alt

As shown in illustration 2, Player B has moved the one marble from his hole B2 into the empty hole B3. He will now take that marble and the marbles in A4 and place all those marbles in B3. His turn will then end and the next player goes.

Input Format

The 1st line contains the Player id 1 or 2 indicating Player A and Player B respectively.
The 2nd line contains the Mancala count for Player1.
The 3rd line contains 6 single spaced integers each indicating the number of marbles in the 1st Player's hole from left to right with respect to player1.
The 4th line contains the Mancala count for player2.
The 5th line contains 6 single spaced integers each indicating the number of marbles in the 2nd player's hole from left to right with respect to Player2.

Output Format

Each turn, output the number (1-6) of the hole you wish to empty.

Sample Input/Output:

Input for Player1:

1
0
4 4 4 4 4 4
0
4 4 4 4 4 4
Player1 output:

5
Input for Player2:

2
1
4 4 4 4 0 5
0
5 5 4 4 4 4
Explanation:

Player1 emptied the 5th hole, which put marbles on his side and mancala and Player2's side. Player2 then receives the current game state and makes a move:

Player2 output:

6
This would then be the input for Player1's next move:

1
1
5 5 5 4 0 5
1
5 5 4 4 4 0
Task

Complete the function printNextMove which takes in 5 parameters as input

An integer player_id 1 or 2: player
An integer mancala of Player1: player1Mancala
A vector array of integers of marbles in holes of Player1: player1Marbles
An integer mancala of Player2: player2Mancala
A vector array of integers of marbles in holes of Player2: player2Marbles
and prints an integer of the hole you wish to empty.

Scoring

This is a competitive 2 player game. Please refer scoring on how bots are scored and how opponents are picked.
