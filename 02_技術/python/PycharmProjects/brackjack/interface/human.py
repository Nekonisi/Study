# coding=utf8
from abc import abstractmethod
from Deck import Deck

"""
==========
human Class(interface)
==========
"""


class Human(object):

    def __init__(self):
        self.name = ''
        self.score = 0
        self.hand = list()

    @abstractmethod
    def greet(self):
        pass

    @abstractmethod
    def hit(self, deck: Deck) -> bool:
        print(self.name + ": hit")
        self.hand.append(deck.pop())
        score = self.hand[-1].get_number()

        if score > 10:
            score = 10

        self.score += score
        if self.score > 21:
            print('Busted!')
            return True, False

        if self.score == 21:
            return False, True
        else:
            return False, False

    @abstractmethod
    def stand(self):
        print(self.name + ' : stand')

    @abstractmethod
    def first_draw(self, deck) -> Deck:
        self.hit(deck)
        self.hit(deck)
