#ifndef GNUITRACK_HPP
#define GNUITRACK_HPP

#include <Godot.hpp>
#include <Spatial.hpp>

#include <Nuitrack.h>

namespace godot {
    class gNuitrack : public Spatial {
        GODOT_CLASS(gNuitrack, Node) //Macro for internal setup

        private:
        public:

        static void _register_methods();
        void _init(); //initialiser called by Godot
        ~gNuitrack();

        int test();
    };
}

#endif
