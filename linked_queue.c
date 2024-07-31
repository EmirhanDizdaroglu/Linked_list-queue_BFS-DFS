#include <stdio.h>
#include <stdlib.h>
#include "linked_queue.h"

// Kuyruğu başlatır
LINKED_QUEUE linked_queue_create() {
    LINKED_QUEUE queue = (LINKED_QUEUE)malloc(sizeof(LINKED_QUEUE_t));
    if (queue == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

// Kuyruktan veri çıkarır
void *linked_queue_dequeue(LINKED_QUEUE queue) {
    if (linked_queue_is_empty(queue)) {
        printf("Queue is empty!\n");
        return NULL;
    }

    LINKED_QUEUE_NODE node = queue->head;
    void *data = node->data;
    queue->head = node->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(node);
    return data;
}

// Kuyruğa veri ekler
void linked_queue_enqueue(LINKED_QUEUE queue, void *data) {
    LINKED_QUEUE_NODE new_node = (LINKED_QUEUE_NODE)malloc(sizeof(LINKED_QUEUE_NODE_t));
    if (new_node == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;

    if (queue->tail == NULL) {
        queue->head = queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

// Kuyruğun tüm elemanlarını yazdırır
void linked_queue_print(LINKED_QUEUE queue) {
    LINKED_QUEUE_NODE current = queue->head;
    while (current != NULL) {
        printf("%d ", *(int*)current->data);
        current = current->next;
    }
    printf("\n");
}

// Kuyruğu serbest bırakır
void linked_queue_destroy(LINKED_QUEUE queue) {
    while (!linked_queue_is_empty(queue)) {
        free(linked_queue_dequeue(queue));
    }
    free(queue);
}

// Kuyruğun boş olup olmadığını kontrol eder
int linked_queue_is_empty(LINKED_QUEUE queue) {
    return queue->head == NULL;
}

// Kuyruğun boyutunu hesaplar
int linked_queue_size(LINKED_QUEUE queue) {
    int size = 0;
    LINKED_QUEUE_NODE current = queue->head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}
