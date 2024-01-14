
import rospy
from demo_package.msg import Pesan

def callback_handler(msg):
    rospy.loginfo("\n Saya Laksanakan: \n")
    rospy.loginfo("umur: %d\n", msg.umur)
    rospy.loginfo("tinggi: %lf\n", msg.tinggi)
    rospy.loginfo("nama: %s\n", msg.nama)
    rospy.loginfo("Kehadiran: %d\n", msg.Kehadiran)

def main():
    rospy.init_node("ROS_TOPIC_Subscriber")
    data_subscriber = rospy.Subscriber("ROS_TOPIC", Pesan, callback_handler)
    rospy.spin()

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
