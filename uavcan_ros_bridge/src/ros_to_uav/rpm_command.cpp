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
bool convert(const acomar_thruster::ThrusterArray& ros_msg, uavcan::equipment::esc::RPMCommand& uav_msg)
{
    uav_msg.rpm.resize(10);

    uav_msg.rpm[0] = ros_msg.data[0]*7*9.549; //ESC 0, As T500 Thrusters have 7 pole pairs the input is now correctly sent as VESC believes the input is in ERPM (was 3000). 
    uav_msg.rpm[1] = ros_msg.data[1]*7*9.549;; // these are extended with  9.549 which is equal to 60/2pi which is convertion from rad/s to rpm
    uav_msg.rpm[2] = ros_msg.data[2]*7*9.549;;
    uav_msg.rpm[3] = ros_msg.data[3]*7*9.549;;
    uav_msg.rpm[4] = ros_msg.data[4]*7*9.549;;
    uav_msg.rpm[5] = ros_msg.data[5]*7*9.549;;
    uav_msg.rpm[6] = ros_msg.data[6]*7*9.549;;
    uav_msg.rpm[7] = ros_msg.data[7]*7*9.549;;


  // uav_msg.rpm[1] = ros_msg.thruster_1*7; //ESC 1
    return true;
}

}
