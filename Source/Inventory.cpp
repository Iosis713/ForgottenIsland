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
        (*existingItem)->amount_ += resourcePtr->amount_;
    else
        items_.push_back(std::make_shared<Resource>(resourcePtr->nameCode_, resourcePtr->value_, resourcePtr->amount_));
}