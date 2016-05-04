# include <stdio.h>
# include <stdbool.h>

/*
 ==========================================================
 Author : Hyogi Jung(hyogij@gmail.com)
 Date : 2016.04.25
 Problem : http://waytocrack.com/blog/how-to-check-if-a-number-is-bleak-or-supported-number/
 ==========================================================
 */

int setbits(int n);
bool isBleakNumber(int n);
void bleakNumbers(int input1[]);

char* output1[100];

int main() {	
	int input1[100];
	for(int i = 1; i <= 100; i++) {
		input1[i] = i;
	}
	bleakNumbers(input1);
	for(int i = 0; i < 100; i++) {
		printf("%s\n", output1[i]);
	}
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

bool isBleakNumber(int n) {
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
			return false;
		}
	}
	printf("Bleak Number! %d\n", n);
	return true;
}

// Assume following return types while writing the code for this question.
void bleakNumbers(int input1[]) {
	int size = 100;
	for(int i = 0; i < size; i++) {
		if(isBleakNumber(input1[i]) == true) {
			output1[i] = "Supported Number!";
		} else {
			output1[i] = "Bleak Number!";
		}
	}
}
