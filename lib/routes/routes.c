#include "routes.h"

int32_t get_routes_index(Routes *routes, char key[]) {
    for (size_t i = 0; i < routes->size; i++) {
        if (strcmp(routes->keys[i], key) == 0) {
            return i;
        }
    }

    return -1;
}

void insert_route(Routes *routes, char key[], char value[]) {
    int index = get_routes_index(routes, key);

    if (index == -1) {
        strcpy(routes->keys[routes->size], key);
        routes->values[routes->size] = value;
        routes->size++;
    } else {
        routes->values[index] = value;
    }
}

char *get_route(Routes *routes, char key[]) {
    int32_t index = get_routes_index(routes, key);

    if (index == -1) {
        return NULL;
    } else {
        return routes->values[index];
    }
}
