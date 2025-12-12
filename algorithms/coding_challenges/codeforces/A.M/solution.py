# Busy Beaver is throwing an MITIT party!

# Busy Beaver is planning to print a large banner. His printer is old-school: it draws on an N×N pixel board,
# where N is odd, using # for ink and . for blank space. For the first letter of the banner, he needs the letter M,
# printed as shown below.

# Your job is to tell the printer exactly which pixels to ink.

# Formally, the M is defined as follows. The left and right edges of the banner are the M's vertical legs,
# running all the way from top to bottom. From the top corners, two strokes with slope 1 and −1 descend inward,
# one from each side, meeting exactly in the middle row. Because n is odd, there is a single center column and a
# single middle row where the slanted strokes touch. Below that meeting point, only the two outer legs
# continue to the bottom.

# Input
# The first line contains a single integer T (1≤T≤50) — the number of test cases.
# 
# The only line of each test case contains a single odd integer N (5≤N<50, N is odd) — the side length of
# Busy Beaver's board.

# Output
# For each test case, output N lines, each containing N characters # and . without spaces — the letter M,
# as described in the statement.
# 
# Do not output empty lines between test cases.

for _ in range(int(input())):
    print(f"M square matrix of size {int(input())}")