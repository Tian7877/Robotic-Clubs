#include "ros/ros.h"
#include "demo_package/Pesan.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "vector_magnitude_client_cpp");
    ros::NodeHandle n;

    ros::ServiceClient client = n.serviceClient<my_ros_package::VectorService>("calculate_magnitude");
    my_ros_package::VectorService srv;
    
    srv.request.komponenX = 3.0;  // contoh nilai 
    srv.request.komponenY = 4.0;
    srv.request.komponenZ = 5.0;

    if (client.call(srv))
    {
        ROS_INFO("Magnitude: %f", srv.response.magnitude);
    }
    else
    {
        ROS_ERROR("Gagal");
        return 1;
    }

    return 0;
}
