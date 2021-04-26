"""
Name: Johnson Dinh

Assignment 7: This program will act as a banking system where the user can add accounts, view accounts, check their
              accounts and make a deposit, withdrawal, or a transfer as well as removing an account. They will also be
              allowed to quit the program if they wish to do so by simply inputting 'Q' when prompted. When the user
              adds an account, they will be prompted to enter an account number and an initial balance. If the user
              enters an account number that is already in the database, they will be prompted to choose a different
              back account number. This program also ensures that deposits, withdrawals, and transfer are numeric
              inputs only as all non-negative. The user can also view all accounts in the bank or a specific account if
              they choose to do so.
"""

bank_accounts = dict()  # holds the bank accounts with each of their balances


# not sure what to do with this yet, but I still want to be able to fully test it out sometime
class Bank:
    def __init__(self, bank_account, balance=0.00):
        self.bank_account = bank_account
        self.balance = balance

    def get_bank_account(self):
        return self.bank_account


# intitiate a class for the bank accounts
class BankAccount:
    def __init__(self, account_number, balance=0.00):
        self.account_number = account_number
        self.balance = balance

    def get_balance(self):
        float(self.balance)
        return self.balance

    def withdraw_balance(self, account_number, amount):
        for key, value in bank_accounts.items():
            if key == account_number:
                balance = value.get_balance()

                if amount > balance:
                    print("Your withdrawal cannot exceed your balance! ")
                    return balance

                elif amount < 0:
                    print("Your withdrawal must be at least $0! ")
                    return balance

                else:
                    for key, value in bank_accounts.items():
                        if key == account_number:
                            balance -= amount
                            print(f"Your new balance is ${balance:>2.2f}!")
                    return balance

    def deposit_balance(self, account_number, amount):
        if amount < 0:
            print("Deposit must be at least $0! ")
            for key, value in bank_accounts.items():
                if key == account_number:
                    balance = value.get_balance()
                    return balance

        else:
            for key, value in bank_accounts.items():
                if key == account_number:
                    balance = value.get_balance()
                    balance += amount
                    print(f"Your new balance is ${balance:>2.2f}!")

                    return balance

    def transfer_balance(self, first_account_number, second_account_number, amount):
        for key, value in bank_accounts.items():
            if key == first_account_number:
                balance = value.get_balance()

                if amount > balance:
                    print("Your transfer amount cannot exceed your balance! ")
                    return balance

                elif amount < 0:
                    print("Your transfer amount must be at least $0! ")
                    return balance

                else:
                    for key, value in bank_accounts.items():
                        if key == first_account_number:
                            balance -= amount
                            print(f"You successfully transferred ${amount:>2.2f}!")

                    return balance

            elif key == second_account_number:
                balance = value.get_balance()

                if amount > balance:
                    return balance

                elif amount < 0:
                    return balance

                else:
                    for key, value in bank_accounts.items():
                        if key == second_account_number:
                            balance += amount

                    return balance

    def view_account(self, account_number):
        if account_number in bank_accounts:
            for key, value in bank_accounts.items():
                if key == account_number:
                    returned_balance = value.get_balance()
                    print(key, returned_balance, sep=" : $")

        else:
            print("Could not find that account! ")

    def remove_account(self, account_number):
        if account_number in bank_accounts:
            bank_accounts.pop(account_number)

            print(f"\nAccount '{account_number}' successfully removed! ")

        else:
            print("Could not find account! ")


if __name__ == "__main__":
    while True:
        # display menu
        print("\n[A] Add Account\n"
              "[V] View All\n"
              "[C] Check Account\n"
              "[R] Remove Account\n"
              "[Q] Quit")

        choice = input("Selection: ").upper()

        if choice == 'Q':
            exit(0)

        elif choice == 'A':
            account_number = input("\nEnter your account number: ").upper()

            while True:
                balance = float(input("Enter your balance: "))

                if balance < 0:
                    print("\nYour balance can't be negative! ")

                else:
                    break

            # create an initial account
            get_account = Bank(account_number, balance)

            account = BankAccount(account_number, balance)

            if account_number in bank_accounts:
                print("This account number is already used! ")

            else:
                # if account number is unused, simply add the account to the dictionary
                bank_accounts[account_number] = account

        elif choice == 'V':
            print("\n[1] All Accounts \n[2] Specific Account")
            selection = int(input("Selection: "))

            # view all the accounts in the database
            if selection == 1:
                for key, value in bank_accounts.items():
                    # returned_value = value.get_balance()
                    print(key, value.get_balance(), sep=" : $")

            # view a specific account number with its balance
            elif selection == 2:
                account_number = input("Enter the account number to search "
                                       "for: ").upper()

                find_account = BankAccount(account_number, 0.00)

                find_account.view_account(account_number)

        elif choice == 'C':
            account_number = input("Enter your account number: ").upper()

            if account_number not in bank_accounts:
                print("Account is not in database! ")

            else:
                print("\n[1] Deposit"
                      "\n[2] Withdraw"
                      "\n[3] Transfer")

                choice = int(input("Choice: "))

                action = BankAccount(account_number, 0.00)

                if choice == 1:
                    # try-catch to see whether the input is a numerical value
                    try:
                        deposit = float(input("Enter deposit amount: "))

                    except ValueError:
                        print("Must be a numerical input! ")
                        continue

                    new_balance = action.deposit_balance(account_number, deposit)

                    updated_account = BankAccount(account_number, new_balance)

                    bank_accounts[account_number] = updated_account

                elif choice == 2:
                    try:
                        withdrawal = float(input("Enter withdrawal amount: "))

                    except ValueError:
                        print("Must be a numerical input! ")
                        continue

                    new_balance = action.withdraw_balance(account_number, withdrawal)

                    updated_account = BankAccount(account_number, new_balance)

                    bank_accounts[account_number] = updated_account

                elif choice == 3:
                    first_account_number = input("Enter the account number you want to transfer funds from: ")

                    second_account_number = input("Enter the account number you wish to transfer funds to: ").upper()

                    if first_account_number not in bank_accounts or second_account_number not in bank_accounts:
                        print("One or more accounts not in database! ")

                    else:
                        try:
                            transfer_amount = float(input("\nEnter the amount you wish to transfer: "))

                        except ValueError:
                            print("Must be a numerical input! ")
                            continue

                        first_updated_balance = action.transfer_balance(first_account_number, None, transfer_amount)

                        first_updated_account = BankAccount(first_account_number, first_updated_balance)

                        bank_accounts[first_account_number] = first_updated_account

                        second_updated_balance = action.transfer_balance(None, second_account_number, transfer_amount)

                        second_updated_account = BankAccount(second_account_number, second_updated_balance)

                        bank_accounts[second_account_number] = second_updated_account

        elif choice == 'R':
            account_number = input("Enter the account number you wish to have removed: ").upper()

            decision = input("Are you sure you wish to remove? (y/n) ").upper()

            if decision == 'Y':
                remove_account = BankAccount(account_number, 0.00)

                remove_account.remove_account(account_number)

            else:
                continue
