#pragma once
#ifndef INVENTORY
#define INVENTORY

#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>

#include "Resource.hpp"

using Items = std::vector<std::shared_ptr<Resource>>;

class Inventory
{
private:
    Items items_;
    
public:
    Inventory();
    ~Inventory() = default;

    void add(const std::shared_ptr<Resource> resourcePtr);
    void sortByAmount();
    void sortByName();
    void sortByUnitValue();
    
    //________________________GETTERS_________________________________//

    inline Items getItems() { return this->items_; };
    
    //________________________TEMPLATES_______________________________//
    

    
    

};

#endif
