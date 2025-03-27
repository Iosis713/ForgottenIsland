#pragma once
#ifndef ALIVE
#define ALIVE

#include <chrono>

using TimePoint = std::chrono::time_point<std::chrono::steady_clock>;

class Alive 
{
protected:
    int HP_ = 10;
    bool vulnerable_ = true;
    const unsigned invulnerabilityTime_ = 500; //ms
    TimePoint previousHit_{};

public:
    Alive() = delete;
    Alive(const int HP);
    virtual ~Alive() = default;
    int inline getHP() const { return this->HP_; };
    void inline setHP(const int HP) {HP_ = HP;};
    Alive& operator-=(const int value);
    Alive& operator+=(const int value);
    bool operator==(const Alive& other) { return this->HP_ == other.getHP(); };

    virtual void hitNow() {previousHit_ = std::chrono::steady_clock::now();};
    virtual void makeInvulnerable() {this->vulnerable_ = false;};
    virtual void makeVulnerable() {this->vulnerable_ = true;}
    virtual bool isVulnerable() const {return this->vulnerable_;};
    virtual void update();
};

#endif
