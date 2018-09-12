# coding=utf8


from Deck import Deck
from Dealer import Dealer
from Player import Player

if __name__ == '__main__':
    # program start here!

    dealer = Dealer()
    player = Player()

    Dealer.greet(player)

    deck = Deck()
    # deck is shuffled
    deck.shuffle()

    deck.open()
