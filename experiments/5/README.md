Tennis tournament
=================

There are many variation of tennis tournament problem however, we are covering that comes close to min-max problem, where we have to simulate the tournament with elimination rounds and award the players by their wins and losses at each level. 

Algorithm
---------

Using the general divide and conquer strategy do the following:

1.  Recursively divide the players list to sublists uptill we have one player in the sub-list.

2.  When the two recursive methods return the player, then simulate a random winner between the two and return to the higher calling function.

3.  Do that till we reach the top level with a single winner.

**NOTE**: *While we are calculating the winner, update player's matches list and calculate the price money based on win or loss*

###Pseudo Code

```
 function simulate(players, first, last, matches, price_money)
     if length(players) ≤ 1
         return players[0]  // an array of zero or one elements is already sorted
     mid = first + (last - first) / 2
     player1 = simulate(players, first, mid, matches, price_money)
     player2 = simulate(players, mid + 1, last, matches, price_money)
     winner = Random(player1, player2)
     loser = player1 if winner is player1 else player2
     matches[player1] += 1
     matches[player2] += 1
     price_money[winner] += 2 * 100 * matches[winner]     
     price_money[loser] += 1 * 100 * matches[loser]
```

###Analysis

It invloves 2 recursive calls on lists of size n/2, so the recurrence relation is
T(n) = O(1) + 2T(n/2).

And as per the master theorem, it takes O(n log n) time to complete.
