#ifndef _odom_to_pose_covariance_hpp
#define _odom_to_pose_covariance_hpp

#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

class odom_to_pose_covariance
{
public:
	odom_to_pose_covariance( const ros::NodeHandle &_nh, const ros::NodeHandle &_nh_priv );
	
	bool start();

private:
	ros::NodeHandle nh;
	ros::NodeHandle nh_priv;
	ros::Subscriber odometry_sub;
	ros::Publisher pose_with_covariance_stamped_pub;

	void odometryCB(const nav_msgs::OdometryPtr &msg);
};

#endif   // _odom_to_pose_covariance_hpp
