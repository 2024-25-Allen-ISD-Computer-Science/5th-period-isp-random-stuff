extends AnimatedSprite2D

var f = randi_range(0,51)
var pts = 0

func _ready():
	frame = 52
	print("frame: "+str(f))
	match(f):
		0,13,26,39:
			#pts += int($"../Ace".value)
			f = 2
			pts += 3
		1,14,27,40:
			pts += 2
		2,15,28,41:
			pts += 3
		3,16,29,42:
			pts += 4
		4,17,30,43:
			pts += 5
		5,18,31,44:
			pts += 6
		6,19,32,45:
			pts += 7
		7,20,33,46:
			pts += 8
		8,21,34,47:
			pts += 9
		9,10,11,12,22,23,24,25,35,36,37,38,48,49,50,51:
			pts += 10
	print(pts)


func _process(delta):
	pass
	#if ($"../Ace".timesPressed % 2 == 1):
		#pts += 10 
	#if (($"../Ace".timesPressed % 2 == 0) && ($"../Ace".timesPressed > 0)):
		#pts -= 10
