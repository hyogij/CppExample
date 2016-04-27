# include <stdio.h>
#include <string.h>

/*
 ==========================================================
 Author : Hyogi Jung(hyogij@gmail.com)
 Date : 2016.04.25
 Problem : http://codereview.stackexchange.com/questions/17517/reversing-every-word-in-a-string
 ==========================================================
 */
void reverse(char* str);
void reverse_word(char* str, int left, int right);
char toLowercase(char c);
char toUppercase(char c);

int main() {
	char str1[] = "Hello There";
	char str2[] = "How are you?";
	char str3[] = "my nAMe is john.";
	char str4[] = "my nAMe is j'ohn.";

	reverse(str1);
	reverse(str2);
	reverse(str3);
	reverse(str4);
}

char *output;
void reverse(char* str) {
	printf("Input :%s\n", str);

	int len = strlen(str);
	int left = 0, right = 0;
	for (; right < len; right++) {
		// Break words with these characters
		if (str[right] == ' ' || str[right] == '.') {
			reverse_word(str, left, right - 1);
			left = right + 1;
		}
	}
	reverse_word(str, left, right - 1);

	output = str;
	printf("Output :%s\n", output);
}

void reverse_word(char *x, int begin, int end) {
	int first = begin;
	while (begin < end) {
		char c = toLowercase(*(x + begin));
		*(x + begin) = toLowercase(*(x + end));
		*(x + end) = c;
		++begin, --end;
	}
	x[first] = toUppercase(x[first]);
}

// Ascii values : 65 A, 90 Z, 97 a, 122 z
char toLowercase(char c) {
	if (c >= 65 && c <= 90)
		return c + 32;
	return c;
}

char toUppercase(char c) {
	if (c >= 97 && c <= 122)
		return c - 32;
	return c;
}
