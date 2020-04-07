#ifndef GNUITRACK_HPP
#define GNUITRACK_HPP

#include <Godot.hpp>
#include <Spatial.hpp>
#include <Nuitrack.h>	
#include <vector>
#include <string>

namespace godot {
    class gNuitrack : public Spatial {
        GODOT_CLASS(gNuitrack, Node) //Macro for internal setup

        private:

        tdv::nuitrack::SkeletonTracker::Ptr _skeleton_tracker_ptr;
        tdv::nuitrack::SkeletonData::Ptr _skeleton_data_ptr;

        tdv::nuitrack::UserTracker::Ptr _user_tracker_ptr;
        tdv::nuitrack::ColorSensor::Ptr _color_sensor_ptr;

        int _num_skeletons;
        static bool _init_state; // this is only definition
        static bool _run_state;

        void on_update_skeleton(tdv::nuitrack::SkeletonData::Ptr skeleton_data); //obtain skeleton joint data here

        public:

        int get_num_skeletons() const;
        bool get_init_state() const;

        static void _register_methods();
        void _init(); //initialiser called by Godot
        ~gNuitrack();

        
        bool init();
        void update();
        void create(bool skeleton_tracker, bool user_tracker, bool color_sensor);
        bool run();
    };
}

#endif
