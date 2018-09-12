# coding = utf-8


"""
==============
プレイヤークラス
==============
"""


class Player:
    def __init__(self):
        self.__name = ''

    def greet(self):
            print('You: My name is ...', end="")
            self.__name = str(input())

    def get_name(self):
        return self.__name
