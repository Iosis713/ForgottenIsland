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
