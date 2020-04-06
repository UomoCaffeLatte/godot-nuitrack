#ifndef GNUITRACK_HPP
#define GNUITRACK_HPP

#include <Godot.hpp>
#include <Spatial.hpp>
#include <Nuitrack.h>

namespace godot {
    class gNuitrack : public Spatial {
        GODOT_CLASS(gNuitrack, Node) //Macro for internal setup

        private:

        tdv::nuitrack::SkeletonTracker::Ptr _skeleton_tracker_ptr;
        tdv::nuitrack::SkeletonData::Ptr _skeleton_data_ptr;

        int _num_skeletons;

        int get_num_skeletons() const;

        public:

        static void _register_methods();
        void _init(); //initialiser called by Godot
        ~gNuitrack();

        int test();
        void on_update_skeleton(tdv::nuitrack::SkeletonData::Ptr skeleton_data); //obtain skeleton joint data here
        void update();
    };
}

#endif
