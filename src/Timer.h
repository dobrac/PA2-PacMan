#pragma once

#include <chrono>

template<class _Time>
class Timer {
public:
    Timer();

    void reset();

    double elapsed() const;

private:
    typedef std::chrono::high_resolution_clock m_type_Clock;
    std::chrono::time_point<m_type_Clock> m_Begin;
};


typedef std::chrono::duration<double, std::ratio<1> > Timer_Type_Second;
typedef std::chrono::duration<double, std::ratio<1, 1000> > Timer_Type_Millisecond;
template class Timer<Timer_Type_Second>;
template class Timer<Timer_Type_Millisecond>;