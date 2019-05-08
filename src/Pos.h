#pragma once

#include <string>

class Pos {
public:
    Pos(int x, int y);

    bool compare(int x, int y) const;

    bool empty() const;

    std::string operator()() const;

    Pos &operator+=(const Pos &posAdd);

    Pos &operator-=(const Pos &posRemove);

    Pos &operator*=(const Pos &posMulti);

    Pos operator+(Pos posAdd) const;

    Pos operator-(Pos posRemove) const;

    Pos operator*(Pos posMulti) const;

    bool operator==(const Pos &posCmp) const;

    bool operator!=(const Pos &posCmp) const;


    bool operator<(const Pos &pos) const;

    int getX() const;

    int getY() const;

private:
    int m_X;
    int m_Y;
};
