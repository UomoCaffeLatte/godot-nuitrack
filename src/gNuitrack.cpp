#include "gNuitrack.hpp"

#define _ERROR_PRINT(msg) godot::Godot::print_warning(msg,__FUNCTION__,__FILE__,__LINE__)

namespace godot {

    bool gNuitrack::_init_state = false; // definining the static variable
    bool gNuitrack::_run_state = false;

    void gNuitrack::_register_methods () {
        register_method("init", &gNuitrack::init);
        register_method("update", &gNuitrack::update);
        register_method("create", &gNuitrack::create);
        register_method("run", &gNuitrack::run);

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

    bool gNuitrack::init(){ //godot::Variant config_values
        // initalise nuitrack library
        try {
            // initalize nuitrack
            tdv::nuitrack::Nuitrack::init();


            // REMOVE THIS HARD CODED FEATURE AND ALLOW USERS TO ADD THIS FROM GDSCRIPT 
            tdv::nuitrack::Nuitrack::setConfigValue("AstraProPerseeDepthProvider.RGB.Width","1280");
            tdv::nuitrack::Nuitrack::setConfigValue("AstraProPerseeDepthProvider.RGB.Height","720");
            tdv::nuitrack::Nuitrack::setConfigValue("AstraProPerseeDepthProvider.Depth.Width","640");
            tdv::nuitrack::Nuitrack::setConfigValue("AstraProPerseeDepthProvider.Depth.Height","480");
            tdv::nuitrack::Nuitrack::setConfigValue("Skeletonization.MaxDistance","4000");

            _init_state = true;
            return true; 
            
        } catch (const tdv::nuitrack::Exception& e) {
            _ERROR_PRINT("Failed to initalise Nuitrack");
            _init_state = false;
            return false;
        }

    }

    void gNuitrack::on_update_skeleton(tdv::nuitrack::SkeletonData::Ptr skeleton_data){
        _skeleton_data_ptr = skeleton_data;

        _num_skeletons = skeleton_data->getNumSkeletons();
        
        // wrap skeleton data and get joint position for TORSO



    };

    void gNuitrack::create(bool skeleton_tracker = false, bool user_tracker = false, bool color_sensor = false){
        if (skeleton_tracker == true){
            _skeleton_tracker_ptr = tdv::nuitrack::SkeletonTracker::create();
            _skeleton_tracker_ptr->connectOnUpdate([&](tdv::nuitrack::SkeletonData::Ptr userSkeleton){gNuitrack::on_update_skeleton(userSkeleton);}); // lambda expression, [&] means pass everything by reference
        }

        if (user_tracker == true) {
            _user_tracker_ptr = tdv::nuitrack::UserTracker::create();
        }

        if (color_sensor == true) {
            _color_sensor_ptr = tdv::nuitrack::ColorSensor::create();
        }
        
    }

    void gNuitrack::update(){
        tdv::nuitrack::Nuitrack::waitUpdate(_skeleton_tracker_ptr);
    }

    bool gNuitrack::run(){
        
        try {
            tdv::nuitrack::Nuitrack::run();
            _run_state = true;
            return true;

        } catch (const tdv::nuitrack::Exception& ) {
            _run_state = false;
            return false;
        }
    }
}
