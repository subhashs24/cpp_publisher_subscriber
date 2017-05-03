#!/usr/bin/env python
import rospy
#from std_msgs.msg import String
from cpp_publisher_subscriber.msg import SuperAwesome

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.my_status)
    
def listener():

    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber("my_status", SuperAwesome, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()
