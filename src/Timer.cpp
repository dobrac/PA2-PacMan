#include "Timer.h"

template<class _Time>
Timer<_Time>::Timer() : m_Begin(m_type_Clock::now()) {
}

template<class _Time>
void Timer<_Time>::reset() {
    m_Begin = m_type_Clock::now();
}

template<class _Time>
double Timer<_Time>::elapsed() const {
    return std::chrono::duration_cast<_Time>
            (m_type_Clock::now() - m_Begin).count();
}