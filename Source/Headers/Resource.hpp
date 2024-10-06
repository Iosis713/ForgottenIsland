#pragma once
#ifndef RESOURCE
#define RESOURCE

#include <string>

enum class ResourceName
{
    UNKNOWN = 0,
    Wood = 1
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
