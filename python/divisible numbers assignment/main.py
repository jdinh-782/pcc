"""
Johnson Dinh

Lab 4 Part 3: This program will ask the user to enter an integer of their choice so that the program will display the list of integers
that are divisible by the integer input. However, the range will be determined by the user as the program will ask the user to enter
a start and end integer for the range. All numbers that are divisible by the integer input and that are in the range will be displayed.
If the user enters anything besides a number, the program will exit and nothing will be displayed.
"""


def check_divisible(num1, num2 = 1, num3 = 1000):
    divisible_num = []

    for i in range(num2, num3+1):
        if i % num1 == 0:
            divisible_num.append(i)
        else:
            continue

    return divisible_num


def check_divisible_range(num1, num2, num3):
    divisible_num_v3 = []

    #add 1 to the ending range so that the list can include all possible values up until the point the user wants to stop at
    for i in range(num2, num3+1):
        if i % num1 == 0:
            divisible_num_v3.append(i)
        else:
            continue

    return divisible_num_v3


if __name__ == '__main__':
    try:
        num = int(input("enter an integer: "))
        rangeStart = int(input("enter a starter integer for your range: "))
        rangeFinish = int(input("enter an ending integer for your range: "))
        print(check_divisible_range(num, rangeStart, rangeFinish))

    except ValueError:
        exit(0)

    try:
        num = int(input("\nenter an integer: "))
        rangeStart = int(input("enter a starter integer for your range: "))
        rangeFinish = int(input("enter an ending integer for your range: "))
        print(check_divisible(num, rangeStart, rangeFinish))

    except ValueError:
        exit(0)