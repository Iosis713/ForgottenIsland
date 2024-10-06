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

    template <typename Resource_t>
    void add(std::shared_ptr<Resource_t> resourcePtr)
    {
    auto existingItem = std::find_if(items_.begin(), items_.end(), [resourcePtr](auto& item)
            {
                return item->name_ == resourcePtr->name_;
            }
        );

    if (existingItem != items_.end())
        (*existingItem)->amount_ += resourcePtr->amount_;
    
    else
        items_.push_back(resourcePtr);
    }

};

#endif
