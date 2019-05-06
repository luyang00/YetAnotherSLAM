#include "camera.h"
#include "YAMLParser.h"

namespace YetAnotherSLAM
{
    

Camera::Camera(std::string filename)
{
    CONFIG::YAMLParser::setParameterFile(filename);
    fx_ = CONFIG::YAMLParser::parse<float>("camera.fx");
    fy_ = CONFIG::YAMLParser::parse<float>("camera.fy");
    cx_ = CONFIG::YAMLParser::parse<float>("camera.cx");
    cy_ = CONFIG::YAMLParser::parse<float>("camera.cy");
    depth_scale_ = CONFIG::YAMLParser::parse<float>("camera.depth_scale");
    DEBUG << "Load param from yaml file:"<<filename <<END;
    DEBUG << "fx: "<<fx_<<",fy: "<< fy_ << ",cx: "<<cx_<<",cy: "<<cy_<<",depth_scale: "<< depth_scale_<<END; 
}

Eigen::Vector3d Camera::world2camera ( const Eigen::Vector3d& p_w, const Sophus::SE3d& T_c_w )
{
    return T_c_w*p_w;
}

Eigen::Vector3d Camera::camera2world ( const Eigen::Vector3d& p_c, const Sophus::SE3d& T_c_w )
{
    return T_c_w.inverse() *p_c;
}

Eigen::Vector2d Camera::camera2pixel ( const Eigen::Vector3d& p_c )
{
    return Eigen::Vector2d (
               fx_ * p_c ( 0,0 ) / p_c ( 2,0 ) + cx_,
               fy_ * p_c ( 1,0 ) / p_c ( 2,0 ) + cy_
           );
}

Eigen::Vector3d Camera::pixel2camera ( const Eigen::Vector2d& p_p, double depth )
{
    return Eigen::Vector3d (
               ( p_p ( 0,0 )-cx_ ) *depth/fx_,
               ( p_p ( 1,0 )-cy_ ) *depth/fy_,
               depth
           );
}

Eigen::Vector2d Camera::world2pixel ( const Eigen::Vector3d& p_w, const Sophus::SE3d& T_c_w )
{
    return camera2pixel ( world2camera(p_w, T_c_w) );
}

Eigen::Vector3d Camera::pixel2world ( const Eigen::Vector2d& p_p, const Sophus::SE3d& T_c_w, double depth )
{
    return camera2world ( pixel2camera ( p_p, depth ), T_c_w );
}

Eigen::Matrix4f Camera::getIntrinMatrix(){
    Eigen::Matrix4f K;
    K << fx_, 0, cx_, 0,
         0, fy_, cy_, 0,
         0, 0, 1, 0,
         0, 0, 0, 1;
    return K;
    
}

}