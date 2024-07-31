#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

typedef struct linked_queue_node_t {
    void *data;
    struct linked_queue_node_t *next;
} LINKED_QUEUE_NODE_t, *LINKED_QUEUE_NODE;

typedef struct {
    LINKED_QUEUE_NODE head;
    LINKED_QUEUE_NODE tail;
} LINKED_QUEUE_t, *LINKED_QUEUE;

// Kuyruğu oluşturur
LINKED_QUEUE linked_queue_create();

// Kuyruğu serbest bırakır
void linked_queue_destroy(LINKED_QUEUE queue);

// Kuyruğa veri ekler
void linked_queue_enqueue(LINKED_QUEUE queue, void *data);

// Kuyruktan veri çıkarır
void *linked_queue_dequeue(LINKED_QUEUE queue);

// Kuyruğun boş olup olmadığını kontrol eder
int linked_queue_is_empty(LINKED_QUEUE queue);

// Kuyruğun boyutunu hesaplar
int linked_queue_size(LINKED_QUEUE queue);

// Kuyruğun tüm elemanlarını yazdırır
void linked_queue_print(LINKED_QUEUE queue);

#endif // LINKED_QUEUE_H
