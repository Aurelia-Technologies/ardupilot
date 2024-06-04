#pragma once
#include <AP_CustomParams/AP_CustomParams.h>
#include "../GCS_MAVLink/GCS.h"

#define LOCK_ENABLED 1
#define PASSWORD 99
#define ODID_DISABLED 99

class GlobalConstants
{
public:
    GlobalConstants();
    CLASS_NO_COPY(GlobalConstants);
    static GlobalConstants *get_singleton();

    void set_rid_value(char *_v);
    void set_bps_value(int _v);
    int get_rid_value();
    int get_bps_value();

private:
    static GlobalConstants *instance;
    static int RID_VALUE;
    static int BPS_VALUE;
};

namespace AP
{
    GlobalConstants &gc();
};
