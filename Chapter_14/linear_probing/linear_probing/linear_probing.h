#ifndef LINEAR_PROBING_H
#define LINEAR_PROBING_H

#define KEY_SIZE 10
#define TABLE_SIZE 13

typedef struct
{
	int is_used;
	char key[KEY_SIZE];
}element;

element hash_table[TABLE_SIZE];

void init_table(element ht[]);
int transform(char* key);
int hash_function(char* key);
void hash_lp_add(element item, element ht[]);
int hash_lp_search(element item, element ht[]);
void hash_lp_print(element ht[]);
int is_equal(char* s1, char* s2);
int is_empty(element bucket);
int is_used(element bucket);
void hash_lp_delete(element item, element ht[]);

#endif // !LINEAR_PROBING_H

