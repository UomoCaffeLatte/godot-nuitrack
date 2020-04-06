#include "gNuitrack.hpp"


namespace godot {
    void gNuitrack::_register_methods () {
        register_method("test", &gNuitrack::test);
        register_method("update", &gNuitrack::update);

        register_property<gNuitrack, int>("num_skeleton", nullptr, &gNuitrack::get_num_skeletons, 0);
    }

    void gNuitrack::_init(){
    }

    int gNuitrack::get_num_skeletons() const {
        return _num_skeletons;
    };

    gNuitrack::~gNuitrack(){
        // add cleanup here
        tdv::nuitrack::Nuitrack::release();
    }

    int gNuitrack::test(){

        int returnno = 10;

        tdv::nuitrack::Nuitrack::init();

        _skeleton_tracker_ptr = tdv::nuitrack::SkeletonTracker::create();

		// link on update method to skeleton tracker
		_skeleton_tracker_ptr->connectOnUpdate([&](tdv::nuitrack::SkeletonData::Ptr userSkeleton){gNuitrack::on_update_skeleton(userSkeleton);}); // lambda expression, [&] means pass everything by reference
        
        try{
            tdv::nuitrack::Nuitrack::run();
            returnno = 12;
        } catch (const tdv::nuitrack::Exception& e) {
            returnno = 15;
        }
        return returnno;
    }

    void gNuitrack::on_update_skeleton(tdv::nuitrack::SkeletonData::Ptr skeleton_data){
        _skeleton_data_ptr = skeleton_data;
        _num_skeletons = skeleton_data->getNumSkeletons();
    };

    void gNuitrack::update(){
        tdv::nuitrack::Nuitrack::waitUpdate(_skeleton_tracker_ptr);
    }

}
