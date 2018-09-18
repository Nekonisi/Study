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
    def greet(player)-> Player:
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

    def hit(self, deck):
        super().hit(deck)

    def stand(self, deck):
        super().stand()

    def first_draw(self, deck)->Deck:
        super().first_draw(deck)

    def show_hand(self, flg):
        print(self.name + ': My hand is ', end=' ')

        if flg:
            print(self.hand[0].open(), end=' ')
        else:
            for card in self.hand:
                print(card.open(), end=' ')

        self.__show_score(flg)

    def __show_score(self, flg)->bool:
        if flg:
            score = self.score - self.hand[-1].get_number()
            print('(' + str(score) + ')')
        else:
            print('(' + str(self.score) + ')')
