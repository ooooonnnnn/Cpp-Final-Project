#include "EnemyFactory.h"

#include "Dragon.h"
#include "Skeleton.h"
#include "Zombie.h"

Character* EnemyFactory::make_enemy(std::string enemy_type)
{
    if (enemy_type == "zombie") return new Zombie();
    if (enemy_type == "skeleton") return new Skeleton();
    if (enemy_type == "dragon") return new Dragon();
    
    return nullptr;
}
