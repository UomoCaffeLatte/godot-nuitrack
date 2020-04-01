#!python
import os
import sys
import subprocess

# Local dependency paths, adapt them to your setup
godot_cpp_headers_path = "godot-cpp/godot_headers"
godot_cpp_bindings_path = "godot-cpp/"
godto_cpp_lib = "libgodot-cpp.android.debug.armv7.a"

nuitrack_sdk_path = "libs/nuitrack-sdk/Nuitrack"
nuitrack_sdk_core_lib = "libnuitrack.so"
nuitrack_sdk_middleware_lib = "libmiddleware.so"
nuitrack_sdk_openi_lib = "libOpenNI.so"
nuitrack_sdk_lib_path = nuitrack_sdk_path + "/lib/android/"

android_ndk_path = "libs/android-ndk/"
final_lib_path = "res/addons/"

def add_sources(sources, directory, extension):
    for file in os.listdir(directory):
        if file.endswith('.' + extension):
            sources.append(directory + '/' + file)

env = Environment(ENV = os.environ)
    
# support only android armv7
# setup toolchain
api_level = "18"
toolchain = android_ndk_path + "/toolchains/llvm/prebuilt/linux-x86_64"

env.PrependENVPath('PATH', toolchain + "/bin") # This does nothing half of the time, but we'll put it here anyways

arch = "armv7"
arch_march = "armv7-a"
arch_target = "armv7a-linux-androideabi"
arch_tool_path = "arm-linux-androideabi"
arch_compiler_path = "armv7a-linux-androideabi"
arch_ccflags = "-mfpu=neon"

## setup tools
env['CXX'] = toolchain + "/bin/armv7a-linux-androideabi16-clang++" #c++

env.Append(CCFLAGS=[
    #'--target=' + arch_target + api_level,
    '-march=' +arch_march,
    '-fPIC'
])
env.Append(CCFLAGS=arch_ccflags)

#env.Append(LINKFLAGS=["-Wl,-R,'$$ORIGIN'"])

env.Append(CPPPATH = [
    '.',
    'src/',
    godot_cpp_headers_path,
    godot_cpp_bindings_path + 'include/',
    godot_cpp_bindings_path + 'include/core/',
    godot_cpp_bindings_path + 'include/gen/',
    godot_cpp_bindings_path + 'godot_headers/',
    godot_cpp_bindings_path + 'godot_headers/android/',
    nuitrack_sdk_path + '/include/',
    nuitrack_sdk_path + '/include/middleware/',
    nuitrack_sdk_path + '/include/nuitrack'
])

env.Append(LIBPATH=[
    godot_cpp_bindings_path + 'bin/',
    nuitrack_sdk_lib_path
])

env.Append(LIBS=[
    godto_cpp_lib,
    nuitrack_sdk_core_lib,
    nuitrack_sdk_middleware_lib,
    nuitrack_sdk_openi_lib
])

env.Append(CPPPATH=['src/'])
sources = []
add_sources(sources, "src", 'cpp')

library = env.SharedLibrary(target=final_lib_path + "libgdnuitrack", source=sources)
Default(library)
