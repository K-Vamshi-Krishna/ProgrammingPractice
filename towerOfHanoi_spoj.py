# given 3 pegs, leftmost A, center B,righmost C
# Transfer the first n-1 discs to peg C
# Transfer the disc n to Peg B
# Transfer the n-1 discs from Peg C to Peg A
# Transfer the disc n to peg C
# tranfer the n-1 discs to peg C again as we did in the first stemp
# Mn = 3 * Mn+1 + 2

def tower_of_hanoi_revisited(num):
	val = 0
	while num > 0:
		val = 3 * val + 2
		num -= 1
	print val

if __name__ == '__main__':
	for _ in xrange(int(raw_input())):
		tower_of_hanoi_revisited(int(raw_input()))
