"""
Name: Johnson Dinh
Lab Week 11: This program is designed to interact with the features built in tkinter to produce a calculator-based
             program. The GUI is simply a holder for the calculator with its necessary buttons to insert numbers and
             perform a specific operation.
"""

import tkinter as tk
import functools


class Calculator:
    def __init__(self):
        self._numbers = None
        self._operation = None
        self._result = None

        self.clear_numbers()

    def update_number(self, number, update_reason):
        # update reason: +, *, /, -
        self._numbers.append(number)
        self._operation = update_reason

    def equal_operation(self, number):
        if operation == "addition":
            self._result = self._numbers[-1] + number

        elif operation == "subtraction":
            self._result = self._numbers[-1] - number

        elif operation == "multiplication":
            self._result = self._numbers[-1] * number

        elif operation == "division":
            self._result = self._numbers[-1] / number

    def get_result(self):
        return self._result

    def clear_numbers(self):
        self._numbers = [0]
        self._result = 0


class CalculatorGUI:
    def __init__(self, root):
        self._backend = Calculator()
        root.title("Calculator")

        # the entry, where the numbers will appear
        self._entry = tk.Entry(root, width=40, borderwidth=5)
        self._entry.grid(row=0, column=0, columnspan=3, padx=10, pady=10)

        # buttons
        self._buttons = dict()
        buttons = list(range(0, 10, 1))
        buttons.extend(["+", "-", "*", "/", "=", "+/-", ".", "Clear"])

        # print(buttons)
        for i in buttons:
            if i in range(0, 10, 1):
                buttons[i] = tk.Button(root, text=i, padx=40, pady=20, command=functools.partial(self.button_number, i))
        buttons[10] = tk.Button(root, text="+", padx=40, pady=20, command=self.addition)  # addition
        buttons[11] = tk.Button(root, text="-", padx=40, pady=20, command=self.subtraction)  # subtraction
        buttons[12] = tk.Button(root, text="*", padx=40, pady=20, command=self.multiplication)  # multiplication
        buttons[13] = tk.Button(root, text="/", padx=40, pady=20, command=self.division)  # division
        buttons[14] = tk.Button(root, text="=", padx=40, pady=20, command=self.button_equal)  # equal
        buttons[15] = tk.Button(root, text="+/-", padx=40, pady=20, command=None)  # plus/minus
        buttons[16] = tk.Button(root, text=".", padx=40, pady=20, command=None)  # plus/minus

        columns = 0
        rows = 5
        for i in range(0, 10):
            buttons[i].grid(row=rows, column=columns)
            columns += 1
            if i % 3 == 0:
                rows -= 1
                columns = 0
        buttons[10].grid(row=5, column=1)
        buttons[11].grid(row=5, column=2)
        buttons[12].grid(row=6, column=0)
        buttons[13].grid(row=6, column=1)
        buttons[14].grid(row=6, column=2)
        buttons[15].grid(row=7, column=0)
        buttons[16].grid(row=7, column=1)

        # clear button
        buttons[17] = tk.Button(root, text="Clear", padx=130, pady=20, command=self.button_clear)
        buttons[17].grid(row=8, column=0, columnspan=3)

    def addition(self):
        self._backend.update_number(int(self._entry.get()), "+")
        global operation
        operation = "addition"
        self._entry.delete(0, tk.END)

    def subtraction(self):
        self._backend.update_number(int(self._entry.get()), "-")
        global operation
        operation = "subtraction"
        self._entry.delete(0, tk.END)

    def multiplication(self):
        self._backend.update_number(int(self._entry.get()), "*")
        global operation
        operation = "multiplication"
        self._entry.delete(0, tk.END)

    def division(self):
        self._backend.update_number(int(self._entry.get()), "/")
        global operation
        operation = "division"
        self._entry.delete(0, tk.END)

    def button_number(self, text):
        current = self._entry.get()
        self._entry.delete(0, tk.END)
        self._entry.insert(0, str(current) + str(text))

    def button_equal(self):
        self._backend.equal_operation(int(self._entry.get()))
        self._entry.delete(0, tk.END)
        self._entry.insert(0, self._backend.get_result())

    def button_clear(self):
        self._entry.delete(0, tk.END)


if __name__ == '__main__':
    root = tk.Tk()
    app = CalculatorGUI(root)
    root.mainloop()
