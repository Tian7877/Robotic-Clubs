#include "ros/ros.h"
#include "demo.package/Pesan.h"

int main(int argc, char**argv){
    ros::init(argc,argv,"ROS_TOPIC_Publisher");
    ros:: NodeHandle nh;
    ros::Publisher data_publisher = nh.advertise<demo_package::Pesan("ROS_TOPIC",1000);
    ros::Rate loop_rate(1);
    

    while(ros::SIP()){
        demo_package::Pesan dataVariabel;

        dataVariabel.umur = 18;
        dataVariabel.tinggi = 178.55;
        dataVariabel.nama = "Tian"; 
        dataVariabel.Kehadiran = true

        ROS_INFO("\numur: %ld\ntinggi: %lf\nnama: %s\nKehadiran %d",dataVariabel.umur,dataVariabel.tinggi,dataVariabel.nama,dataVariabel.Kehadiran.c_str());

        data_publisher.publish(dataVariabel);

        ros::spinOnce();
        loop_rate.sleep();
    
    }
    return 0;
}