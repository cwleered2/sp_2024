#include "kvs.h"


char* get(kvs_t* kvs, const char* key) {
    node_t* current = kvs->db;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
           return strdup(current -> value);
        }
        current = current->next; 
    } 
    return NULL; 
}

