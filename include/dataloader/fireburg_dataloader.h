#ifndef __FIREBURG_DATALOADER_H
#define __FIREBURG_DATALOADER_H
#include "common.h"
#include "dataloader/dataloader.h"
namespace YetAnotherSLAM 
{
 
class FireburgDataloader : public Dataloader
{
private:
    std::string data_path;
    std::shared_ptr<Camera> p_camera;
    const std::string depth_txt_filename = "depth.txt";
    const std::string rgb_txt_filename = "rgb.txt";
    const std::string groundtruth_txt_filename = "groundtruth.txt";
    int frames_total;
    std::queue<Data> q_data;

    void parseRecord(const std::string& line, std::string& time_stamp, std::string& filepath);
public:
    FireburgDataloader(std::string camera_param_path,std::string data_path);
    ~FireburgDataloader(){};

    Frame popNextFrame(void);
    int getTotalFrames();
   
    
};
}

#endif