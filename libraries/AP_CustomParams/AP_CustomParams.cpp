#include "AP_CustomParams.h"

AP_CustomParams *AP_CustomParams::instance = nullptr;
// const char *AP_CustomParams::custom_params[3];
struct AP_CustomParams::comparison
{
    bool operator()(const char *a, const char *b) const
    {
        return strcmp(a, b) < 0;
    }
};
std::map<const char *, int, AP_CustomParams::comparison> AP_CustomParams::custom_params;

// const char* prefix = "CPS_"

const AP_Param::GroupInfo AP_CustomParams::var_info[] = {
    // index 0 was used for the old orientation matrix

    // @Param: LOCK
    // @DisplayName: Lock
    // @Description: Lock some parameters from being changed
    // @Range: 1 2
    // @User: Advanced
    AP_GROUPINFO("LOCK", 1, AP_CustomParams, _lock, LOCK_DEFAULT),
    // @Param: RID
    // @DisplayName: RID
    // @Description: ID of RID module
    // @Range: -1 99999
    // @User: Advanced
    AP_GROUPINFO("RID", 2, AP_CustomParams, _rid, RID_DEFAULT),
    // @Param: BPS
    // @DisplayName: BPS
    // @Description: BPS
    // @Range: 10 20
    // @User: Advanced
    AP_GROUPINFO("BPS", 3, AP_CustomParams, _bps, BPS_DEFAULT),
    AP_GROUPEND};

std::map<const char *, int> AP_CustomParams::get_custom_params()
{
    if (custom_params[0] == 0)
    {
        init_custom_params();
    }
    std::map<const char *, int> new_map(custom_params.begin(), custom_params.end());
    return new_map;
}
//{100000, 100, 10};

void AP_CustomParams::init_custom_params()
{
    custom_params["CPS_RID"] = 100000;
    custom_params["CPS_BPS"] = 100;
    custom_params["CPS_LOCK"] = 10;
}

AP_CustomParams::AP_CustomParams()
{
    // AP_Param::setup_object_defaults(this, var_info); // load parameter defaults
    if (instance)
    {
        AP_HAL::panic("Too many AP_CustomParams instances");
    }
    instance = this;

    AP_Param::setup_object_defaults(this, var_info);
}

int16_t AP_CustomParams::get_lock_status() const
{
    return _lock;
}
int32_t AP_CustomParams::get_rid() const
{
    return _rid;
}
int16_t AP_CustomParams::get_bps() const
{
    return _bps;
}

AP_CustomParams *AP_CustomParams::get_singleton()
{
    return AP_CustomParams::instance;
}

namespace AP
{

    AP_CustomParams &cps()
    {
        return *AP_CustomParams::get_singleton();
    }

};
