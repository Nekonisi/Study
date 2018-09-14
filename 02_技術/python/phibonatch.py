# -*- coding: utf-8 -*-


class Fibonacci:

    __list = []

    def __init__(self):
        self.__list.append(1)
        self.__list.append(1)

    def add(self):
        value = self.__list[len(self.__list) - 1] + self.__list[len(self.__list) - 2]
        self.__list.append(value)

    def delete(self):
        if len(self.__list) < 3:
            print('too low to delete list')
        else:
            del self.__list[len(self.__list)-1]

    def print_list(self):
        print(self.__list)


def show_menu():
    menu = ''' 
   ****************************
   Fibonacci sequence !!
   ****************************
   please press a key!
     [a]: add to sequence
     [d]: delete from sequence
     [p]: show list
     [q]: quit
   '''
    print(menu)


if __name__ == '__main__':
    fibonacci = Fibonacci()
    while True:
        show_menu()
        ans = input("command >> ")

        if ans == 'a':
            fibonacci.add()
        elif ans == 'd':
            fibonacci.delete()
        elif ans == 'p':
            fibonacci.print_list()
        elif ans == 'q':
            break
        else:
            print("invalid answer! die!")

