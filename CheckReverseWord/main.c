# include <stdio.h>
#include <string.h>

/*
 ==========================================================
 Author : Hyogi Jung(hyogij@gmail.com)
 Date : 2016.04.25
 Problem : http://codereview.stackexchange.com/questions/17517/reversing-every-word-in-a-string
 ==========================================================
 */
#define ROWS 3
#define COLS 10

void check_duplicate(char words[][COLS], int num);
void reverse_word(char *x, int begin, int end);
void find_word(char words[][COLS], int num, char *word);

int main() {
	char words[ROWS][COLS] = { "hello", "aaa", "hi" };
	check_duplicate(words, ROWS);
}

void check_duplicate(char words[][COLS], int num) {
	char word[10];
	for (int i = 0; i < num; i++) {
		strcpy(word, words[i]);
		reverse_word(word, 0, strlen(word) - 1);
		find_word(words, num, word);
	}
}

void reverse_word(char *x, int begin, int end) {
	while (begin < end) {
		char c = *(x + begin);
		*(x + begin) = *(x + end);
		*(x + end) = c;
		++begin, --end;
	}
}

void find_word(char words[][COLS], int num, char *word) {
	for (int i = 0; i < num; i++) {
		if (strcmp(words[i], word) == 0) {
			printf("duplicated : %s\n", word);
			return;
		}
	}
	printf("not duplicated : %s\n", word);
}
