#include <ros/ros.h>
#include <std_msgs/String.h>

class HelloRobots
{
    public:
        HelloRobots(ros::NodeHandle* nh);
        ~HelloRobots();

        void update(const ros::TimerEvent&);
    private:
        ros::NodeHandle nh_;
        ros::Timer timer;
        std_msgs::String msg;
        ros::Publisher message_publisher;

};

HelloRobots::HelloRobots(ros::NodeHandle* nh) : nh_(*nh)
{
    message_publisher = nh_.advertise<std_msgs::String>("/message", 10, true);
    timer = nh_.createTimer(ros::Duration(1.0 / 30.0), &HelloRobots::update, this);
}

HelloRobots::~HelloRobots()
{
    ros::shutdown();
}

void HelloRobots::update(const ros::TimerEvent& e)
{
    msg.data = "Hello Robot friend, How are you?";

    message_publisher.publish(msg);
}