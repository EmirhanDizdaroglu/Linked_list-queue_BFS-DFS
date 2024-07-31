# Linked Queue and Stack Project

Bu proje, bağlı liste (linked list) kullanarak bir kuyruk (queue) ve bir yığın (stack) veri yapılarının temel implementasyonlarını sağlar. Ayrıca, genişlik öncelikli gezinti (BFS) ve derinlik öncelikli gezinti (DFS) algoritmalarının örneklerini içermektedir.

## Projeye Genel Bakış

Bu proje iki temel veri yapısını içerir:

1. **Linked Queue (Bağlı Liste Kuyruğu)**: FIFO (First In, First Out) prensibine göre çalışan bir veri yapısıdır.
2. **Linked Stack (Bağlı Liste Yığını)**: LIFO (Last In, First Out) prensibine göre çalışan bir veri yapısıdır.

Proje ayrıca şu işlevleri içerir:

- Genişlik öncelikli gezinti (BFS) algoritması
- Derinlik öncelikli gezinti (DFS) algoritması

## Kurulum ve Gereksinimler

Bu proje, C programlama dili kullanılarak geliştirilmiştir ve CMake ile yapılandırılmıştır. Derleyici olarak GCC veya MinGW kullanılabilir.

### Gereksinimler

- C derleyicisi (GCC, MinGW vb.)
- CMake (3.10 veya daha yeni bir sürüm)

### Kurulum

Projeyi yerel makinenize klonlayın:

```bash
git clone https://github.com/kullanici-adiniz/linked-queue-stack.git
cd linked-queue-stack

### Dosya yapısı

CMakeLists.txt: CMake yapılandırma dosyası.
main.c: BFS ve DFS algoritmalarını içeren ana program dosyası.
linked_queue.c: Bağlı liste kuyruk implementasyonu.
linked_queue.h: Kuyruk veri yapısının başlık dosyası.
linked_stack.c: Bağlı liste yığını implementasyonu.
linked_stack.h: Yığın veri yapısının başlık dosyası.

### Örnek output
Breadth-First Traversal starting from vertex 0:
0 1 4 7 3 2 5 8
Depth-First Traversal starting from vertex 0:
0 1 3 8 5 2 4 7

Process finished with exit code 0
