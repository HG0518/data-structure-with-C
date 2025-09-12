#ifndef DICTIONARY_H
#define DICTIONARY_H

#define MAX_WORD_SIZE 50
#define MAX_MEANINT_SIZE 500
#define SIZE 5

typedef struct {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANINT_SIZE];
}Word;

typedef struct {
	Word list[SIZE];
}Dictionary;

void dictionary();
void insert_dic(Dictionary* dic);
void print_dic(Dictionary* dic);

#endif // !DICTIONARY_H
