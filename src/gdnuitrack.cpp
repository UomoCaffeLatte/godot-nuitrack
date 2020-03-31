#include "gdnuitrack.hpp"


namespace godot {
    void Nuitrack::_register_methods () {
        register_method("test", &Nuitrack::test);
    }

    void Nuitrack::_init(){

        JNIEnv *env = godot::android_api->godot_android_get_env();

        // get context
        jclass activityThread = env->FindClass("android/app/ActivityThread");
        jmethodID currentActivityThread = env->GetStaticMethodID(activityThread, "currentActivityThread", "()Landroid/app/ActivityThread;");
        jobject at = env->CallStaticObjectMethod(activityThread, currentActivityThread);
        jmethodID getApplication = env->GetMethodID(activityThread, "getApplication", "()Landroid/app/Application;");
        jobject context = env->CallObjectMethod(at, getApplication);

        // get nuitrack activity
        jclass activityThreadNuitrack = env->FindClass("com/tdv/nuitrack/sdk/Nuitrack");
        jmethodID nuitrack_init_method = env->GetStaticMethodID(activityThread, "init", "()Lcom/tdv/nuitrack/sdk/Nuitrack;");
        jenv->CallStaticMethod(activityThreadNuitrack, nuitrack_init_method, new );

    }

    Nuitrack::~Nuitrack(){
        // add cleanup here
    }

    int Nuitrack::test(){
        return 10;
    }
}