#ifndef GODOT_CPP_MULTIMESHINSTANCE_HPP
#define GODOT_CPP_MULTIMESHINSTANCE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "GeometryInstance.hpp"
namespace godot {

class MultiMesh;

class MultiMeshInstance : public GeometryInstance {
	struct ___method_bindings {
		godot_method_bind *mb_get_multimesh;
		godot_method_bind *mb_set_multimesh;
	};
	static ___method_bindings ___mb;

public:
	static void ___init_method_bindings();

	static inline const char *___get_class_name() { return (const char *) "MultiMeshInstance"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (o) ? (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o) : nullptr; }

	// enums

	// constants


	static MultiMeshInstance *_new();

	// methods
	Ref<MultiMesh> get_multimesh() const;
	void set_multimesh(const Ref<MultiMesh> multimesh);

};

}

#endif