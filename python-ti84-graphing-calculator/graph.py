import pygame
import sys

eq = []

while True:
    eq.append(input("y = "))
    if eq[-1] == "graph":
        eq.remove("graph")
        break

pygame.init()
screenSize = 500
screen = pygame.display.set_mode((screenSize, screenSize))

def yy(y):
    return -y + screenSize

def px(x, y):
    screen.set_at((int(x), int(y)), (255, 255, 255))

def graph(i):
    yp = 0
    for x in range(screenSize):
        y = eval(eq[i])
        if (x == 0) or (int(yp) == int(y)):
            px(x, yy(y))
        else:
            if int(yp) < int(y):
                for w in range(int(yp + 1), int(y + 1)):
                    px(x, yy(w))
            elif int(yp) > int(y):
                for w in range(int(y), int(yp)):
                    px(x, yy(w))
        yp = y

while True:
    screen.fill((0, 0, 0))
    for i in range(len(eq)):
        graph(i)
    pygame.display.flip()

