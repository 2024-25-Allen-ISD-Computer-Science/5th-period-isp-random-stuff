extends Label

var value
var bvalue
var val2 = -1

func _ready():
	text="MONEY"

func _process(delta):
	bvalue = $"../../TextEdit".text
	if (text=="MONEY" && $"../../TextEdit".m ==122):
		text += (": " + str(bvalue))
	elif (val2 != -1):
		text = "MONEY: " + str(val2)
