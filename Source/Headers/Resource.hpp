#pragma once
#ifndef RESOURCE
#define RESOURCE

#include <string>

enum class ResourceName
{
    UNKNOWN = 0,
    Ash = 1,
    Wheat = 2,
    Rock = 3,
    Iron = 4
};

struct Resource
{
public:
    const ResourceName nameCode_ = ResourceName::UNKNOWN;
    const std::string name_ = "Unknown";
    const unsigned value_ = 0;
    unsigned amount_ = 1;

    Resource(ResourceName nameCode, const std::string name_, unsigned value,unsigned amount);
    virtual ~Resource() = default;
};

#endif
