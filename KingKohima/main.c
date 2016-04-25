# include <stdio.h>
#include <string.h>

/*
 ==========================================================
 Author : Hyogi Jung(hyogij@gmail.com)
 Date : 2016.04.25
 Problem : http://stackoverflow.com/questions/19343509/number-of-possible-ways-of-assigning-free-plots-to-buildings-with-the-restrictio
 ==========================================================
 */
void kingKohima(int N);
int recur(char c, int num, int N);

int main() {
	kingKohima(3);
	kingKohima(4);
}

void kingKohima(int N) {
	//x is number of combinations when the first slot is used to build a house
	int x = recur('X', 1, N);

	//y is number of combinations when the first slot is left empty
	int y = recur('Y', 1, N);

	//Since same number exists on other side also
	int total = (x + y) * (x + y);

	printf("kingKohima : %d, %d\n", N, total);
}

int recur(char c, int num, int N) {
	if (num == N) {
		return 1;
	}

	if (num < N) {
		if (c == 'X') {
			return recur('Y', num + 1, N);
		} else {
			return recur('X', num + 1, N) + recur('Y', num + 1, N);
		}
	}
	return 1;
}
