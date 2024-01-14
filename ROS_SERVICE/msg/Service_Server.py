
import rospy
from demo_package import Pesan

def handle_vector_magnitude(req):
    magnitude = sqrt(req.komponenX**2 + req.komponenY**2 + req.komponenZ**2)
    rospy.loginfo(f"Received Request: {req.komponenX}, {req.komponenY}, {req.komponenZ}")
    return magnitude

def vector_magnitude_server():
    rospy.init_node('vector_magnitude_server')
    s = rospy.Service('calculate_magnitude', VectorService, handle_vector_magnitude)
    rospy.loginfo("Calculator Magnitude")
    rospy.spin()

if __name__ == "__main__":
    vector_magnitude_server()
