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

    void sortByAmount();
    void sortByName();
    void sortByUnitValue();
    
    //________________________GETTERS_________________________________//

    inline Items getItems() { return this->items_; };
    
    //________________________TEMPLATES_______________________________//
    

    //TO CHANGE TO DO TO DO TO DO
    //template <typename Resource_t>
    void add(std::shared_ptr<Resource> resourcePtr)
    {
        auto existingItem = std::find_if(items_.begin(), items_.end(), [&resourcePtr](const auto& item)
                {
                    return item->nameCode_ == resourcePtr->nameCode_;
                }
            );

        if(existingItem != items_.end())
        {
            std::cout << "Existing Item amount = " << (*existingItem)->amount_ << '\n';
            (*existingItem)->amount_ += resourcePtr->amount_;
            std::cout << "Resource Item amount = " << resourcePtr->amount_ << '\n';
        }
        
        else
        {
            std::cout << "Last iterator!\n";
            items_.push_back(resourcePtr);
        }
    }

    

};

#endif
