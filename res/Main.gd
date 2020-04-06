extends Spatial


# Declare member variables here. Examples:
# var a = 2
# var b = "text"

var nuitrackdata

# Called when the node enters the scene tree for the first time.
func _ready():
	if Engine.has_singleton("gdNuitrack"):
		var singleton = Engine.get_singleton("gdNuitrack")
		var stringreturn = singleton.myFunction("World")
		$Label.text = "Data: " + stringreturn
		nuitrackdata = preload("res://addons/gNuitrack.gdns").new()
		$Label.text = "Data: YEEE" 
		$Label.text = "Data: " + str(nuitrackdata.test())
		
		

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass

func _physics_process(delta):
	pass
	#nuitrackdata.update();
	#$Label.text = "Num of Skeletons:  " + str(nuitrackdata.num_skeleton)
