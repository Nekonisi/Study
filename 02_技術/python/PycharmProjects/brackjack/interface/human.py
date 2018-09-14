# coding=utf8
from abc import abstractmethod
from Deck import Deck

"""
==========
human Class(interface)
==========
"""


class Human:

    @abstractmethod
    def greet(self):
        pass

    @abstractmethod
    def hit(self, deck) -> Deck:
        print(self.__name + ": hit")
        self.__hand.append(deck.pop())
        score = self.__hand[-1].get_number()

        if score > 10:
            score = 10

        self.__score += score
        if self.__score > 21:
            print('Busted!')

    @abstractmethod
    def stand(self):
        print(self.__name + ' : stand')

    @abstractmethod
    def first_draw(self, deck) -> Deck:
        self.hit(deck)
        self.hit(deck)
