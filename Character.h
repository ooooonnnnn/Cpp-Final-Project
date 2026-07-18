#pragma once
#include <string>
#include <sstream>

class Character
{
protected:
    float health;
    float damage_taken = 0;
    float attack;
public:
    bool is_dead = false;
    virtual ~Character() = default;
    Character(float health, float attack);
    virtual void take_damage(float base_damage);
    void deal_damage_to(Character* target) const;
    void die();
    virtual std::string stats_to_string() const;
};
