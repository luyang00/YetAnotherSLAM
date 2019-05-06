#ifndef __DATALOADER_H
#define __DATALOADER_H
#include "common.h"
#include "frame.h"
namespace YetAnotherSLAM 
{
class Data{
public:
    std::string rgb_file;
    std::string depth_file;
    std::string time_stamp;
    Data(std::string time_stamp,std::string rgb_file,std::string depth_file):
    rgb_file(rgb_file),depth_file(depth_file),time_stamp(time_stamp){};
    ~Data(){};
};
class Dataloader
{
private:
    int frames_total;
    std::queue<Frame> q_videos;
  
public:
    Dataloader(){};
    ~Dataloader(){};
    int getTotalFrames(){return frames_total;}
    Frame popNextFrame()
    {
        Frame frame = q_videos.front();
        q_videos.pop(); 
        return frame;
    }
   
    void pushNextFrame(Frame frame){ q_videos.push(frame);};
    
};
}

#endif