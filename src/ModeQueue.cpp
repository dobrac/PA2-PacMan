#include "ModeQueue.h"
#include "Console.h"


void ModeQueue::addFront(const std::shared_ptr<Mode> &mode) {
    m_Queue.push_front(mode);
}

void ModeQueue::add(const std::shared_ptr<Mode> &key) {
    m_Queue.push_back(key);
}

void ModeQueue::pop() {
    if (!empty())
        m_Queue.pop_front();
}

void ModeQueue::print() const {
    for (auto &it : m_Queue)
        Console::printLine("Mode: " + it->print());
}

bool ModeQueue::empty() const {
    return m_Queue.empty();
}

const std::shared_ptr<Mode> &ModeQueue::get() const {
    return m_Queue.front();
}

void ModeQueue::clear() {
    m_Queue.clear();
}
