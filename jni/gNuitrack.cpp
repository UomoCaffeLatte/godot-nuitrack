#include "gNuitrack.hpp"


namespace godot {
    void gNuitrack::_register_methods () {
        register_method("test", &gNuitrack::test);
    }

    void gNuitrack::_init(){

        //tdv::nuitrack::Nuitrack::init();

    }

    gNuitrack::~gNuitrack(){
        // add cleanup here
    }

    int gNuitrack::test(){
        return 10;
    }
}
