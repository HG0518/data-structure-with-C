#ifndef HASH_CHAINING_H
#define HASH_CHAINING_H

#define TABLE_SIZE 7

typedef struct
{
	int key;
}element;

typedef struct hash_list
{
	element item;
	struct hash_list* link;
}hash_list;

int hash_function(int key);
hash_list* create_node(element item);
void hash_chain_add(element item, hash_list* ht[]);
void hash_chain_search(element item, hash_list* ht[]);
void hash_chain_print(hash_list* ht[]);
void hash_list_init(hash_list* ht[]);


#endif HASH_CHAINING_H