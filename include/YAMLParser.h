#ifndef __YAMLParser_H
#define __YAMLParser_H

#include "common.h" 

namespace CONFIG 
{
class YAMLParser
{
private:
    static std::shared_ptr<YAMLParser> yaml_; 
    cv::FileStorage file_;
    
    YAMLParser () {} // private constructor makes a singleton
public:
    ~YAMLParser();  // close the file when deconstructing 
    
    // set a new yaml file 
    static void setParameterFile( const std::string& filename ); 
    
    // access the parameter values
    template< typename T >
    static T parse( const std::string& key )
    {
        return T( YAMLParser::yaml_->file_[key] );
    }
};
}

#endif // CONFIG_H