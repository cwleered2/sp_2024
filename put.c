#include "kvs.h"

int put(kvs_t* kvs, const char* key, const char* value) {
    
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (!new_node) {
        //printf("Failed to allocate memory for new node\n");
        return -1;
    }

    strcpy(new_node->key, key);
    new_node->value = strdup(value);
    if (!new_node->value) {
        //printf("Failed to allocate memory for value\n");
        free(new_node);
        return -1;
    }

    new_node->next = kvs->db;
    kvs->db = new_node;
    kvs->items++;
    //printf("Added key-value pair: %s -> %s\n", key, value);
    return 0;
}
