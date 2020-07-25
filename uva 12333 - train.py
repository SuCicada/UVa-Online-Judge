import re

error = 0
limit = 50

fullFile = open("out")
testFile = open("test1")
fullFile.readline()
fullFile.readline()
testFile.readline()
testFile.readline()
fullLine = fullFile.readline()
testLine = testFile.readline()
# while line:
# print(re.split("\D+", testLine))

# print(re.split("\D+", fullLine))

while fullLine and testLine:
    testList = re.split("\D+", testLine.strip())
    fullList = re.split("\D+", fullLine.strip())
    full = fullList[2]
    test = testList[1]
    index = testList[0]
    same = test[0:40] == full[0:40]
    # print(index, testList, fullList)
    if(not same):
        error += 1
    # else:
        print(index)
        quit()

    if(index == "99999"):
        quit()

    # if(index == "100"):
    print(index, same, error)
    fullLine = fullFile.readline()
    testLine = testFile.readline()

print(error)
