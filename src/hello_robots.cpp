#include <hello_robots_tutorials/hello_robots.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "hello_robots_node");
    ros::NodeHandle nh;
    HelloRobots hrn(&nh);
    ros::spin();
    return 0;
}