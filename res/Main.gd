extends Spatial


# Declare member variables here. Examples:
# var a = 2
# var b = "text"

var nuitrack_helper_singleton
var nuitrack_helper_state

var nuitrack_api
var config_array

onready var nuitrack_apk_state_label = get_node("nuitrack_apk_loader_state")
onready var nuitrack_init_state_label = get_node("nuitrack_init_state")

# Called when the node enters the scene tree for the first time.
func _ready():

	if Engine.has_singleton("gdNuitrack"):
		# Load Nuitrack.apk using custom java plugin
		nuitrack_helper_singleton = Engine.get_singleton("gdNuitrack")
		nuitrack_helper_state = nuitrack_helper_singleton.get_nuitrack_state()
		nuitrack_apk_state_label.set_text("Nuitrack.apk init state ---" + str(nuitrack_helper_state))
		
		# Initalize nuitrack c++ api wrapper
		if nuitrack_helper_state == true:
			nuitrack_init_state_label.set_text("Nuitrack init() state ---" + "executing...")
			nuitrack_api = preload("res://addons/gNuitrack.gdns").new()
			nuitrack_init_state_label.set_text("Nuitrack init() state ---" + "found nuitrack api")
			var return_state = nuitrack_api.init();
			nuitrack_init_state_label.set_text("Nuitrack init() state ---" + str(return_state))
			
		#	config_array = [
		#					["AstraProPerseeDepthProvider.RGB.Width","640"],
		#					["AstraProPerseeDepthProvider.RGB.Height","480"],
		#					["Skeletonization.MaxDistance","4000"]
			#				]
	else:
		# Add failure log
		pass
		
		

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass

func _physics_process(delta):
	pass
