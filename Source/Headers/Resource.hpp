#pragma once
#ifndef RESOURCE
#define RESOURCE

#include <string>
#include <map>
enum class ResourceName : int
{
    UNKNOWN = 0,
    Ash = 1,
    Wheat = 2,
    Rock = 3,
    Iron = 4
};

class ResourceNameTranslator
{
protected:
    std::map<ResourceName, std::string> resourceNamesMap_ {
        {ResourceName::UNKNOWN, "Unknown"}
        , {ResourceName::Ash, "Ash"}
        , {ResourceName::Wheat, "Wheat"}
        , {ResourceName::Rock, "Rock"}
        , {ResourceName::Iron, "Iron"}
        };

public:
    ResourceNameTranslator() = default;
    ~ResourceNameTranslator() = default;

    std::string translateResourceName(const ResourceName resourceName) const;
};

struct Resource
{
public:
    const ResourceName nameCode_ = ResourceName::UNKNOWN;
    const std::string name_ = "Unknown";
    const unsigned value_ = 0;
    unsigned amount_ = 0;

    Resource() = default;
    Resource(ResourceName nameCode, unsigned value);
    Resource(ResourceName nameCode, unsigned value, unsigned amount);
    virtual ~Resource() = default;

    Resource& operator +=(const unsigned amount);
};

#endif
