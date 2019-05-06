#include "YAMLParser.h"

namespace CONFIG 
{
    
void YAMLParser::setParameterFile( const std::string& filename )
{
    if ( yaml_ == nullptr )
        yaml_ = std::shared_ptr<YAMLParser>(new YAMLParser);
    yaml_->file_ = cv::FileStorage( filename.c_str(), cv::FileStorage::READ );
    if ( yaml_->file_.isOpened() == false )
    {
        std::cerr<<"parameter file "<<filename<<" does not exist."<<std::endl;
        yaml_->file_.release();
        return;
    }
}

YAMLParser::~YAMLParser()
{
    if ( file_.isOpened() )
        file_.release();
}

std::shared_ptr<YAMLParser> YAMLParser::yaml_ = nullptr;

}