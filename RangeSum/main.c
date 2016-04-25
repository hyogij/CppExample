# include <stdio.h>
#include <string.h>

/*
 ==========================================================
 Author : Hyogi Jung(hyogij@gmail.com)
 Date : 2016.04.25
 Problem : Find out the sum of all digit from M to N (both inclusive)
 ==========================================================
 */
void range_sum(int a, int b);

int main() {
	range_sum(1, 10);
	range_sum(10, 15);
}

void range_sum(int a, int b) {
	int sum = 0;
	for (int i = a; i <= b; i++) {
		int n = i;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
	}
	printf("total : %d\n", sum);
}
