import time
from pynput.mouse import Button, Controller
import threading
import keyboard

mouse = Controller()
clickclock = 0.05
clickbool = False
clicktt = None

def onstart():
    clickCC = 0
    while clickbool:
        mouse.click(Button.left)
        clickCC += 1
        time.sleep(clickclock)

def cltog():
    global clickbool, clicktt
    if clickbool:
        clickbool = False
        if clicktt is not None:
            clicktt.join()
        print("stopped")
    else:
        clickbool = True
        clicktt = threading.Thread(target=onstart)
        clicktt.daemon = True
        clicktt.start()
        print("start")

def keybm():
    while True:
        if keyboard.is_pressed('f'):
            cltog()
            time.sleep(0.2) 
        if keyboard.is_pressed('esc'):
            stop_clicking()
            print("bye")
            break
keybm()
