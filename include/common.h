#ifndef __COMMON_H
#define __COMMON_H

//For debug message
#define DEBUG std::cout<<"[DEBUG] "
#define END std::endl

#define ERROR std::cout<<"[ERROR] "

// define the commonly included file to avoid a long include list
// for Eigen
#include <Eigen/Core>
#include <Eigen/Geometry>


// for Sophus
#include <sophus/se3.hpp>
#include <sophus/so3.hpp>


// for cv
#include <opencv2/core/core.hpp>
#include "opencv2/opencv.hpp"

#include "opencv2/imgproc.hpp"


// std 
#include <vector>
#include <list>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>


#endif