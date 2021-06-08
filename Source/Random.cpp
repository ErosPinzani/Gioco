//
// Created by erosp on 08/06/2021.
//

#include "..\Include\Random.h"

int generateRandom(int max) {

    int random = (rand() % max)+1;
    return random;
}

int generateRandom0(int max) {

    int random = (rand() % max);
    return random;
}

bool generateRandBool() {
    int random = (rand() % 2) + 1;
    //if 1 returns true else false
    return random==1;
}