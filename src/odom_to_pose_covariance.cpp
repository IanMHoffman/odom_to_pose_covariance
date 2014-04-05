#include "odom_to_pose_covariance/odom_to_pose_covariance.hpp"

odom_to_pose_covariance::odom_to_pose_covariance( const ros::NodeHandle &_nh, const ros::NodeHandle &_nh_priv ) :
	nh( _nh ),
	nh_priv( _nh_priv )
{
}

bool odom_to_pose_covariance::start()
{
	if( !pose_with_covariance_stamped_pub )
		pose_with_covariance_stamped_pub = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>( "poseupdate", 2);

	if( !odometry_sub )
		odometry_sub = nh.subscribe( "encoder_odom", 1, &odom_to_pose_covariance::odometryCB, this);

	return true;
}

void odom_to_pose_covariance::odometryCB(const nav_msgs::OdometryPtr &msg)
{
	geometry_msgs::PoseWithCovarianceStampedPtr pose_msg(new geometry_msgs::PoseWithCovarianceStamped);
	pose_msg->header = msg->header;
	pose_msg->pose = msg->pose;
	pose_with_covariance_stamped_pub.publish(pose_msg);
}
