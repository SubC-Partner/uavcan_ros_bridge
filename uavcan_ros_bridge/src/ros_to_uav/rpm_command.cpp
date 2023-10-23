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
bool convert(const acomar_thruster::ThrusterArray& ros_msg, uavcan::equipment::esc::RPMCommand& uav_msg,  unsigned char uid)
{
    uav_msg.rpm.resize(10);
    int i = 1;


    uav_msg.rpm[0] = ros_msg.thruster_0*7; //ESC 0, As T500 Thrusters have 7 pole pairs the input is now correctly sent as VESC believes the input is in ERPM (was 3000). 
    uav_msg.rpm[1] = ros_msg.thruster_1*7; //ESC 1
    uav_msg.rpm[2] = ros_msg.thruster_2*7; //ESC 2
    uav_msg.rpm[3] = ros_msg.thruster_3*7; //ESC 3
    uav_msg.rpm[4] = ros_msg.thruster_4*7; //ESC 4
    uav_msg.rpm[5] = ros_msg.thruster_5*7; //ESC 5
    uav_msg.rpm[6] = ros_msg.thruster_6*7; //ESC 6
    uav_msg.rpm[7] = ros_msg.thruster_7*7; //ESC 7
    uav_msg.rpm[8] = ros_msg.thruster_8*7; //ESC 8
    uav_msg.rpm[9] = ros_msg.thruster_9*7; //ESC 9


    return true;
}

}
