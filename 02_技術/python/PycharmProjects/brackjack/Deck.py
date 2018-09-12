# coding = utf-8

"""
==============
デッキクラス
==============
"""
from Card import Card
from Const import CARD_FORMAT
import random


class Deck:
    __cards = list()

    def __init__(self):
        for suit in ['H', 'D', 'C', 'S']:
            for number in range(1, 13+1, 1):
                card = Card(suit, number)
                self.__cards.append(card)

    def shuffle(self):
        random.shuffle(self.__cards)

    def open(self):
        for card in self.__cards:
            print(CARD_FORMAT.format(card.open()))
