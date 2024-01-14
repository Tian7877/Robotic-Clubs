
#include "ros/ros.h"
#include "demo_package/Pesan.h"
#include <cmath>

bool handle_vector_magnitude(my_ros_package::VectorService::Request& req,
                             my_ros_package::VectorService::Response& res)
{
    res.magnitude = std::sqrt(req.komponenX * req.komponenX +
                              req.komponenY * req.komponenY +
                              req.komponenZ * req.komponenZ);

    ROS_INFO("Received Request: %f, %f, %f", req.komponenX, req.komponenY, req.komponenZ);
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "vector_magnitude_server_cpp");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("calculate_magnitude", handle_vector_magnitude);
    ROS_INFO("Calculator Magnitude");
    ros::spin();

    return 0;
}
