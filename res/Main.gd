extends Spatial


# Declare member variables here. Examples:
# var a = 2
# var b = "text"

var nuitrack_helper_singleton
var nuitrack_helper_state

var nuitrack_api
var config_array

# Called when the node enters the scene tree for the first time.
func _ready():
	if Engine.has_singleton("gdNuitrack"):
		# Load Nuitrack.apk using custom java plugin
		nuitrack_helper_singleton = Engine.get_singleton("gdNuitrack")
		nuitrack_helper_state = nuitrack_helper_singleton.get_nuitrack_state()
		$nuitrack_apk_loader_state.text = "Nuitrack.apk init state ---" + str(nuitrack_helper_state)
		
		# Initalize nuitrack c++ api wrapper
		if nuitrack_helper_state == true:
			nuitrack_api = preload("res://addons/gNuitrack.gdns").new()
			config_array = [
							["AstraProPerseeDepthProvider.RGB.Width","640"],
							["AstraProPerseeDepthProvider.RGB.Height","480"],
							["Skeletonization.MaxDistance","4000"]
							]
	else:
		# Add failure log
		pass
		
		

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass

func _physics_process(delta):
	pass
