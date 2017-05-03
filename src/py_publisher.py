#!/usr/bin/env python
# license removed for brevity
import rospy
#from std_msgs.msg import String
from cpp_publisher_subscriber.msg import SuperAwesome

def talker():
    pub = rospy.Publisher('my_status', SuperAwesome, queue_size=1)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        hello_str = "feeling awesome"
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass

