
=================================TriPeaks===============================

Mini projet algo & C

Jean-Baptiste F, Romain G, Pierre K

========================================================================

-Objective : Remove all the cards from the three pyramids.

-Rules : You can only take card with a value equal to one less or one more that the last card.

========================================================================

Description cards : 

Symbol : 

s : spades
h : hearts
d : diamonds
c : clubs

Number : 

a : ace
2
3
4
5
6
7
8
9
10
j : jack
q : queen 
k : king 

========================================================================

Here is an example :
[X.22] = reserve
|7..s| = Fondation


           |x..x|                  |x..x|                  |x..x|
        |x..x|  |x..x|          |x..x|  |x..x|          |x..x|  |x..x|
    |x..x|  |x..x|  |x..x|  |x..x|  |x..x|  |x..x|  |x..x|  |x..x|  |x..x|
|9..h|  |k..c|  |8..h|  |j..s|  |j..h|  |6..d|  |7..d|  |5..d|  |5..s|  |a..h|


[X.22]  [>][>]  |7..s|

0 : Draw card on the reserve
1 : Pick card on the board
x : Exit
>

========================================================================
