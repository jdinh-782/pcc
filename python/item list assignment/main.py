"""
Name: Johnson Dinh

Assignment 4: This program will give the user 5 options to choose from. They will be allowed to (1) see their items in
              their list, (2) add an item of their choice, (3) remove an item of their choice, (4) search for an item
              in their list, and (5) quit the program if they desire to. Each choice will ensure their responsibilities
              by the use of checks whether they may be checking if an item is not in a list, or if there are no items
              in the list already. The user will also have the option to confirm whether they would like to add/remove
              a specific item.
"""

items = []


# display the entire menu for the user to choose an option
def display():
    print("\n\n[1] See items"
          "\n[2] Add items"
          "\n[3] Remove items"
          "\n[4] Search items"
          "\n[Q] Quit")

    selection = input("\nSelection: ").upper()

    if selection == 'Q':
        exit(0)

    else:
        selection = int(selection)

    return selection


# to display the items, if any
def see_items():
    if not items:
        print("No items in list.")

    else:
        for i in items:
            print(i)


# process of adding an item to the user's list
def add_items():
    add_item_input = input("\nEnter item: ").upper()

    while True:
        confirm = input(f"\nAdd {add_item_input} to list? ").upper()

        if confirm == 'Y':
            print(f"{add_item_input} added to the list!")
            items.append(add_item_input)
            break

        elif confirm == 'N':
            break

        else:
            print("Must be Y or N")
            continue


# removes an item based on user input (checks if their item input is in their list)
def remove_items():
    remove_item_input = input("\nItems to remove: ").upper()

    if remove_item_input not in items:
        print(f"{remove_item_input} not found! ")

    else:
        while True:
            confirm = input(f"\nRemove {remove_item_input}? ").upper()

            if confirm == 'Y':
                print(f"{remove_item_input} removed from list! ")
                items.remove(remove_item_input)
                break

            elif confirm == 'N':
                break

            else:
                print("Must be Y or N")
                continue


# search for items that are in the user's list
def search_items():
    item_input = input("\nEnter an item to search for: ").upper()

    if item_input not in items:
        print(f"{item_input} could not be found! ")

    else:
        for i in items:
            if item_input == i:
                print(f"{item_input} found at index {items.index(item_input)}! ")


if __name__ == '__main__':
    print("Welcome to the Grocery List Program")

    while True:
        option = display()

        if option == 1:
            see_items()

        elif option == 2:
            add_items()

        elif option == 3:
            remove_items()

        elif option == 4:
            search_items()

        else:
            exit(0)
