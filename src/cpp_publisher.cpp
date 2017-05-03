#include "ros/ros.h"
#include "std_msgs/String.h"
#include "cpp_publisher_subscriber/SuperAwesome.h"

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  ros::init(argc, argv, "cpp_publisher");

  ros::NodeHandle n;

  ros::Publisher status_pub = n.advertise<cpp_publisher_subscriber::SuperAwesome>("my_status",1);

  ros::Rate loop_rate(1000000);

  int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg; 
    cpp_publisher_subscriber::SuperAwesome myMsg; 

    myMsg.my_status = "feeling awesome!";

    status_pub.publish(myMsg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
