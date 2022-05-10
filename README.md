# Jurassic

The objective of this assignment is to write a "C" program which estimates the
probability that an explorer will safely escape from a dinosaur- and volcano-infested
island ("Jurassic Island") by taking random walks across it. As well as calculating the
probability of escape, the mean and standard deviation of the path lengths should be
determined for each starting cell. \n
2 Jurassic Island Map
The island map is stored as a 9*9 array:
 B W W B B W B W W
 B L L V L L L L B
 W L L L L D L L B
 B L L D L L L L W
 B L D L L L L L W
 W L L L L L V L B
 W V L L L L L L W
 W L L L D L L L W
 B B W B W B B W B
where each 'cell' is labelled as follows:
 L: Land, the explorer can safely step on this cell.
 B: Bridge, the explorer can safely step on this cell and use it to get off the
island.
 W: Water, the explorer will die if this cell is stepped on.
 D: Dinosaur, the explorer will die if this cell is stepped on.
 V: Volcano, the explorer will die if this cell is stepped on.
The island should be represented in your program as a 2-D array. The only way to
escape from the island is for the explorer to step onto a Bridge (B) cell (this includes
the case when B is a starting cell). Stepping onto a Land (L) cell is safe, however if
the explorer steps on a Dinosaur (D), Volcano (V) or Water (W) cell, the walk is
terminated and the next random walk should be attempted.
Each cell in the map is to be used as a starting point for walks, beginning, for
example, with the B cell at the top-left corner (i.e. [0][0] in the 2-D array).
2
3 Random Exploration
For each valid starting cell (i.e. a cell marked B or L on the map), the program
should perform 1,000 random walks where the explorer attempts to get off the island.
Each step on a walk is randomly chosen from one of eight directions, i.e. North,
Northeast, East, Southeast, South, Southwest, West, or Northwest, with equal
probability:
For each cell, the program should check to see if the walk:
 is successful by stepping off the island from a Bridge cell;
 has failed by stepping onto a Dinosaur, Volcano or Water cell;
 continues by stepping onto a Land or Bridge cell.
For example, assuming that the explorer is on the top-left corner cell (B), if the next
step is to the NE, N, NW, W, or SW then they will have stepped off the island
successfully; if the next step is to the S or SE the walk continues (lands on a B or a L
cell); however, if the next step is to E then the explorer lands on a W cell and the
walk terminates unsuccessfully:
To perform the random movement you must use the rand() function (explained
in the Appendix). You should map each move to an integer value as follows: 0
represents N, 1 represents NE, 2 represents E, etc.
3
4 Results and Example Output
For every valid starting cell your program should compute to two decimal places
 the probability of successfully escaping from the island;
 the mean path length (i.e. number of steps) of successful walks;
 the standard deviation of path lengths of successful walks.
(Invalid starting cells have 0.00 for the above items)
The values should be displayed on the screen when the program terminates. Use of
gcc is expected, using either the C89 or C99 "C" standard. An example output is
shown below:
