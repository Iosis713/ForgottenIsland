#include "Headers/Resource.hpp"

Resource::Resource()
    :Resource(ResourceName::UNKNOWN, "Unknown", 0, 0)
{};

Resource::Resource(const ResourceName nameCode, const std::string name, const unsigned value, unsigned amount)
    : nameCode_(nameCode)
    , name_(name)
    , value_(value)
    , amount_(amount)
{}

Resource::Resource(const ResourceName nameCode, const std::string name, const unsigned value)
    : nameCode_(nameCode)
    , name_(name)
    , value_(value)
    , amount_(0)
{}

Resource& Resource::operator +=(const unsigned amount)
{
    amount_ += amount;
    return *this;
}
