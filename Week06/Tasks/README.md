# Linked List

Задачата ви е да имплементирате свързан списък (Linked List). Нека класа ви има следния интерфейс:
```
template <typename T>
struct Node {
    T value;
    Node<T>* next;
};

template <typename T>
class LinkedList {
private:
    private Node<T> front;

    void copy(const LinkedList& other);
    void destroy();
public:
    LinkedList();
    LinkedList(const List& other);
    LinkedList& operator=(const LinkedList& other);
    ~LinkedList();

    bool isEmpty() const;
    bool insertBefore(const T& value, int index);
    bool insertAfter(const T& value, int index);

    bool deleteBefore(int index);
    bool deleteAt(int index);
    bool deleteAfter(int index);

    const T& elementAt(int index) const;
};

```

Добавянето на допълнителни помощни функции при нужда е позволено.