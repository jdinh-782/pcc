"""
Name: Johnson Dinh
Lab Week 08: This program will act as a a dog walker program that will feature 4 different classes: 1 for a person, 1
             for a dog walker (inherited from person), 1 for a customer (inherited from person), and 1 for a dog. The
             person class will take in the name, id number, and the list of dogs for reference. The dog walker class
             will simply take in the attributes given in the person class as well as creating an hourly rate attribute.
             The customer class will show how much an amount is owed after the dog walker walks the dog. The dog class
             will simply take in the name, breed, weight, and the hours walked of the dog(s).
"""

records = dict()  # holds a record of names, id numbers, and number of dogs
dog_names = []


class Person:
    def __init__(self, name, id_number, dogs=0):
        self.name = name
        self.id_number = id_number
        self.dogs = dogs

    def get_name(self):
        return self.name

    def get_id_number(self):
        return self.id_number

    def get_dogs(self):
        return self.dogs

    def display(self):
        print(self.name)
        print(self.id_number)
        print(self.dogs)


class DogWalker(Person):
    def __init__(self, name, id_number, dogs, rate=0.00):
        Person.__init__(self, name, id_number, dogs)
        self.rate = rate

    def get_name(self):
        return self.name

    def get_rate(self):
        return self.rate

    def display(self):
        print(f"{self.rate:>.2f}")


class Customer(Person):
    def __init__(self, name, id_number, dogs, amount_owed=0.00):
        Person.__init__(self, name, id_number, dogs)
        self.amount_owed = amount_owed

    def get_amount_owed(self):
        return self.amount_owed


class Dog:
    def __init__(self, name, breed, weight=0.00):
        self.name = name
        self.breed = breed
        self.weight = weight

    def get_name(self):
        return self.name

    def get_breed(self):
        return self.breed

    def get_weight(self):
        return self.weight

    def get_hours_walked(self, hours_walked):
        self.hours_walked = hours_walked
        return self.hours_walked


if __name__ == "__main__":
    name_input = input("Enter your name: ")
    id_number_input = input("Enter your id number: ")

    while True:
        # global dogs_input
        global num_dogs

        # implement a try-catch to see if input is correct
        try:
            num_dogs = int(input("Enter the number of dogs you have: "))

            if num_dogs <= 0:
                print("Must be greater than 0!\n")
                continue

            else:
                print("")
                record = Person(name_input, id_number_input, num_dogs)
                records[name_input] = record
                break

        except ValueError:
            print("Must be an integer!\n")
            continue

    # simply for display purposes
    for key, value in records.items():
        print(key, value.get_id_number(), value.get_dogs(), sep=", ")

    dog_walker = DogWalker('Johnson', id_number_input, num_dogs, 20.50)
    dog_walker_name = dog_walker.name
    hourly_rate = dog_walker.rate

    print(f"\nThe rate is ${hourly_rate:>.2f} for each hour we walk your dog(s).")

    while True:
        global num_hours
        try:
            num_hours = int(input("Enter the number of hours you would like our dog walker to walk your dog(s) for: "))

            if num_hours <= 0:
                print("Must be greater than 0!\n")
                continue

            else:
                break

        except ValueError:
            print("\nPlease enter a whole number! ")
            continue

    customer = Customer(name_input, id_number_input, num_dogs, hourly_rate)
    total_cost = customer.amount_owed * num_hours

    print(f"\nYour total is ${total_cost:>.2f}.")

    print(f"\nIn order for our employee '{dog_walker_name}' to walk your dog(s), you must confirm this total first.")

    while True:
        confirm = input("Enter 'YES' to confirm purchase: ").upper()

        if confirm == 'YES':
            break

        elif confirm == 'NO':
            print("\nSee you next time! ")
            exit(1)

        else:
            print("\nInvalid response! ")
            exit(1)

    confirmation = 'NO'

    # globalized so that the variable can be used outside of local scopes
    global doggo

    while confirmation != 'YES':
        print("\nYou will now enter the name, breed, and weight for your dog(s).\n\n")
        dog_characteristics = dict()
        dog_names = []
        for i in range(0, num_dogs):
            dog_name = input(f"Enter dog name for dog {i+1}: ")
            dog_breed = input(f"Enter dog breed for dog {i+1}: ")
            dog_names.append(dog_name)

            while True:
                global dog_weight

                try:
                    dog_weight = float(input(f"Enter dog weight (in lbs) for dog {i+1}: "))

                    if dog_weight <= 0:
                        print("\nMust be greater than 0! ")
                        continue

                    else:
                        break

                except ValueError:
                    print("\nMust be a number! ")
                    continue

            print("")

            doggo = Dog(dog_name, dog_breed, dog_weight)
            dog_characteristics[dog_name] = doggo

        for key, value in dog_characteristics.items():
            print(key, value.get_breed(), value.get_weight(), sep=", ")

        confirmation = input("\nEnter 'YES' if these characteristics are correct: ").upper()

        if confirmation == 'YES':
            break

        else:
            continue

    input(f"\n\nAll right! Everything is now set, and '{dog_walker_name}' will begin to walk your dog(s): {dog_names} ")

    total_hours_walked = doggo.get_hours_walked(num_hours)

    print(f"\nHey '{name_input}'! '{dog_walker_name}' has finished walking your dog(s): {dog_names} for "
          f"{total_hours_walked} hours! ")
    print("Thank you for choosing our service! Come again!")
