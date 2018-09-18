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
        self.hand = list()
        self.score = 0
        self.name = 'Dealer'

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
        print(self.name + ': My hand is ', end=' ')

        if flg:
            print(self.hand[0].open(), end=' ')
        else:
            for card in self.hand:
                print(card.open(), end=' ')

        self.__show_score(flg)

    def __show_score(self, flg: bool) -> bool:
        if flg:
            score = self.score - self.hand[-1].get_number()
            print('(' + str(score) + ')')
        else:
            print('(' + str(self.score) + ')')

    def action(self, deck: Deck) -> bool:
        if self.score <= 15:
            self.hit(deck)
            return True
        else:
            self.stand(deck)
            return False
