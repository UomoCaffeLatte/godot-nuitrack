#ifndef GDNUITRACK_HPP
#define GDNUITRACK_HPP

#include <Godot.hpp>
#include <godot_android.h>
#include <jni.h>
#include <Spatial.hpp>

#include <Nuitrack.h>


// nuitrack library

namespace godot {
    class Nuitrack : public Spatial {
        GODOT_CLASS(Nuitrack, Node) //Macro for internal setup

        private:
        public:

        static void _register_methods();
        void _init(); //initialiser called by Godot
        ~Nuitrack();

        int test();
    };
}

#endif