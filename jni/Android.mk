
LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

MY_DIR_PATH = $(LOCAL_PATH)/..
NUITRACK_INCLUDE_PATH = $(MY_DIR_PATH)/libs/nuitrack-sdk/Nuitrack/include
NUITRACK_LIBRARY_PATH = $(MY_DIR_PATH)/libs/nuitrack-sdk/Nuitrack/lib/android
GODOT_CPP_LIBRARY_PATH = $(MY_DIR_PATH)/godot-cpp/bin

LOCAL_MODULE := libgdnuitrack
LOCAL_CPPFLAGS := -std=c++14 -mfpu=neon
#-target=armv7a-linux-androideabi18

LOCAL_CPP_FEATURES := rtti exceptions 
LOCAL_LDLIBS := -L$(NUITRACK_LIBRARY_PATH) -L$(GODOT_CPP_LIBRARY_PATH) -llog -landroid -lgodot-cpp.android.debug.armv7 #-lnuitrack -lmiddleware -lOpenNI
LOCAL_SRC_FILES := gdlibrary.cpp \
gNuitrack.cpp 

#LOCAL_C_INCLUDES := $(MY_DIR_PATH)/libs/nuitrack-sdk/Nuitrack/include
#LOCAL_C_INCLUDES += $(MY_DIR_PATH)/libs/nuitrack-sdk/Nuitrack/include/nuitrack
#LOCAL_C_INCLUDES += $(MY_DIR_PATH)/libs/nuitrack-sdk/Nuitrack/include/middleware
LOCAL_C_INCLUDES += $(MY_DIR_PATH)/godot-cpp/godot_headers
LOCAL_C_INCLUDES += $(MY_DIR_PATH)/godot-cpp/godot_headers\android
LOCAL_C_INCLUDES += $(MY_DIR_PATH)/godot-cpp/include/core
LOCAL_C_INCLUDES += $(MY_DIR_PATH)/godot-cpp/include/gen
LOCAL_C_INCLUDES += $(MY_DIR_PATH)/godot-cpp/include


include $(BUILD_SHARED_LIBRARY)
