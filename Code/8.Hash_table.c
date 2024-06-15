#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Hash table entry structure
typedef struct Entry {
    char* key;
    int value;
    struct Entry* next;
} Entry;

// Hash table structure
typedef struct HashTable {
    Entry* buckets[TABLE_SIZE];
} HashTable;

// Hash function
int hashFunction(char* key) {
    int hash = 0;
    for (int i = 0; key[i]; i++) {
        hash = (hash * 31 + key[i]) % TABLE_SIZE;
    }
    return hash;
}

// Insert a key-value pair into the hash table
void insert(HashTable* table, char* key, int value) {
    int index = hashFunction(key);
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->key = strdup(key);
    newEntry->value = value;
    newEntry->next = table->buckets[index];
    table->buckets[index] = newEntry;
}

// Retrieve the value associated with a key
int get(HashTable* table, char* key) {
    int index = hashFunction(key);
    Entry* current = table->buckets[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Key not found
}

// Remove a key-value pair from the hash table
void remove_(HashTable* table, char* key) {
    int index = hashFunction(key);
    Entry* current = table->buckets[index];
    Entry* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                table->buckets[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->key);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    HashTable table;

    insert(&table, "apple", 10);
    insert(&table, "banana", 20);
    insert(&table, "cherry", 30);

    printf("Value of 'apple': %d\n", get(&table, "apple"));
    printf("Value of 'banana': %d\n", get(&table, "banana"));
    printf("Value of 'cherry': %d\n", get(&table, "cherry"));

    remove_(&table, "banana");

    printf("Value of 'banana' after removal: %d\n", get(&table, "banana"));

    return 0;
}