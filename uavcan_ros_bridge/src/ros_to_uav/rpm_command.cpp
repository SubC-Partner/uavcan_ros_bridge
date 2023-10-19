#include <uavcan_ros_bridge/ros_to_uav/rpm_command.h>

namespace ros_to_uav {

template <>
bool convert(const std_msgs::Int32& ros_msg, uavcan::equipment::esc::RPMCommand& uav_msg)
{
    uav_msg.rpm.resize(1);
    uav_msg.rpm[0] = ros_msg.data;
    return true;
}

template <>
bool convert(const acomar_thruster::ThrusterCmd& ros_msg, uavcan::equipment::esc::RPMCommand& uav_msg)
{
    uav_msg.rpm.resize(1);
    uav_msg.rpm[0] = ros_msg.data*7; //ESC 0, As T500 Thrusters have 7 pole pairs the input is now correctly sent as VESC believes the input is in ERPM (was 3000). 
    //uav_msg.rpm[1] = ros_msg.data*7 //ESC 1
    //uav_msg.rpm[2] = ros_msg.data*7 //ESC 2 etc.
    return true;
}

}
