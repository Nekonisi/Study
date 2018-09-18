# coding = utf-8

from interface.human import Human
from Deck import Deck

"""
==============
Player Class
==============
"""


class Player(Human):

    def __init__(self):
        self.name = ''
        self.hand = list()
        self.score = 0

    def get_name(self):
        return self.name

    def greet(self):
        print('You: My name is ...', end="")
        self.name = str(input())
        return self.name

    def hit(self, deck: Deck):
        return super().hit(deck)

    def first_draw(self, deck) -> Deck:
        super().first_draw(deck)

    def stand(self):
        super().stand()

    def show_hand(self):
        print(self.name + '\'s hand is', end=' ')

        for card in self.hand:
            print(card.open(), end=' ')

        self.__show_score()

    def __show_score(self):
        print('(' + str(self.score) + ')')
