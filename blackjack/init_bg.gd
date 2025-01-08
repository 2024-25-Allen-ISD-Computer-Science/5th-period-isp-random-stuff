extends ColorRect

func _ready():
	position = Vector2.ZERO
	size = Vector2(get_viewport_rect().size.x*2, get_viewport_rect().size.y*2)
	

func _process(delta):
	pass
