#include "dataloader/fireburg_dataloader.h"
#include <stdlib.h>


namespace YetAnotherSLAM{
     void FireburgDataloader::parseRecord(const std::string& line, std::string& time_stamp, std::string& filepath){
          int split_pos = line.find(" ");
          int len = line.length();
          time_stamp = line.substr(0,split_pos);
          filepath =  this->data_path + line.substr(split_pos+1,len);
     }
     FireburgDataloader::FireburgDataloader(std::string camera_param_path,std::string data_path){
          //inita camera from params
          p_camera = std::make_shared<Camera>(camera_param_path);

          this->data_path = data_path;
          DEBUG << "open RGB txt file: "<<data_path + rgb_txt_filename <<END;
          std::ifstream fin_RGB(data_path + rgb_txt_filename,std::ios::in);
          DEBUG << "open depth txt file: "<<data_path + depth_txt_filename <<END;
          std::ifstream fin_depth(this->data_path+depth_txt_filename);
        
          if(!fin_RGB || !fin_depth)
          {
             ERROR<< "please check data path is correct" <<END; 
          }

          std::string line_rgb,line_depth;
          while(std::getline(fin_RGB,line_rgb) && std::getline(fin_depth,line_depth))
          {
               if(line_rgb[0]=='#' || line_depth[0]=='#') continue;
               std::string time_stamp,rgb_path,depth_path;
               parseRecord(line_rgb,time_stamp,rgb_path);
               parseRecord(line_depth,time_stamp,depth_path);

               q_data.push(Data(time_stamp,rgb_path,depth_path));
         }
         //total length of data
         frames_total = q_data.size();
     }
     Frame FireburgDataloader::popNextFrame(void){
          Data data = q_data.front();
          q_data.pop();
          Frame::Ptr pFrame = Frame::createFrame();
          pFrame->camera_ = p_camera;
          pFrame->color_ = cv::imread(data.rgb_file);
          pFrame->depth_ = cv::imread(data.depth_file);
          pFrame->time_stamp_ = atof(data.time_stamp.c_str());
          return *pFrame;
     }


    int FireburgDataloader::getTotalFrames()
    {
         return frames_total;
    }
}
