#include <odom_to_pose_covariance/odom_to_pose_covariance.hpp>

int main( int argc, char *argv[] )
{
        ros::NodeHandle *nh = NULL;
        ros::NodeHandle *nh_priv = NULL;
        odom_to_pose_covariance *converter = NULL;

        ros::init( argc, argv, "odom_to_pose_covariance" );

        nh = new ros::NodeHandle( );
        if( !nh )
        {
                ROS_FATAL( "Failed to initialize NodeHandle" );
                ros::shutdown( );
                return -1;
        }
        nh_priv = new ros::NodeHandle( "~" );
        if( !nh_priv )
        {
                ROS_FATAL( "Failed to initialize private NodeHandle" );
                delete nh;
                ros::shutdown( );
                return -2;
        }
        converter = new odom_to_pose_covariance( *nh, *nh_priv );
        if( !converter )
        {
                ROS_FATAL( "Failed to initialize driver" );
                delete nh_priv;
                delete nh;
                ros::shutdown( );
                return -3;
        }
        if( !converter->start( ) )
                ROS_ERROR( "Failed to start the driver" );

	ros::spin( );

        delete converter;
        delete nh_priv;
        delete nh;

        return 0;
}

