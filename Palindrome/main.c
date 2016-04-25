# include <stdio.h>
#include <string.h>

/*
 ==========================================================
 Author : Hyogi Jung(hyogij@gmail.com)
 Date : 2016.04.25
 Problem : http://www.programmingsimplified.com/c-program-find-palindrome
 ==========================================================
 */
void is_palindrome_num(int num);
void is_palindrome_char(char *input);

int main() {
	is_palindrome_num(101);
	is_palindrome_num(123);
	is_palindrome_num(12321);
	is_palindrome_num(123321);

	is_palindrome_char("Hello");
	is_palindrome_char("banana");
	is_palindrome_char("bananab");
}

void is_palindrome_num(int num) {
	int temp = num;
	int reverse = 0;
	while (temp != 0) {
		reverse = reverse * 10;
		reverse = reverse + temp % 10;
		temp = temp / 10;
	}

	if (num == reverse)
		printf("%d is a palindrome number.\n", num);
	else
		printf("%d is not a palindrome number.\n", num);
}

void is_palindrome_char(char *text) {
	int begin, middle, end = 0;
	int length = strlen(text);

	end = length - 1;
	middle = length / 2;

	for (begin = 0; begin < middle; begin++) {
		if (text[begin] != text[end]) {
			printf("Not a palindrome.\n");
			break;
		}
		end--;
	}

	if (begin == middle)
		printf("Palindrome %s.\n", text);
}
