#pragma once
#ifndef RESOURCE
#define RESOURCE

enum class ResourceName
{
    UNKNOWN = 0,
    Wood = 1
};

struct Resource
{
public:
    const ResourceName name_ = ResourceName::UNKNOWN;
    const unsigned value_ = 0;
    unsigned amount_ = 1;

    Resource(ResourceName name, unsigned value, unsigned amount);
    virtual ~Resource() = default;
};

#endif
