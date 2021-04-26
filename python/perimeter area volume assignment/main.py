"""
Name: Johnson Dinh

Assignment Week 3: This program asks the user to choose a shape of their choice and then calculate either the perimeter, area, or the volume. The user
is also able to quit the program at any time, however, if the user decides to "quit" during the equation menu, they will be prompted back to the shape
menu. If a user selects either a square, rectangle, triangle, or a circle, they will be given the option to either calculate the perimeter or the area.
The user will choose an option and then input a numerical value of their choice, all while error checking is enabled. If the user decides to choose
either a cube or a sphere, the user will be allowed to calculate the volume instead. The program will then display the result to the screen and then
loop back to the shape menu, all until the user enters 'Q' to quit (assuming the user is never in the equation menu).
"""

import math

def menu():
    print("\nSelect a shape:\n"
          "[1] Square\n"
          "[2] Rectangle\n"
          "[3] Triangle\n"
          "[4] Circle\n"
          "[5] Cube\n"
          "[6] Sphere\n"
          "[Q] Quit")


def select_shape():
    while True:
        selection = input("\nSelection: ").upper()

        if selection == "1" or selection == "2" or selection == "3" or selection == "4" or selection == "5" or selection == "6":
            break

        elif selection == "Q":
            exit(0)

        else:
            print("invalid input, enter again...")
            continue

        selection = int(selection)

    return selection



def sub_menu(selection):

    if selection >= 1 and selection <= 4:
        print("\n[P] Perimeter"
              "\n[A] Area"
              "\n[Q] Quit")


    elif selection == 5 or selection == 6:
        print("\n[V] Volume"
              "\n[Q] Quit")


def select_equation(selection):

    while True:
        if selection >= 1 and selection <= 4:
            option = input("\nSelection: ").upper()

            if option == "Q":
                break

            elif option == "P" or option == "A":
                break

            else:
                print("invalid selection, enter again...")
                continue


        elif selection == 5 or selection == 6:
            option = input("\nSelection: ").upper()

            if option == "Q":
                break

            elif option == "V":
                break

            else:
                print("invalid selection, enter again...")
                continue

    return option


def equation_selector(selection, sub_selection):
    while True:
        #square
        if (selection == 1):
            print("\nenter a side: ")
            side = checkValidity(0, 1)

            if (sub_selection == "P"):

                perimeterSquare = side * 4

                print(f"\nSquare Perimeter: {perimeterSquare:>2.2f} units")
                break

            elif (sub_selection == "A"):

                areaSquare = side * side

                print(f"\nArea Perimeter: {areaSquare:>2.2f} units squared")
                break

        #rectangle
        elif (selection == 2):
            print("\nenter the length: ")
            length = checkValidity(0, 1)

            print("\nenter the width: ")
            width = checkValidity(0, 1)

            if (sub_selection == "P"):

                perimeterRectangle = 2 * (length + width)

                print(f"\nPerimeter Rectangle: {perimeterRectangle:>2.2f} units")
                break

            elif (sub_selection == "A"):

                areaRectangle = length * width

                print(f"\nArea Rectangle: {areaRectangle:>2.2f} units squared")
                break

        #triangle
        elif (selection == 3):
            if (sub_selection == "P"):
                print("\nenter side 1: ")
                side1 = checkValidity(0, 1)

                print("\nenter side 2: ")
                side2 = checkValidity(0, 1)

                print("\nenter side 3: ")
                side3 = checkValidity(0, 1)

                perimeterTriangle = side1 + side2 + side3

                print(f"\nPerimeter Triangle: {perimeterTriangle:>2.2f} units")
                break

            elif (sub_selection == "A"):
                print("\nenter a base: ")
                base = checkValidity(0, 1)

                print("\nenter a height: ")
                height = checkValidity(0, 1)

                areaTriangle = 0.5 * (base * height)

                print(f"\nArea Triangle: {areaTriangle:>2.2f} units squared")
                break

        #circle
        elif (selection == 4):
            print("\nenter a radius: ")
            radius = checkValidity(0, 1)

            if (sub_selection == "P"):
                perimeterCircle = 2 * (math.pi) * radius

                print(f"\nPerimeter Circle: {perimeterCircle:>2.2f} units")
                break

            elif (sub_selection == "A"):
                areaCircle = (math.pi) * (radius * radius)

                print(f"\nArea Triangle: {areaCircle:>2.2f} units squared")
                break

        #cube
        elif (selection == 5):
            print("\nenter a side: ")
            edge = checkValidity(0, 1)

            volumeCube = edge * edge * edge

            print(f"\nVolume Cube: {volumeCube:>2.2f} units cubed")
            break

        #sphere
        elif (selection == 6):
            print("\nenter a radius: ")
            radius = checkValidity(0, 1)

            volumeSphere = (4/3) * (math.pi) * (radius * radius * radius)

            print(f"\nVolume Sphere: {volumeSphere:>2.2f} units cubed")
            break



def checkValidity(i, counter):
    while i < counter:

        try:
            side = int(input())

        except ValueError:
            print("\ninvalid input, enter again...")
            continue

        if (side <= 0):
            print("\nmust be greater than 0...")
            continue

        else:
            i += 1
            return side





if __name__ == '__main__':
    while True:
        menu()
        selection = select_shape()

        selection = int(selection)

        sub_menu(selection)

        sub_selection = select_equation(selection)

        if sub_selection == "Q":
            continue

        equation_selector(selection, sub_selection)

print("\nExiting...")

