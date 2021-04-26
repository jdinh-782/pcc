"""
Johnson Dinh

Lab 4 Part 1: This program asks the user to enter an integer of any sort so that the program can display the number of
integers (from 1-1000) that are divisible by the user input. The program will simply exit the program and not display
anything if the user enters anything besides an integer.
"""


def check_divisible(num):
    divisible_num = []

    #since the range is exclusive end, the ending number should be 1001
    for i in range(1, 1001):
        if i % num == 0:
            divisible_num.append(i)
        else:
            continue

    return divisible_num


if __name__ == '__main__':
    try:
        num = int(input("enter an integer: "))
        print(check_divisible(num))

    #if input is incorrect, simply exit program
    except ValueError:
        exit(0)
