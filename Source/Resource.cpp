#include "Headers/Resource.hpp"

Resource::Resource(const ResourceName nameCode, const unsigned value, unsigned amount)
    : nameCode_(nameCode)
    , name_(ResourceNameTranslator().translateResourceName(nameCode))
    , value_(value)
    , amount_(amount)
{}

Resource::Resource(const ResourceName nameCode, const unsigned value)
    : nameCode_(nameCode)
    , name_(ResourceNameTranslator().translateResourceName(nameCode))
    , value_(value)
    , amount_(0)
{}

Resource& Resource::operator +=(const unsigned amount)
{
    amount_ += amount;
    return *this;
}

std::string ResourceNameTranslator::translateResourceName(const ResourceName resourceName) const
{
    using enum ResourceName;
    const auto name = resourceNamesMap_.find(resourceName);
    if(name != resourceNamesMap_.end())
        return name->second;
    else
        return resourceNamesMap_.at(UNKNOWN);
};