cmake_minimum_required(VERSION 3.19)
project(Gioco)

set(SFML_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SFML)

set(CMAKE_CXX_STANDARD 14)

#message("Adding test subdir")
#add_subdirectory(test)

set(SOURCE_FILES Include/Entity.h Source/Entity.cpp Include/Characters/Characters.h Source/Characters/Characters.cpp Include/Characters/Hero.h Source/Characters/Hero.cpp Include/Game.h Source/Game.cpp Include/Characters/Enemy.h Source/Characters/Enemy.cpp Include/Characters/Gregarious.h Include/Characters/RangedGregarious.h Source/Characters/Gregarious.cpp Source/Characters/RangedGregarious.cpp Include/Strategy/Strategy.h Source/Strategy/Strategy.cpp Include/Strategy/InspectionStrategy.h Source/Strategy/InspectionStrategy.cpp Include/Strategy/ChaseStrategy.h Source/Strategy/ChaseStrategy.cpp Include/Objects/Objects.h Source/Objects/Objects.cpp Include/Objects/ObjectFactory.h Source/Objects/ObjectFactory.cpp Include/Objects/Medikit.h Source/Objects/Medikit.cpp Include/Objects/Consumables.h Source/Objects/Consumables.cpp Include/Objects/Weapons/MeleeWeapon.h Source/Objects/Weapons/MeleeWeapon.cpp Include/Objects/Weapons/RangedStWeapon.h Source/Objects/Weapons/RangedStWeapon.cpp Include/Objects/Weapons/RangedAoeWeapon.h Source/Objects/Weapons/RangedAoeWeapon.cpp Include/Objects/Weapons/Weapon.h Source/Objects/Weapons/Weapon.cpp Include/Random.h Source/Random.cpp Include/ResourceHolder.h Include/ResourceIdentifier.h Include/World.h Source/World.cpp Source/Characters/EnemyFactory.cpp Include/Characters/EnemyFactory.h Include/Objects/Weapons/Bullets.h Source/Objects/Weapons/Bullets.cpp Include/Menu.h Source/Menu.cpp Include/TextDisplay.h Source/TextDisplay.cpp Include/Map.h Source/Map.cpp Include/Objects/Tile.h Source/Objects/Tile.cpp)

add_executable(Gioco Source/main.cpp)

set(CMAKE_MODULE_PATH ${SFML_ROOT}/sfml_cmake)
find_package(SFML REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})

message("Add library")
add_library(core ${SOURCE_FILES})
target_link_libraries(Gioco core ${SFML_LIBRARIES} )

get_directory_property(output INCLUDE_DIRECTORIES)
message("Include directories:" ${output})