# coding = utf-8

from Player import Player
from Deck import Deck
from interface.human import Human

"""
==============
Dealer Class
==============
"""


class Dealer(Human):

    def __init__(self):
        super().__init__()
        self._name = 'Dealer'

    @staticmethod
    def greet(player: Human):
        ignore_count = 0
        if player.get_name() == '':
            print('Dealer: Welcome!')
            print('Dealer: What\'s your name?')
            player.greet()

        while player.get_name() == '':
            print('Dealer: Huh? Are you DEAF?')
            print('Dealer: What is your NAME?')
            player.greet()
            ignore_count += 1
            if ignore_count > 5:
                print('Dealer: OK! FUCK OFF LOSER!!')
                exit()
        else:
            print('Dealer: OK! {} Let\'s play game'.format(player.get_name()))

    def hit(self, deck: Deck):
        super().hit(deck)

    def stand(self, deck: Deck):
        super().stand()

    def first_draw(self, deck: Deck):
        super().first_draw(deck)

    def show_hand(self, flg: bool):
        print(self._name + ': My hand is ', end=' ')

        if flg:
            print(self._hand[0].open(), end=' ')
        else:
            for card in self._hand:
                print(card.open(), end=' ')

        self.__show_score(flg)

    def __show_score(self, flg: bool) -> bool:
        if flg:
            score = self._score - self._hand[-1].get_number()
            print('(' + str(score) + ')')
        else:
            print('(' + str(self._score) + ')')

    def action(self, deck: Deck) -> bool:
        if self._score <= 15:
            self.hit(deck)
            return True
        else:
            self.stand(deck)
            return False
