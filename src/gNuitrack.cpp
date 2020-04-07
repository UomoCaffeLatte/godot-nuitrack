#include "gNuitrack.hpp"

#define _ERROR_PRINT(msg) godot::Godot::print_warning(msg,__FUNCTION__,__FILE__,__LINE__)

namespace godot {

    bool gNuitrack::_init_state = false; // definining the static variable

    void gNuitrack::_register_methods () {
        register_method("test", &gNuitrack::init);
        register_method("update", &gNuitrack::update);

        register_property<gNuitrack, int>("num_skeleton", nullptr, &gNuitrack::get_num_skeletons, 0);
    }

    void gNuitrack::_init(){
    }

    int gNuitrack::get_num_skeletons() const { // const restricts class to only reading of class variables
        return _num_skeletons;
    };

    bool gNuitrack::get_init_state() const {
        return _init_state;
    }

    gNuitrack::~gNuitrack(){
        // clean up code
        tdv::nuitrack::Nuitrack::release();
    }

    bool gNuitrack::init(godot::Variant config_values){
        bool config_state = false;
        // initalise nuitrack library
        try {
            // initalize nuitrack
            tdv::nuitrack::Nuitrack::init();
            // set config values
            config_state = gNuitrack::_set_config_values(config_values);

            if (config_state == true) {
              _init_state = true;
                return true;  
            } else if (config_state == false) {
                _ERROR_PRINT("Failed to set Nuitrack config values");
                return false;
            } else {
                _ERROR_PRINT("Failed to run Nuitrack set config values");
                return false;
            }
            
        } catch (const tdv::nuitrack::Exception& e) {
            _ERROR_PRINT("Failed to initalise Nuitrack");
            _init_state = false;
            return false;
        }

        // _skeleton_tracker_ptr = tdv::nuitrack::SkeletonTracker::create();

		// // link on update method to skeleton tracker
		// _skeleton_tracker_ptr->connectOnUpdate([&](tdv::nuitrack::SkeletonData::Ptr userSkeleton){gNuitrack::on_update_skeleton(userSkeleton);}); // lambda expression, [&] means pass everything by reference
        
        // try{
        //     tdv::nuitrack::Nuitrack::run();
        // } catch (const tdv::nuitrack::Exception& e) {
        // }
    }

    bool gNuitrack::_set_config_values(godot::Variant config_values){

        godot::Array config_array = config_values;

        // Loop through config array
    
        //tdv::nuitrack::Nuitrack::setConfigValue();
        return true;
    }

    void gNuitrack::on_update_skeleton(tdv::nuitrack::SkeletonData::Ptr skeleton_data){
        _skeleton_data_ptr = skeleton_data;
        _num_skeletons = skeleton_data->getNumSkeletons();
    };

    void gNuitrack::update(){
        tdv::nuitrack::Nuitrack::waitUpdate(_skeleton_tracker_ptr);
    }

}
