#ifndef GDNUITRACK_HPP
#define GDNUITRACK_HPP

#include <Godot.hpp>
#include <Spatial.hpp>

// nuitrack library

namespace godot {
    class Nuitrack : public Spatial {
        GODOT_CLASS(Nuitrack, Node) //Macro for internal setup

        private:
        public:

        static void _register_methods();
        void _init(); //initialiser called by Godot
        ~Nuitrack();
    };
}

#endif