#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct hash_entry {
    int key; 
    int value;
    struct hash_entry *next; //pointer to next  entry in linked list
};

//define a hash table
struct hash_table {
    struct hash_entry **entries; //array of pointers to hash table entries. 
}; 

//create a new hash table
struct hash_table *create_hash_table()
{
    struct hash_table *table = malloc(sizeof(struct hash_table));
    table->entries = calloc(TABLE_SIZE, sizeof(struct hash_entry*));
    return table;
}

void destroy_hash_table(struct hash_table *table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        //get the frist entry in the linked list at this index
        struct hash_entry *entry = table->entries[i];
        while (entry != NULL)
        {
            struct hash_entry *next = entry->next;
            free(entry);
            entry = next; 
        }
    }
    free(table->entries);
    free(table);
}

//hash a key to an index
int hash(int key)
{
    return key % TABLE_SIZE;
}

//inserts a key-value pair into hash table
void insert(struct hash_table *table, int key, int value)
{
    int index = hash(key);
    //get the first entry in the linked list at this index
    struct hash_entry *entry = table->entries[index];
    //check if entry exists in the hash table
    while(entry != NULL)
    {
        //if key exits, update value and return
        if(entry->key == key)
        {
            entry->value = value; 
            return;
        }
        //next entry in linked list
        entry = entry->next;
    }

    //if key does not exits, malloc for new entry
    entry = malloc(sizeof(struct hash_entry));
    //set the key value of entry
    entry->key = key;
    entry->value = value; 

    //set teh next pointer of entry to the current first entry in linked liust
    entry->next = table->entries[index];

    //set the first entry in linked list at this in
    table->entries[index] = entry;
}

int search(struct hash_table *table, int key)
{
    int index = hash(key);
    struct hash_entry *entry = table->entries[index];
    while (entry != NULL)
    {
        if(entry->key == key)
        {
            return entry->value;
        }
        entry = entry->next; 
    }
    //key not found
    return -1; 
}

int main()
{
    struct hash_table *table = create_hash_table();

    insert(table, 1, 10);
    insert(table, 2, 20);
    insert(table, 3, 30);

    printf("%d\n", search(table, 1));

    destroy_hash_table(table);
    return 0; 
}
