#include "ros/ros.h"
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv) 
{
    ros::init(argc, argv, "turtle_publisher");

    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

    ros::Rate loop_rate(10);

    while (ros::ok())
    {

        geometry_msgs::Twist msg;
        msg.linear.x =  0.5;
        msg.angular.z = 0;

        ROS_INFO("turtle velocity: linear=%.2f , angular=%.2f", msg.linear.x , msg.angular.z );

        ros::spinOnce();
        loop_rate.sleep();



        
    }
    





    return 0;
}



