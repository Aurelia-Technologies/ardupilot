#include "Global_Constants.h"

GlobalConstants *GlobalConstants::instance = nullptr;

int GlobalConstants::RID_VALUE = RID_DEFAULT;
int GlobalConstants::BPS_VALUE = BPS_DEFAULT;

GlobalConstants::GlobalConstants()
{
    if (instance)
    {
        AP_HAL::panic("Too many GlobalConstants instances");
    }
    instance = this;
}

void GlobalConstants::set_bps_value(int _v)
{
    BPS_VALUE = _v;
}
void GlobalConstants::set_rid_value(char *_v)
{
    RID_VALUE = atoi(_v);
}
int GlobalConstants::get_rid_value()
{
    return RID_VALUE;
}
int GlobalConstants::get_bps_value()
{
    return BPS_VALUE;
}

GlobalConstants *GlobalConstants::get_singleton()
{
    return GlobalConstants::instance;
}

namespace AP
{
    GlobalConstants &gc()
    {
        return *GlobalConstants::get_singleton();
    }

};