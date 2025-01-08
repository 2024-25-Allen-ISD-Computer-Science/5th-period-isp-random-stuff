extends Sprite2D

var value = "1"
var timesPressed = 0

# Called when the node enters the scene tree for the first time.
func _ready():
	pass


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	$Label.text = ("("+value+")")

func _on_texture_button_pressed():
	if (value == "1"):
		value = "11"
	elif(value == "11"):
		value = "1"
