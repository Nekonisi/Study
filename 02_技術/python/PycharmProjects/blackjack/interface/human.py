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
        self._name = ''
        self._score = 0
        self._hand = list()

    @abstractmethod
    def greet(self):
        pass

    def hit(self, deck: Deck) -> bool:
        print(self._name + ": hit")
        self._hand.append(deck.pop())
        score = self._hand[-1].get_number()

        if score > 10:
            score = 10

        # If Draw Card is Ace
        if score == 1:
            if self._score < 11:
                score = 11

        self._score += score

        if self._score > 21:
            print('Busted!')
            return True, False

        if self._score == 21:
            print('BlackJack!')
            return False, True
        else:
            return False, False

    def stand(self):
        print(self._name + ' : stand')

    def first_draw(self, deck: Deck):
        self.hit(deck)
        self.hit(deck)

    def get_score(self) -> int:
        return self._score

    def get_name(self) -> str:
        return self._name
