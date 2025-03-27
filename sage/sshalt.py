import os
import time

last_thing = "empty"
while True:
    time.sleep(5)
    os.system("git pull")
    f = open("input", "r")
    inp = (f.read()) 
    inp = inp.strip()   
    if inp != last_thing:
        os.system(inp + " > output && git add . && git commit -m 'refresh' && git push")
        last_thing = inp
