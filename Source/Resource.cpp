#include "Headers/Resource.hpp"

Resource::Resource(ResourceName name, const unsigned value, unsigned amount)
    : name_(name)
    , value_(value)
    , amount_(amount)
{}

