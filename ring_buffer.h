#pragma once
#include <cstddef>

template <typename T>
class RingBuffer {
public:
    // Hàm tạo
    RingBuffer(int size)
        : capacity(size), head(0), tail(0), count(0) {
        buffer = new T[size];   
    }

    // Hàm hủy
    ~RingBuffer() {
        delete[] buffer;
    }

    // Xoá RingBuffer 
    void Clear() {
        head = 0;
        tail = 0;
        count = 0;
    }

    // Put item vào buffer
    int PutItemToRingBuffer(T item) {
        if (count == capacity) {
            return -1; 
        }
        buffer[tail] = item;
        tail = (tail + 1) % capacity;
        count++;
        return 0;
    }

    // Get item ra khỏi buffer
    int GetItemFromRingBuffer(T* item) {
        if (count == 0) {
            return -1; // trống
        }
        *item = buffer[head];
        head = (head + 1) % capacity;
        count--;
        return 0;
    }
    T* buffer;       
    int capacity;   
    int head;        
    int tail;        
    int count;       
};
