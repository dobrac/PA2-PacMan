#pragma once

#include <chrono>

/**
 * Timer class for tracking elapsed time
 * @tparam _Time Type of tracking, seconds or milliseconds
 * @tparam _startOnCreate Whether timer should start immediately or not
 */
template<class _Time, bool _startOnCreate = true>
class Timer {
public:

    /**
     * Instance new timer
     */
    Timer();

    /**
     * Reset timer back to zero
     */
    void reset();

    /**
     * Pause timer
     */
    void pause();

    /**
     * Resume timer
     */
    void resume();

    /**
     * Get elapsed time
     * @return elapsed time in seconds or milliseconds
     */
    double elapsed() const;

private:
    /**
     * Type definition of clock
     */
    typedef std::chrono::high_resolution_clock m_type_Clock;

    /**
     * Internal variable for clock start time save
     */
    std::chrono::time_point<m_type_Clock> m_Begin;

    /**
     * Is clock paused
     */
    bool m_Paused = !_startOnCreate;

    /**
     * Sum for clock pausing and resuming
     */
    double m_Sum = 0;

    /**
     * Get elapsed time without Sum variable
     * @return eapsed time in seconds or milliseconds
     */
    double elapsedInner() const;
};

/**
 * Type definition for seconds
 */
typedef std::chrono::duration<double, std::ratio<1> > Timer_Type_Second;

/**
 * Type definition for milliseconds
 */
typedef std::chrono::duration<double, std::ratio<1, 1000> > Timer_Type_Millisecond;

template
class Timer<Timer_Type_Second, true>;

template
class Timer<Timer_Type_Second, false>;

template
class Timer<Timer_Type_Millisecond, true>;

template
class Timer<Timer_Type_Millisecond, false>;