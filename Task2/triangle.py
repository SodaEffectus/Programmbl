# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


def triangle(a):
    zv = 1
    for i in range(a+1):
        print(" " * a, end="")
        print("*" * zv)
        zv = zv + 2
        a = a - 1


if __name__ == '__main__':
    a = int(input())
    triangle(a)


