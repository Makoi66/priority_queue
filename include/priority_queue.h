#include <iostream>
#include <vector>
#include <algorithm>

template <typename T1, typename T2>
class PriorityQueue {
private:
    using PairType = std::pair<T1, T2>;
    std::vector<PairType> heap;

    void emersion(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index].first > heap[parentIndex].first) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            }
            else {
                break;
            }
        }
    }

    void diving(int index) {
        int n = heap.size();
        while (true) {
            int largest = index;
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            if (leftChild < n && heap[leftChild].first > heap[largest].first) {
                largest = leftChild;
            }
            if (rightChild < n && heap[rightChild].first > heap[largest].first) {
                largest = rightChild;
            }
            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            }
            else {
                break;
            }
        }
    }

public:
    void push(const T1& priority, const T2& value) {
        heap.push_back(std::make_pair(priority, value));
        emersion(heap.size() - 1);
    }

    PairType pop() {
        if (isEmpty()) {
            throw std::out_of_range("priority queue is empty");
        }
        PairType root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        diving(0);
        return root;
    }

    PairType top() const {
        if (isEmpty()) {
            throw std::out_of_range("priority queue is empty");
        }
        return heap[0];
    }

    bool isEmpty() const {
        return heap.empty();
    }

    size_t size() const {
        return heap.size();
    }

    void clear() {
        heap.clear();
    }


    void printHeap() const {
        std::cout << "[ ";
        for (const auto& item : heap) {
            std::cout << "(" << item.first << ", " << item.second << ") ";
        }
        std::cout << "]" << std::endl;
    }
};


int run() {
    PriorityQueue<int, std::string> pq;

    pq.push(3, "task C");
    pq.push(10, "task A");
    pq.push(1, "task D");
    pq.push(7, "task B");
    pq.push(5, "task E");

    std::cout << "heap size: " << pq.size() << std::endl;
    std::cout << "hepa: "; pq.printHeap();

    while (!pq.isEmpty()) {
        auto top = pq.pop();
        std::cout << "priority: " << top.first << ", value: " << top.second << std::endl;
        std::cout << "heap: "; pq.printHeap();

    }
    try {
        pq.pop();
    }
    catch (const std::out_of_range& oshibka) {
        std::cout << "Error: " << oshibka.what() << std::endl;
    }

    return 0;
}