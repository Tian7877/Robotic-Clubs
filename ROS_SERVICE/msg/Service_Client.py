
import rospy
from demo_package import Pesan

def vector_magnitude_client(x, y, z):
    rospy.wait_for_service('calculate_magnitude')
    try:
        calculate_magnitude = rospy.ServiceProxy('calculate_magnitude', VectorService)
        response = calculate_magnitude(x, y, z)
        rospy.loginfo(f"Magnitude : {response}")
    except rospy.ServiceException as e:
        rospy.logerr(f"GAGAL: {e}")

if __name__ == "__main__":
    rospy.init_node('vector_magnitude_client')
    vector_magnitude_client(3.0, 4.0, 5.0)  # Contoh Nilai 
