#ifndef __FRAME_H
#define __FRAME_H

#include "common.h"
#include "camera.h"

namespace YetAnotherSLAM 
{

class Frame
{
public:
    typedef std::shared_ptr<Frame> Ptr;
    unsigned long                  id_;         // id of this frame
    double                         time_stamp_; // when it is recorded
    Sophus::SE3d                            T_c_w_;      // transform from world to camera
    std::shared_ptr<Camera> camera_;     // Pinhole RGBD Camera model 
    cv::Mat                            color_, depth_; // color and depth image 
    // std::vector<cv::KeyPoint>      keypoints_;  // key points in image
    // std::vector<MapPoint*>         map_points_; // associated map points
    bool                           is_key_frame_;  // whether a key-frame
    
public: // data members 
    Frame();
    Frame( long id, double time_stamp=0, Sophus::SE3d T_c_w=Sophus::SE3d(), Camera::Ptr camera=nullptr, cv::Mat color=cv::Mat(), cv::Mat depth=cv::Mat() );
    ~Frame();
    
    static Frame::Ptr createFrame(); 
    
    // find the depth in depth map
    double findDepth( const cv::KeyPoint& kp );
    
    // Get Camera Center
    Eigen::Vector3d getCamCenter() const;
    
    void setPose( const Sophus::SE3d& T_c_w );
    
    // check if a point is in this frame 
    bool isInFrame( const Eigen::Vector3d& pt_world );
};

}

#endif // FRAME_H