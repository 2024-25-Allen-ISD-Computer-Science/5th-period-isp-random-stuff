import random
list2 = []
def convertToString(list1):
    newstring = ""
    for i in range(len(list1)):
        newstring = newstring + list1[i]
    return newstring
def convertToString1(list1):
    newstring = ""
    for i in range(len(list1)):
        newstring = newstring + str(list1[i]+1) + "-"
    return newstring
def generate(gn):
    for i in range(gn):
        number = random.randint(1,26)
        list2.append(number)
generate(int(input("how many letters: ")))
list3 = convertToString1(list2)[:-1]
print(list3)
ans = input("answer: \n")
ansList = list(ans)
alphabet = "abcdefghijklmnopqrstuvwxyz"
letterList = list(alphabet)
alistfull = []
for i in range(len(list2)):
    alistfull.append(letterList[list2[i]])
if (convertToString(alistfull) == ans):
    print("you win")
else:
    print("you lose: " + convertToString(alistfull))
