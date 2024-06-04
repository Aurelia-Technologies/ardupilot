#pragma once
#include <AP_Param/AP_Param.h>
#include <AP_Common/AP_Common.h>
#include <map>

#define LOCK_DEFAULT 1
#define RID_DEFAULT 0
#define BPS_DEFAULT 20

class AP_CustomParams
{
public:
    AP_CustomParams();
    CLASS_NO_COPY(AP_CustomParams);
    static AP_CustomParams *get_singleton();

    int16_t get_lock_status() const;
    int32_t get_rid() const;
    int16_t get_bps() const;
    void set_lock_status(int16_t);
    static const struct AP_Param::GroupInfo var_info[];
    std::map<const char *, int> get_custom_params();

private:
    void init_custom_params();
    //static const char *custom_params[3];
    struct comparison;
    static std::map<const char *, int, comparison> custom_params;
    static AP_CustomParams *instance;

protected:
    AP_Int16 _lock;
    AP_Int16 _bps;
    AP_Int32 _rid;
};

namespace AP
{
    AP_CustomParams &cps();
};
