# include <stdio.h>

/*
 ==========================================================
 Author : Hyogi Jung(hyogij@gmail.com)
 Date : 2016.04.25
 Problem : http://waytocrack.com/blog/how-to-check-if-a-number-is-bleak-or-supported-number/
 ==========================================================
 */

int setbits(int n);
void isBleakNumber(int n);

int main() {
	for (int i = 1; i < 20; i++)
		isBleakNumber(i);
}

// Find number of set bits in n
int setbits(int n) {
	int setbits = 0;
	for (int i = 0; i <= 31; i++) {
		if (n & (1 << i))
			setbits++;
	}
	return setbits;
}

void isBleakNumber(int n) {
	int msb = 0;
	// Find msb of n
	for (int i = 0; i < 32; i++) {
		if (n & (1 << i))
			msb = i;
	}
	++msb;

	for (int i = msb; i >= 0; i--) {
		// i is the number of set bits. If it satisfies above condition then you are done
		if (setbits(n - i) == i) {
			printf("Supported Number! %d and supported by : %d\n", n, n - i);
			return;
		}
	}
	printf("Bleak Number! %d\n", n);
}

// Assume following return types while writing the code for this question.
char* output1[100];
void bleakNumbers(int input1[]) {
	//Write code here
}
