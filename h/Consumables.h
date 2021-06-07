//
// Created by erosp on 06/06/2021.
//

#ifndef CHARACTERS_H_CONSUMABLES_H
#define CHARACTERS_H_CONSUMABLES_H

#include "Objects.h"

class Consumables: public Objects {

public:
    int getQuantity() const;
    void update() override;

public:
    bool collected;

protected:
    int quantity = 0;

};

#endif //CHARACTERS_H_CONSUMABLES_H
