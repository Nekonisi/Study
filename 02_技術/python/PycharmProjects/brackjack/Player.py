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
        self.__name = ''
        self.__hand = list()
        self.__score = 0

    def get_name(self):
        return self.__name

    def greet(self):
            print('You: My name is ...', end="")
            self.__name = str(input())
            return self.__name

    def hit(self, deck) -> Deck:
        print(self.__name + ": hit")
        self.__hand.append(deck.pop())
        score = self.__hand[-1].get_number()

        if score > 10:
            score = 10

        self.__score += score
        if self.__score > 21:
            print('Busted!')

    def first_draw(self, deck)->Deck:
        super().first_draw(deck)

    def stand(self, deck):
        super().stand()

    def show_hand(self):
            for card in self.__hand:
                print(card.open(), end=' ')

            self.__show_score()

    def __show_score(self):
            print('(' + str(self.__score) + ')')
