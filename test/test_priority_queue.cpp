#include "priority_queue.h"

#include <gtest.h>

TEST(PriorityQueueTest, PushAndSize) {
    PriorityQueue<int, std::string> pq;
    ASSERT_TRUE(pq.isEmpty());
    ASSERT_EQ(pq.size(), 0);

    pq.push(3, "task C");
    ASSERT_FALSE(pq.isEmpty());
    ASSERT_EQ(pq.size(), 1);

    pq.push(10, "task A");
    ASSERT_EQ(pq.size(), 2);

    pq.push(1, "task D");
    ASSERT_EQ(pq.size(), 3);
}


TEST(PriorityQueueTest, Pop) {
    PriorityQueue<int, std::string> pq;
    pq.push(3, "task C");
    pq.push(10, "task A");
    pq.push(1, "task D");


    auto top1 = pq.pop();
    ASSERT_EQ(top1.first, 10);
    ASSERT_EQ(top1.second, "task A");

    auto top2 = pq.pop();
    ASSERT_EQ(top2.first, 3);
    ASSERT_EQ(top2.second, "task C");


    auto top3 = pq.pop();
    ASSERT_EQ(top3.first, 1);
    ASSERT_EQ(top3.second, "task D");
    ASSERT_TRUE(pq.isEmpty());
}

TEST(PriorityQueueTest, top) {
    PriorityQueue<int, std::string> pq;
    pq.push(3, "task C");
    pq.push(10, "task A");

    ASSERT_EQ(pq.top().first, 10);
    ASSERT_EQ(pq.top().second, "task A");
    ASSERT_EQ(pq.size(), 2);

    pq.pop();
    ASSERT_EQ(pq.top().first, 3);
    ASSERT_EQ(pq.top().second, "task C");
}



TEST(PriorityQueueTest, EmptyQueue) {
    PriorityQueue<int, std::string> pq;
    ASSERT_TRUE(pq.isEmpty());
    ASSERT_THROW(pq.pop(), std::out_of_range);
    ASSERT_THROW(pq.top(), std::out_of_range);

}

TEST(PriorityQueueTest, Clear) {
    PriorityQueue<int, std::string> pq;
    pq.push(3, "task C");
    pq.push(10, "task A");
    pq.push(1, "task D");
    ASSERT_FALSE(pq.isEmpty());
    pq.clear();
    ASSERT_TRUE(pq.isEmpty());
    ASSERT_EQ(pq.size(), 0);
}

TEST(PriorityQueueTest, ComplexScenario) {
    PriorityQueue<int, std::string> pq;
    pq.push(3, "task C");
    pq.push(10, "task A");
    pq.push(1, "task D");
    pq.push(7, "task B");
    pq.push(5, "task E");

    ASSERT_EQ(pq.pop().second, "task A");
    ASSERT_EQ(pq.pop().second, "task B");
    ASSERT_EQ(pq.pop().second, "task E");
    ASSERT_EQ(pq.pop().second, "task C");
    ASSERT_EQ(pq.pop().second, "task D");
    ASSERT_TRUE(pq.isEmpty());
}

TEST(PriorityQueueTest, DifferentTypes) {
    PriorityQueue<double, int> pq;
    pq.push(3.5, 100);
    pq.push(10.2, 200);
    pq.push(1.1, 300);

    ASSERT_EQ(pq.pop().first, 10.2);
    ASSERT_EQ(pq.pop().first, 3.5);
    ASSERT_EQ(pq.pop().first, 1.1);
}


TEST(QueueTest, PushAndPop) {
    run();
    ADD_FAILURE();
}