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
    player.hit(deck)

    # game
    dealer.show_hand(True)
    player.show_hand()

    while True:
        print(MENU)
        ans = input("command >> ")
        if ans == 'h':
            over = player.hit(deck)
        elif ans == 's':
            player.stand()
        elif ans == 'q':
            break
        else:
            print("invalid answer! die!")
        player.show_hand()


