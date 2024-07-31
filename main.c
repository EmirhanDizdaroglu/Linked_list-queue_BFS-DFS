#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_queue.h"
#include "linked_stack.h"

#define N 10

// Dinamik bellek tahsisi yapan ve verilen değeri atayan bir işlev
int *init_integer(int val) {
    int *ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    *ptr = val;
    return ptr;
}

// Genişlik öncelikli gezinti (BFS) işlevi
void bft(int graph[][N], int start_vertex) {
    LINKED_QUEUE queue = linked_queue_create(); // Kuyruğu oluştur
    int *vmap = (int *)calloc(N, sizeof(int)); // Ziyaret edilen düğümleri işaretlemek için

    if (vmap == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    linked_queue_enqueue(queue, init_integer(start_vertex));
    vmap[start_vertex] = 1;
    printf("%d ", start_vertex);
    fflush(stdout);

    while (!linked_queue_is_empty(queue)) {
        int *current_vertex = linked_queue_dequeue(queue);
        int v = *current_vertex;
        free(current_vertex);

        for (int i = 0; i < N; i++) {
            if (graph[v][i] != 0 && vmap[i] != 1) {
                linked_queue_enqueue(queue, init_integer(i));
                vmap[i] = 1;
                printf("%d ", i);
                fflush(stdout);
            }
        }
    }

    free(vmap);
    linked_queue_destroy(queue); // Kuyruğu serbest bırak
}

// Derinlik öncelikli gezinti (DFS) işlevi
void dft(int graph[][N], int start_vertex) {
    LINKED_STACK stack = linked_stack_create(); // Yığını oluştur
    int *dmap = (int *)calloc(N, sizeof(int)); // Ziyaret edilen düğümleri işaretlemek için

    if (dmap == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    linked_stack_push(stack, init_integer(start_vertex));
    dmap[start_vertex] = 1;

    while (!linked_stack_is_empty(stack)) {
        int *current_vertex = (int *)linked_stack_pop(stack);
        int v = *current_vertex;
        free(current_vertex);

        printf("%d ", v);
        fflush(stdout);

        for (int i = N - 1; i >= 0; i--) { // Komşuları geri sıraya koy
            if (graph[v][i] != 0 && dmap[i] != 1) {
                linked_stack_push(stack, init_integer(i));
                dmap[i] = 1;
            }
        }
    }

    free(dmap);
    linked_stack_destroy(stack); // Yığını serbest bırak
}

int main() {
    int adjMatrix[N][N] = {
            {0, 1, 0, 0, 1, 0, 0, 1, 0},
            {0, 0, 0, 1, 1, 0, 0, 0, 0},
            {1, 0, 1, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 1},
            {0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 1, 0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 1},
            {0, 1, 0, 1, 0, 1, 0, 1, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 0}
    };

    printf("Breadth-First Traversal starting from vertex 0:\n");
    bft(adjMatrix, 0);
    printf("\n");

    printf("Depth-First Traversal starting from vertex 0:\n");
    dft(adjMatrix, 0);
    printf("\n");

    return 0;
}
