#include "gNuitrack.hpp"

namespace godot {

    int gNuitrack::get_num_skeletons() const { // const restricts class to only reading of class variables
        return gNuitrack::_num_skeletons;
    };

    bool gNuitrack::get_init_state() const {
        return gNuitrack::_init_state;
    }

}