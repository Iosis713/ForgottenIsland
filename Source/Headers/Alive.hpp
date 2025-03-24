#pragma once
#ifndef ALIVE
#define ALIVE

class Alive 
{
protected:
    int HP_ = 10;
public:
    Alive() = delete;
    Alive(const int HP);
    virtual ~Alive() = default;
    int inline getHP() const { return this->HP_; };
    void inline setHP(const int HP) { HP_ = HP;};
    Alive& operator-=(const int value);
    Alive& operator+=(const int value);
    bool operator==(const Alive& other) const;
};

#endif
