extends Spatial


# Declare member variables here. Examples:
# var a = 2
# var b = "text"
onready var data = preload("res://addons/nuitrack.gdns").new()

# Called when the node enters the scene tree for the first time.
func _ready():
	$Label.text = "Data = " + "waiting..."
	$Label.text = "Data = " + str(data.test())

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
