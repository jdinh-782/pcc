"""Johnson Dinh (Lab Week 2)

There are 2 parts in this lab where both will take some sort of user input and analyze it for results. For the first
part, the program will ask the user to keep entering an integer until the user enters a negative number (which
indicates to quit the program. The program will notify the user if the integer is odd or even, and at the end, the
program will output the total number of even integers inputted, the sum of those even integers, the total number of
odd integers as well as their respected sum. It will also show the total number of all integers inputted (except
negative numbers and non-integer numbers) as well as the total sum of all correct integer inputs.

For the second part, the user will be ask to input 2 numbers and an operation symbol for calculations. The loop will
continue until the user correctly inputs 2 numbers and an operation symbol. There will be error checking for wrong
inputs such as words, letters, and incorrect mathematical operation symbols. Also, the user can enter "Q" at any time
to quit the prorgam."""


#PART 1
counter = 0
even_int = 0
odd_int = 0
total_sumEven = 0
total_sumOdd = 0
total_numbers = 0
total_sum = 0

while(True):
    #ensures that user input is an integer, if not it will loop until an integer is inputted
    try:
        number = int(input("enter an integer (enter negative integer to quit): "))
    except:
        print("must be an integer\n")
        continue
    #checks for evens and odds as well as adding even and odd totals
    if (number % 2 == 0 and number >= 0):
        even_int += 1
        total_sumEven += number
        total_numbers += 1
    elif (number % 2 != 0 and number >= 0):
        odd_int += 1
        total_sumOdd += number
        total_numbers += 1
    if (number < 0):
        break
total_sum = total_sumEven + total_sumOdd

print("\nTotal even:", "%5s" % even_int,
      "\nSum even:", "%7s" % total_sumEven,
      "\nTotal odd:", "%6s" % odd_int,
      "\nSum odd:", "%8s" % total_sumOdd,
      "\n-----------------",
      "\nTotal entered:", "%2s" % total_numbers,
      "\nTotal sum:", "%6s" % total_sum)


#PART 2
print("enter 'Q' to quit ")

while(True):
    #ensures input is either a number or the letter "Q"
    try:
        num_1 = input("\nEnter first number: ")
        if num_1 == 'Q' or num_1 == 'q':
            break
        num_1 = float(num_1)
    except ValueError:
        print("must be a number: " + num_1.upper())
        continue
    try:
        num_2 = input("\nEnter second number: ")
        if num_2 == 'Q' or num_2 == 'q':
            break
        num_2 = float(num_2)
    except ValueError:
        print("must be a number: " + num_2.upper())
        continue
    operator = input("\nenter operator: ")
    if operator == 'Q' or operator == 'q':
        break
    #if-elif-else statements for what to do when a specific operator is inputted
    if (operator == '+'):
        result = num_1 + num_2
    elif (operator == '-'):
        result = num_1 - num_2
    elif (operator == '*'):
        result = num_1 * num_2
    elif (operator == '/'):
        if num_2 == 0:
            print("cannot divide by zero ")
            continue
        elif num_1 == 0 and num_2 == 0:
            result = num_1 / num_2
        else:
            result = num_1 / num_2
    else:
        print("invalid input ")
        continue
    print(num_1, operator, num_2, "=", result)
