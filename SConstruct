#!python
import os, subprocess

# Local dependency paths, adapt them to your setup
godot_headers_path = "godot-cpp/godot_headers"
cpp_bindings_path = "godot-cpp/"
cpp_bindings_library_path = "godot-cpp/bin/godot-cpp"
nuitracksdk_path = "libs/nuitrack-sdk/Nuitrack"
nuitrack_core_lib = "libnuitrack.so"
nuitrack_middleware_lib = "libmiddleware.so"
cpp_library = "godot-cpp"

# only support 64 bits linux at this time
target = ARGUMENTS.get("target", "debug")
platform = ARGUMENTS.get("platform", "linux")
bits = ARGUMENTS.get("bits", "64")


# some paths we'll be completing
nuitracksdk_lib = nuitracksdk_path
final_lib_path = "res/addons/"
target_name = 'libgdnuitrack'

env = Environment()

def add_sources(sources, directory):
    for file in os.listdir(directory):
        if file.endswith('.cpp'):
            sources.append(directory + '/' + file)

if platform == "linux":

    if ARGUMENTS.get("use_llvm", "no") == "yes":
        env["CXX"] = "clang++"

    env.Append(CCFLAGS=['-fPIC', '-g3', '-std=c++17'])
    env.Append(LINKFLAGS=["-Wl,-R,'$$ORIGIN'"])
    cpp_library += '.linux.debug.64.a'

    if target == 'debug':
        env.Append(CCFLAGS=['-Og'])
    elif target == 'release':
        env.Append(CCFLAGS=['-O3'])

    if bits == '64':
        env.Append(CCFLAGS=['-m64'])
        env.Append(LINKFLAGS=['-m64'])
        nuitracksdk_lib = nuitracksdk_lib + '/lib/linux64/'
    elif bits == '32':
        env.Append(CCFLAGS=['-m32'])
        env.Append(LINKFLAGS=['-m32'])
        nuitracksdk_lib = nuitracksdk_lib + '/lib/linux_arm/'



env.Append(CPPPATH = [
    '.',
    'src/',
    godot_headers_path,
    cpp_bindings_path + 'include/',
    cpp_bindings_path + 'include/core/',
    cpp_bindings_path + 'include/gen/',
    nuitracksdk_path + '/include/',
    nuitracksdk_path + '/include/middleware/',
    nuitracksdk_path + '/include/nuitrack'
])

env.Append(LIBPATH=[
    cpp_bindings_path + 'bin/',
    nuitracksdk_lib
])

env.Append(LIBS=[
    cpp_library,
    nuitrack_core_lib,
    nuitrack_middleware_lib
])

sources = []
add_sources(sources, "src")

library = env.SharedLibrary(target=final_lib_path + target_name, source=sources)
Default(library)
