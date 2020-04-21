#include "gNuitrack.hpp"

namespace godot {

    void gNuitrack::_on_update_skeleton(tdv::nuitrack::SkeletonData::Ptr skeleton_data){
        _skeleton_data_ptr = skeleton_data;

        _num_skeletons = skeleton_data->getNumSkeletons(); //skeleton_data->getNumSkeletons();
        
        // wrap skeleton data and get joint position for TORSO

    };
    
    //function to retrieve joints data from specific skeleton data

}