"""
This program will give the user a total number of 10 tickets. The user will then input a desired number of tickets as long as the number of tickets
is no more than 4, no more than the total tickets they have left, and that the number is more than 0. The user can also press "Q" or "q" at any time
if they wish to exit the program. There are 3 different types of tickets: adult, child, student.

[A]dult = $10.50
[C]hild = $6.25
[S]tudent = $8.00

The program will continue to loop until the total number of tickets left reaches 0. There will be a confirmation after the user inputs the number of
tickets they wish to buy for each ticket type if they wish to confirm their purchase. It will show the number of total tickets the user has bought
as well as the number of times the user has confirmed their purchase. The total amount of money spent will also be displayed.
"""

totalTickets = 10

total_Buyers = 0
totalTicketsSold = 0

total_AdultFinal = 0
total_ChildFinal = 0
total_StudentFinal = 0
total_AdultFinalPrice = 0
total_ChildFinalPrice = 0
total_StudentFinalPrice = 0
total_PriceFinal = 0


while(totalTickets > 0):
    print("Tickets left:", totalTickets)

    while(True):
        ticket_input = int(input("\nHow many tickets? "))

        if (ticket_input > 4):  #makes sure input is greater than 4
            print("You can only buy a maximum of 4 tickets. ")
            continue
        elif (ticket_input > totalTickets):
            print("not enough tickets left.")
            continue
        elif (ticket_input <= 0):
            print("must be more than 0!")
            continue
        else:
            break

    ticket_Counter = 1  #counter to keep track of how many tickets the user wants to buy
    num_Adult = 0
    num_Child = 0
    num_Student = 0

    while(ticket_Counter <= ticket_input):
        ticket_type = input('Ticket {} ' "[A]dult, [C]hild, [Student]: ".format(ticket_Counter))

        if (ticket_type == 'a' or ticket_type == 'A'):
            num_Adult += 1
            ticket_Counter += 1
        elif (ticket_type == 'c' or ticket_type == 'C'):
            num_Child += 1
            ticket_Counter += 1
        elif (ticket_type == 's' or ticket_type == 'S'):
            num_Student += 1
            ticket_Counter += 1
        elif (ticket_type == 'q' or ticket_type == 'Q'):
            exit(1)
        else:
            print("enter valid ticket type.\n")
            continue

    #multiples the price of each ticket type by how many the user desires to buy
    total_Adult = num_Adult * 10.50
    total_Child = num_Child * 6.25
    total_Student = num_Student * 8.00
    final_Total = total_Adult + total_Child + total_Student

    print("\nPurchase Total:" )
    print(num_Adult, "Adult:", "{:10.2f}".format(float(total_Adult)))
    print(num_Child, "Children:", " {:6.2f}".format(float(total_Child)))
    print(num_Student, "Student:", "{:8.2f}".format(float(total_Student)))
    print("-------------------\n", "{:18.2f}".format(float(final_Total)))

    option = input("\b\nConfirm Purchase [Y]es [N]o: ")

    if (option == 'y' or option == 'Y'):
        totalTickets -= num_Adult + num_Child + num_Student
        total_Buyers += 1
        totalTicketsSold += num_Adult + num_Child + num_Student
        total_AdultFinal += num_Adult
        total_ChildFinal += num_Child
        total_StudentFinal += num_Student
        total_PriceFinal += final_Total
        total_AdultFinalPrice += total_Adult
        total_ChildFinalPrice += total_Child
        total_StudentFinalPrice += total_Student
        print("\n")
        continue
    elif (option == 'n' or option == 'N'):
        print("\n")
        continue
    else:
        break

if (totalTickets == 0 or totalTickets < 0):
    print(total_Buyers, " Total Buyers")
    print(totalTicketsSold, "Total Tickets Sold\n")
    print(total_AdultFinal, "Total Adults:", "{:9.2f}".format(float(total_AdultFinalPrice)))
    print(total_ChildFinal, "Total Children:", "{:7.2f}".format(float(total_ChildFinalPrice)))
    print(total_StudentFinal, "Total Students:", "{:7.2f}".format(float(total_StudentFinalPrice)))
    print("--------------------------\n", "{:24.2f}".format(float(total_PriceFinal)))
