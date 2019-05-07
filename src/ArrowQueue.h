#pragma once

#include "Pos.h"
#include <list>

class ArrowQueue {
public:
    void add(const Pos &key);

    void pop();

    void print() const;

    const Pos &get() const;

    bool empty() const;

private:
    std::list<Pos> m_Queue;
};
