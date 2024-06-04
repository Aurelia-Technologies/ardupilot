#include "DefaultValues.h"
//#include "../GCS_MAVLink/GCS.h"

DefaultValues *DefaultValues::_singleton = nullptr;

struct DefaultValues::comparison
{
    bool operator()(const char *a, const char *b) const
    {
        return strcmp(a, b) < 0;
    }
}; 
std::map<const char *, std::array<float, 2>, DefaultValues::comparison> DefaultValues::value_range;

DefaultValues::DefaultValues()
{
    if (_singleton)
    {
        AP_HAL::panic("Too many DefaultValues instances");
    }
    _singleton = this;
}

void DefaultValues::init_data()
{
    /*
    It has the following structure:
    value_range[PARAM_ID] = {Minimum, Maximum}
    */
    value_range["ACRO_BAL_PITCH"] = {1.0f, 2.0f};
}

std::array<float, 2>
DefaultValues::get_data(const char *index)
{
    if (value_range.empty())
    {
        init_data();
    }
    return value_range[index];
}

DefaultValues *DefaultValues::get_singleton()
{
    return DefaultValues::_singleton;
}

namespace AP
{
    DefaultValues &dv()
    {
        return *DefaultValues::get_singleton();
    }

};
