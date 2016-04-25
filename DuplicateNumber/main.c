# include <stdio.h>
#include <string.h>

/*
 ==========================================================
 Author : Hyogi Jung(hyogij@gmail.com)
 Date : 2016.04.25
 Problem : http://cboard.cprogramming.com/c-programming/46897-check-repeated-digits.html
 ==========================================================
 */
void check_digits(int n);

int main() {
	check_digits(112);
	check_digits(314);
	check_digits(3114);
}

void check_digits(int n) {
	int digit_seen[10] = { 0 };
	int digit;

	while (n > 0) {
		digit = n % 10;
		digit_seen[digit]++;
		n /= 10;
	}

	for (int i = 0; i < 10; i++) {
		if (digit_seen[i] > 1) {
			printf("duplicated\n");
			return;
		}
	}

	printf("not duplicated\n");
}
