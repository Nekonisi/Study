# coding = utf-8


"""
==========
カードクラス
==========
"""


class Card:
    def __init__(self, suit, number):
        self.__suit = suit
        self.__number = number

    def open(self):
        return self.__suit, self.__number

