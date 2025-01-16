extends Sprite2D

var total = 0
var op = 0
var mon = 0

func _ready():
	$"../Label2".hide()
	# var file = FileAccess.open("user://money.txt", FileAccess.WRITE)
	# var money = ($"../Label/Label".bvalue)
	# file.store_var(float(money))
	# init money file
	#print("this: "+str(float("128")+10))

func _process(delta):
	# if total points > 21, check here, and then lose and if no lose then win
	total = $"../Hit".pts + $"../Card1".pts + $"../Card2".pts
	op = $"../Card3".pts + $"../Card4".pts
	# print("total"+str(total))
	# print("op"+str(op))
	if (total > 21):
		lose()
func _on_texture_button_pressed():
	# write money to file
	$"../Card3".frame = $"../Card3".f
	await get_tree().create_timer(1).timeout
	if (total > op):
		win()
	elif (total < op):
		lose()
	else:
		tie()

func win():
	$"../Label2".text = "You Win!"
	$"../Label2".show()
	var file = FileAccess.open("user://money.m", FileAccess.WRITE)
	file.store_float(float($"../Label/Label".bvalue)*2.0)
	$"../Label/Label".val2 = int($"../Label/Label".bvalue) * 2
	await get_tree().create_timer(2).timeout
	get_tree().reload_current_scene()
func lose():
	$"../Label2".text = "You Lose."
	$"../Label2".show()
	$"../Label/Label".val2 = 0
	await get_tree().create_timer(2).timeout
	get_tree().reload_current_scene()
func tie():
	$"../Label2".text = "You Tied."
	$"../Label2".show()
	var file = FileAccess.open("user://money.m", FileAccess.WRITE)
	file.store_float(float($"../Label/Label".bvalue))
	await get_tree().create_timer(2).timeout
	get_tree().reload_current_scene()
