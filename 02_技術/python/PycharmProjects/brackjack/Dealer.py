# coding = utf-8

from Player import Player

"""
==============
ディーラークラス
==============
"""


class Dealer:
    hand = list()

    def __init__(self):
        self.__hand = 0

    def show_hand(self):
        print(self.__hand)

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

