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
onready var nuitrack_run_state_label = get_node("nuitrack_run_state")
onready var nuitrack_num_skel_label = get_node("nuitrack_num_skeletons")

onready var run_state = false

# Called when the node enters the scene tree for the first time.
func _ready():

	if Engine.has_singleton("gdNuitrack"):
		# Load Nuitrack.apk using custom java plugin
		nuitrack_helper_singleton = Engine.get_singleton("gdNuitrack")
		nuitrack_helper_state = nuitrack_helper_singleton.get_nuitrack_state()
		nuitrack_apk_state_label.set_text("Nuitrack.apk init state --- " + str(nuitrack_helper_state))
		
		# Initalize nuitrack c++ api wrapper
		if nuitrack_helper_state == true:
			nuitrack_api = preload("res://addons/gNuitrack.gdns").new()
			var init_state = nuitrack_api.init(true);
			nuitrack_init_state_label.set_text("Nuitrack init() state --- " + str(init_state))
			
			if init_state == true:
				# Create skeleton tracker and run nuitrack
				nuitrack_api.create()
				run_state = nuitrack_api.run()
				if run_state == true:
					nuitrack_run_state_label.set_text("Nuitrack run() state --- " + str(run_state))
	else:
		# Add failure log
		pass
		
		

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):##
#	if run_state == true:
#		nuitrack_num_skel_label.set_text("Number of Skeletons:	" + str(nuitrack_api.num_skeleton))

func _physics_process(delta):
	if run_state == true:
		nuitrack_api.update()
		nuitrack_num_skel_label.set_text("Number of Skeletons:  " + str(nuitrack_api.num_skeleton))
