#include "Headers/Inventory.hpp"

Inventory::Inventory()
{
    items_.reserve(50);
}

void Inventory::sortByAmount()
{
    std::sort(items_.begin(), items_.end(), [](auto& previous, auto& next)
        {
            return previous->amount_ <= next->amount_;
        });
}

void Inventory::sortByName()
{
    std::sort(items_.begin(), items_.end(), [](auto& previous, auto& next)
        {
            return previous->name_ <= next->name_;
        });
}

void Inventory::sortByUnitValue()
{
    std::sort(items_.begin(), items_.end(), [](auto& previous, auto& next)
        {
            return previous->value_ <= next->value_;
        });
}

void Inventory::add(const std::shared_ptr<Resource> resourcePtr)
{
    if(!resourcePtr)
        return;
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
        items_.push_back(std::make_shared<Resource>(resourcePtr->nameCode_, resourcePtr->name_, resourcePtr->value_, resourcePtr->amount_));
    }
}