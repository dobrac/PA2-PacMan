#include "ArrowQueue.h"
#include "Console.h"

void ArrowQueue::add(const Pos &key) {
    if (m_Queue.size() >= 3)
        return;

    for (auto &it : m_Queue)
        if (it == key)
            return;

    m_Queue.push_back(key);
}

void ArrowQueue::pop() {
    if (!empty())
        m_Queue.pop_front();
}

void ArrowQueue::print() const {
    for (auto &it : m_Queue)
        Console::printLine("Key: " + it());
}

bool ArrowQueue::empty() const {
    return m_Queue.empty();
}

const Pos &ArrowQueue::get() const {
    return m_Queue.front();
}

void ArrowQueue::clear() {
    m_Queue.clear();
}
