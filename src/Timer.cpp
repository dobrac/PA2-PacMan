#include "Timer.h"

template<class _Time, bool _startOnCreate>
Timer<_Time, _startOnCreate>::Timer() : m_Begin(m_type_Clock::now()) {
}

template<class _Time, bool _startOnCreate>
void Timer<_Time, _startOnCreate>::reset() {
    m_Begin = m_type_Clock::now();
}

template<class _Time, bool _startOnCreate>
double Timer<_Time, _startOnCreate>::elapsed() const {
    if (m_Paused)
        return m_Sum;

    return elapsedInner() + m_Sum;
}

template<class _Time, bool _startOnCreate>
void Timer<_Time, _startOnCreate>::resume() {
    if (!m_Paused)
        return;

    reset();
    m_Paused = false;
}

template<class _Time, bool _startOnCreate>
void Timer<_Time, _startOnCreate>::pause() {
    if (m_Paused)
        return;

    m_Sum += elapsedInner();
    m_Paused = true;
}

template<class _Time, bool _startOnCreate>
double Timer<_Time, _startOnCreate>::elapsedInner() const {
    return std::chrono::duration_cast<_Time>
            (m_type_Clock::now() - m_Begin).count();
}
