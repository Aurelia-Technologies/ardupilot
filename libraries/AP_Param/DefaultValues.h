#pragma once

#include <AP_Common/AP_Common.h>
#include <AP_Param/AP_Param.h>
#include <map>
#include <array>

class DefaultValues
{
public:
    DefaultValues();
    CLASS_NO_COPY(DefaultValues);
    static DefaultValues *get_singleton();
    
    std::array<float, 2> get_data(const char *);

private:
    static DefaultValues *_singleton;
    struct comparison;
    static std::map<const char *, std::array<float, 2>, comparison> value_range;
    void init_data();
};

namespace AP
{
    DefaultValues &dv();
};
