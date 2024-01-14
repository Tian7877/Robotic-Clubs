

import rospy
from demo_package.msg import Pesan

def main():
    rospy.init_node("ROS_TOPIC_Publisher")
    data_publisher = rospy.Publisher("ROS_TOPIC", Pesan, queue_size=1000)
    rate = rospy.Rate(1)

    while not rospy.is_shutdown():
        data_variable = Pesan()

        data_variable.umur = 18
        data_variable.tinggi = 178.55
        data_variable.nama = "Tian"
        data_variable.Kehadiran = True

        rospy.loginfo("\numur: %ld\ntinggi: %lf\nnama: %s\nKehadiran %d",
                      data_variable.umur, data_variable.tinggi, data_variable.nama, data_variable.Kehadiran)

        data_publisher.publish(data_variable)

        rate.sleep()

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
