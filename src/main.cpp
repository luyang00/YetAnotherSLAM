#include "camera.h"
#include "frame.h"
#include "dataloader/dataloader.h"
#include "dataloader/fireburg_dataloader.h"
using namespace YetAnotherSLAM;
int main(void)
{
    cv::namedWindow("color");
     cv::namedWindow("depth");
    // YetAnotherSLAM::Camera camera( "../config/fr1.yaml" );
    FireburgDataloader dataloader( "../config/fr1.yaml","../dataset/rgbd_dataset_freiburg1_room/");
    Frame frame;

    for (int i=0;i< dataloader.getTotalFrames();i++){
        frame = dataloader.popNextFrame();
        cv::imshow("color",frame.color_);
        cv::imshow("depth",frame.depth_);

        cv::waitKey(50);
    }


    return 0;
}