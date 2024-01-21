#include "timehelper.h"

auto TimeHelper::GetCurrentTime()
{
    return Time::now();
}

TimeHelper::TimeHelper()
{

}

void TimeHelper::Init()
{
    last_frame_time_ = GetCurrentTime();
}

double TimeHelper::GetDt()
{
    using seconds_fp = std::chrono::duration<double, std::chrono::seconds::period>;
    auto current_time  = GetCurrentTime();


    const auto interval = current_time - last_frame_time_;
    const auto ret = std::chrono::duration_cast<seconds_fp>(interval).count();

    last_frame_time_ = current_time;

    return ret;
}

