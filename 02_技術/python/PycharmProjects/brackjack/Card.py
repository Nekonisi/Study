# coding = utf-8

from Const import CARD_FORMAT

"""
==========
Card Class
==========
"""


class Card:
    def __init__(self, suit, number):
        self.__suit = suit
        self.__number = number

    def open(self):
        return CARD_FORMAT.format(self.__suit, self.__number)

    def get_number(self):
        return self.__number
