#include <iostream>
#include "ring_buffer.h"

int main() {
    RingBuffer<int> rb(3);

    std::cout << "Put 10 -> " << rb.PutItemToRingBuffer(10) << std::endl;
    std::cout << "Put 20 -> " << rb.PutItemToRingBuffer(20) << std::endl;
    std::cout << "Put 30 -> " << rb.PutItemToRingBuffer(30) << std::endl;
    std::cout << "Put 40 -> " << rb.PutItemToRingBuffer(40) << " (fail expected)" << std::endl;

    int val;
    while (rb.GetItemFromRingBuffer(&val) == 0) {
        std::cout << "Get: " << val << std::endl;
    }

    return 0;
}
