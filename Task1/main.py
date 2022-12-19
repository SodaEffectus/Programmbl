import time
import random

gist = [0] * 10
n = 1000000


def main():
    # for i in range(100):
    a = initListWithRandomNumbers()
    start_time = time.time_ns()
    calcSumm(a)
    end_time = time.time_ns()
    # time_work[i] = end_time - start_time
    # time_work.sort()
    print("Runtime of the calcSumm is ", end_time - start_time)
    print(gist)


def initListWithRandomNumbers():
    rand_list = []
    for i in range(n):
        rand_list.append(random.randint(0, 999))
    return rand_list


def calcSumm(arr):
    for i in range(n):
        gist[int(arr[i] / 100)] = gist[(arr[i] // 100)] + 1
    return gist


def histDistance(hist1, hist2) -> float:
    quadSumm = 0
    # print(hist1)
    # print(hist2)
    for i in range(10):
        quadSumm += (hist1[i] - hist2[i]) ** 2
    return quadSumm ** 0.5


def WriteInFile(hist1, hist2):
    f = open('hist.text', 'w')
    f.write(str(hist1) + '\n')
    f.write(str(hist2) + '\n')
    f.close()


def ReadFromFile():
    f = open('hist.text', 'r')
    print(f.readlines())
    f.close()


# main()

histogram1 = calcSumm(initListWithRandomNumbers())
histogram2 = calcSumm(initListWithRandomNumbers())
print("D =", histDistance(histogram1, histogram2))

WriteInFile(histogram1, histogram2)
ReadFromFile()
