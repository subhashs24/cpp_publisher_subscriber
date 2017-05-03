#include "ros/ros.h"
#include "std_msgs/String.h"
#include "cpp_publisher_subscriber/SuperAwesome.h"

void statusCallback(const cpp_publisher_subscriber::SuperAwesome::ConstPtr& msg)
{
 ROS_INFO("I heard: [%s]", msg->my_status.c_str());
 
}
int msgCount = 0;
int main(int argc, char **argv)
{
  ros::init(argc, argv, "cpp_subscriber");

  ros::NodeHandle n;

  ros::Subscriber sub1 = n.subscribe("my_status",1, statusCallback);

  ros::spin();

  return 0;
}
