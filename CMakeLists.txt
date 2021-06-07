cmake_minimum_required(VERSION 3.19)
project(Gioco)

set(CMAKE_CXX_STANDARD 14)

add_executable(Gioco main.cpp h/Entity.h cpp/Entity.cpp h/Characters.h cpp/Characters.cpp h/Hero.h cpp/Hero.cpp h/Game.h cpp/Game.cpp h/Enemy.h cpp/Enemy.cpp h/Gregarious.h h/RangedGregarious.h cpp/Gregarious.cpp cpp/RangedGregarious.cpp h/Strategy.h cpp/Strategy.cpp h/InspectionStrategy.h cpp/InspectionStrategy.cpp h/ChaseStrategy.h cpp/ChaseStrategy.cpp h/Melee.h h/StRanged.h cpp/Melee.cpp cpp/StRanged.cpp h/AoeRanged.h cpp/AoeRanged.cpp h/Objects.h cpp/Objects.cpp h/ObjectFactory.h cpp/ObjectFactory.cpp h/Medikit.h cpp/Medikit.cpp h/Consumables.h cpp/Consumables.cpp h/MeleeWeapon.h cpp/MeleeWeapon.cpp h/RangedStWeapon.h cpp/RangedStWeapon.cpp h/RangedAoeWeapon.h cpp/RangedAoeWeapon.cpp h/Weapon.h cpp/Weapon.cpp h/RangedWeapon.h cpp/RangedWeapon.cpp)