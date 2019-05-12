#pragma once

#include <chrono>

template<class _Time, bool _startOnCreate = true>
class Timer {
public:
    Timer();

    void reset();

    void pause();

    void resume();

    double elapsed() const;

private:
    typedef std::chrono::high_resolution_clock m_type_Clock;
    std::chrono::time_point<m_type_Clock> m_Begin;

    bool m_Paused = !_startOnCreate;
    int m_Sum = 0;

    double elapsedInner() const;
};


typedef std::chrono::duration<double, std::ratio<1> > Timer_Type_Second;
typedef std::chrono::duration<double, std::ratio<1, 1000> > Timer_Type_Millisecond;
template class Timer<Timer_Type_Second, true>;
template class Timer<Timer_Type_Second, false>;
template class Timer<Timer_Type_Millisecond, true>;
template class Timer<Timer_Type_Millisecond, false>;