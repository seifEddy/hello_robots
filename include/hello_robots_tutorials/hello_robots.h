#include <ros/ros.h>
#include <std_msgs/String.h>

class HelloRobots
{
    public:
        HelloRobots(ros::NodeHandle* nh);
        ~HelloRobots();

        // This function will run every timestep
        void update(const ros::TimerEvent&);

        // This function will be executed each time a new message is received
        void message_callback(const std_msgs::String::ConstPtr& msg);

    private:
        ros::NodeHandle nh_;
        ros::Timer timer;
        std_msgs::String msg;
        ros::Publisher message_publisher;
        ros::Subscriber message_subscriber;

};

HelloRobots::HelloRobots(ros::NodeHandle* nh) : nh_(*nh)
{
    message_publisher = nh_.advertise<std_msgs::String>("/message", 10, true);
    message_subscriber = nh_.subscribe<std_msgs::String>("/message", 10, &HelloRobots::message_callback, this);
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

void HelloRobots::message_callback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("MESSAGE RECEIVED [%s]", msg->data.c_str());
}