#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string> 

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    ros::Rate loop_rate(1);

    int count = 0;
    while (ros::ok())
    {
        std::string str = "Hello World " + std::to_string(count);
        std_msgs::String msg;
        msg.data = str; 

        ROS_INFO("Talker said: [%s]", msg.data.c_str());

        chatter_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }

    return 0;
}
