# coding=utf8

from Deck import Deck
from Dealer import Dealer
from Player import Player
from Const import *

'''
=============
main def
=============
'''


def command():
    while True:
        print(MENU)
        ans = input("command >> ")
        if ans == 'h':
            bast_flg, blackjack_flg = player.hit(deck)
            if bast_flg:
                break
            elif blackjack_flg:
                print('BlackJack!')
                break
        elif ans == 's':
            player.stand()
        elif ans == 'q':
            break
        else:
            print("invalid answer! die!")
        player.show_hand()


if __name__ == '__main__':
    # program start here!

    # make characters!
    dealer = Dealer()
    player = Player()

    # introduce
    dealer.greet(player)

    # make tools
    deck = Deck()
    # deck is shuffled
    deck.shuffle()

    dealer.first_draw(deck)
    player.first_draw(deck)

    # game
    dealer.show_hand(True)
    player.show_hand()

    # Player's turn
    command()

    # dealer's turn
    dealer.show_hand(False)
    player.show_hand()
