#include "ros/ros.h"
#include "demo_package/Pesan.h"

void callbackHandler(const demo_package::Pesan::ConstPtr &msg){

    ROS_INFO("\n Saya Laksanakan: \n");
    ROS_INFO("umur: %ld\n", msg->umur);
    ROS_INFO("tinggi: %lf\n", msg->tinggi);
    ROS_INFO("nama: %s\n", msg->nama.c_str());
    ROS_INFO("Kehadiran: %d\n", msg->Kehadiran);

}

int main(int argc, char **argv){
    ros::init(argc, argv, "ROS_TOPIC_Subscriber");
    ros::NodeHandle nh;
    ros::Subscriber data_subscriber = nh.subscribe("ROS_TOPIC", 1000, callbackHandler);
    ros::spin();
    return 0;
}
