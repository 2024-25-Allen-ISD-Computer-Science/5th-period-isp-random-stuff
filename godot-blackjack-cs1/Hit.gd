extends Sprite2D

var pts = 0

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass

func _on_texture_button_pressed():
	if ($"../Ace".value == "11"):
		var a = randi_range(2,11)
		pts += a
		$"../Label".text += "\n" + str(a)
	else:
		var a = randi_range(1,10)
		pts += a
		$"../Label".text += "\n" + str(a)
