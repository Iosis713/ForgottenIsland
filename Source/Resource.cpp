#include "Headers/Resource.hpp"

Resource::Resource(const ResourceName nameCode, const std::string name, const unsigned value, unsigned amount)
    : nameCode_(nameCode)
    , name_(name)
    , value_(value)
    , amount_(amount)
{}

