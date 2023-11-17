#include <ros/ros.h>
#include <std_msgs/Int8.h>

int main(int argc, char** argv) 
{
ros::init(argc, argv, "publisher"); // node name

ros::NodeHandle n;


ros::Publisher pub = n.advertise<std_msgs::Int8>("chatter", 1000); // creat publisher 
// chater is topic name (must be as same as sub topic)
ros::Rate loop_rate(10);

int count = 20;

while (ros::ok() && count <= 100)

{
    
std_msgs::Int8 msg;
msg.data = count;
pub.publish(msg);
ROS_INFO("publisher: = %d", msg.data );

ros::spinOnce();
loop_rate.sleep();
++count;


}

    return 0;
}