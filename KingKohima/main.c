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
void kingKohimaDp(int N);
int recur(char c, int num, int N);

int main() {
	kingKohima(3);
	kingKohima(4);
	kingKohima(5);

	kingKohimaDp(3);
	kingKohimaDp(4);
	kingKohimaDp(5);
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

void kingKohimaDp(int N) {
	int * countX = (int*) malloc(sizeof(int) * (N + 1));
	int * countY = (int*) malloc(sizeof(int) * (N + 1));

	countX[0] = 0;
	countY[0] = 0;
	countX[1] = 1;
	countY[1] = 1;
	countX[2] = 1;
	countY[2] = 2;

	for (int i = 3; i <= N; i++) {
		countX[i] = countY[i - 1];
		countY[i] = countX[i - 1] + countY[i - 1];
	}

	int total = (countX[N] + countY[N]) * (countX[N] + countY[N]);
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
