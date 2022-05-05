# ComS_327_Terrain_Generation

COM S 327, Spring 2022
Programming Project 1.01
Terrain Generation
It’s time to start developing our Pokemon-inspired game. We’ll begin by generating terrain. Some ´
details are specified below, but generating a good-looking map is largely a matter of taste. I’ll share some
examples later this week (once I’ve had a chance to implement it!)
Because it’s so much a matter of taste, you may decide how you want your map to look and come up
with your own heuristics to generate that look. Things to keep in mind are playability and realism. Yeah,
it’s a fantasy game where we catch monsters in tall grass, but that doesn’t mean there’s no realism! Paths
that are too straight are probably unrealistic; after all, the world is full of rocks, streams, hills and trees.
Your terrain generator should be written with an eye toward extensibility. Remember that you will be
adding functionality on top of this next week, and for the rest of the semester. For this step, you generate a
map, draw it on the standard output, and exit. Here are the requirements:
• All code is in C.
• The map measures 80 units in the x (horizontal) direction and 21 units in the y (vertical) direction. A
standard terminal is 80 × 24, and limiting the map to 21 rows leaves three rows for text, things like
gameplay messages and player status, which come later.
• At least two paths pass through your map, one oriented N-S, the other E-w; these will intersect somewhere in your map. Additional paths are acceptable according to your taste. Paths are represented
using hashes (’#’).
• Your map should have a Pokemon Center and a Pok ´ e Mart, Represented by one or more ’C’ and ’M’, ´
respectively. I plan to make Pokemon Centers and a Pok ´ e Marts ´ 2 × 2.
1
• Your Pokemon Center and a Pok ´ e Mart, should be reachable from the path without having to go ´
through tall grass.
• Your map should contain at least two regions of tall grass (represented with commas)
• The outermost cells of the map are immovable boulders (represented using percent signs), except that
there is one exit on each border. Your N-S path goes between the top and bottom exit, while the E-W
path goes between the left and right exits.2
• Your map should contain at least two clearings. Clearings are represented using periods.
• Other option terrain includes rocks and boulders (’%’) and trees (’ˆ’).
My intended approach involves randomly choosing a handful of “seed” locations for the various region
types, then “growing” those seeds until the regions contact each other. Once the whole map has been filled,
I’ll favor region borders for path placement. To make the space more interesting, in addition to the required
regions given above, I plan to have hybrid regions, essentially clearings with rocks, trees, and tall grass in it.
1
If you’re unfamiliar with Pokemon games, the Pok ´ emon Center is a medical facility where you take your Pok ´ emon for healing ´
and the Poke Mart is a Pok ´ emon convenience store. We’ll implement the functionality of these facilities in a later assignment. ´
2
In a future assignment, we will add the ability to move out of the first map into an adjoining map through any of the exits. In
the new map, you enter through the old map’s exit; thus the position of this exit must me maintained in order to go back where you
came from. For this reason, it’s probably best to generate exits before generating paths!
