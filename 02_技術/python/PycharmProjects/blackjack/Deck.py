# coding = utf-8

"""
==============
Deck Class
==============
"""
from Card import Card
from Const import CARD_FORMAT
import random


class Deck:
    __cards = list()
    __number = __cards

    def __init__(self):
        for suit in ['H', 'D', 'C', 'S']:
            for number in range(1, 13+1, 1):
                __card = Card(suit, number)
                self.__cards.append(__card)

    def shuffle(self):
        random.shuffle(self.__cards)

    def pop(self):
        card = self.__cards.pop()
        return card
