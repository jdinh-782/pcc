"""
Name: Johnson Dinh
Assignment Week 08: This big program essentially acts like a mini casino. There are three games the user can play where
                    they will be able to bet and win/lose. There will be classes for different aspects of the game as
                    well as sub-classes that represent individual games. Checks are implemented so that the user cannot
                    bet over specific restrictions. The user will have the option to leave the casino or be kicked out
                    if they have no more money left over. Overall stats will be displayed.
"""

import random
import time
from enum import Enum

deck = []
balance = 20
total_wins = 0
total_losses = 0
total_gains = 0
user_score_spades = user_score_hearts = user_score_diamonds = user_score_clubs = 0
dealer_score_clubs = dealer_score_hearts = dealer_score_diamonds = dealer_score_spades = 0


# Casino class that returns stats
class Casino:
    def __init__(self, balance, total_losses, total_wins, total_gains):
        self._balance = balance
        self._total_losses = total_losses
        self._total_wins = total_wins
        self._total_gains = total_gains

    def get_balance(self):
        return self._balance

    def get_total_losses(self):
        return self._total_losses

    def get_total_wins(self):
        return self._total_wins

    def get_total_gains(self):
        return self._total_gains

    def display(self):
        print(f"{'-' * 15 :>40} Welcome to the casino! {'-' * 15}"
              f"\n\nTonight we will be hosting 3 unique games for you."
              f"\nThey will be Highest Sum (Rank), Highest Sum (Suit), and Blackjack!"
              f"\nWe hope you enjoy your time here and without further ado, let's begin!")


# table class for representation
class Table:
    def __init__(self, balance):
        # self._table1 = table1  # highest sum (rank only)
        # self._table2 = table2  # highest sum (suits)
        # self._table3 = table3  # blackjack
        self._balance = balance

    def get_balance(self):
        return self._balance


# highest sum (rank only) game
class TableHighestSum(Table):
    def __init__(self, balance):
        super().__init__(balance)
        self._balance = balance

    def display(self):
        print("\nTHE TABLE 'TableHighestSum' WAS CHOSEN! "
              "\nThe rules are fairly simple! "
              "\nYou will receive 5 random cards into your hand. In order for you to win, your hand score must beat "
              "the card dealer's hand score."
              "\nYour hand score is determined by the values of the ranks of each card that you have in your hand."
              "\nThe values for each rank are as follows: "
              "ACE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, "
              "JACK = 11, QUEEN = 12, KING = 13")


# highest sum (suits and ranks) game
class TableHighestSumSuits(Table):
    def __init__(self, balance):
        super().__init__(balance)
        self._balance = balance

    def display(self):
        print("\nTHE TABLE 'TableHighestSumSuits' WAS CHOSEN! "
              "\nThis game is very similar to the 'TableHighestSum' game, however, if there is a tie between your hand "
              "score and the dealer's hand score, the rank of the suits will be taken into account to decide who will "
              "win."
              "\nFor example, if you and the dealer both obtain a total score of 10 from your cards' ranks, the player "
              "with the most amount of suits will win, as long as it follows the suit ranking list."
              "\nIf you and the dealer both have a score of 10, but you have more spades than the dealer, you will win."
              " Thus will be the same for the rest of the suits."
              "\nThe suit order goes as follows: SPADES, HEARTS, DIAMONDS, CLUBS, with 'SPADES' being the highest "
              "ranked suit. "
              "\nAlso remember that the values for each rank are as follows: ACE = 1, TWO = 2, THREE = 3, FOUR = 4, "
              "FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 11, QUEEN = 12, KING = 13. "
              "\nBoth you and the dealer will be given two cards. Best of luck! ")


# blackjack game
class TableBlackJack(Table):
    def __init__(self, balance):
        super().__init__(balance)
        self._balance = balance

    def display(self):
        print("\nTHE TABLE 'TableBlackJack' WAS CHOSEN! "
              "\nBlackjack is our game of the night, and we are so glad to have you come play with us! "
              "\nThe rules are simple! You will go up against the dealer, and the player who gets closest to 21 wins! "
              "\nScores are determined by the rank values of each card both players have. "
              "\nEach player will be dealt two cards at the beginning. They may wish to be 'hit' with one card at a "
              "time, meaning that they wish to draw another card in hopes of getting closer to 21. "
              "\nHowever, as soon as one player goes past 21 or 'bust', the other player automatically wins! "
              "\nWe will go by the five card trick rule as it states that the first player who has been dealt five "
              "cards in total will automatically win the game, regardless of scores. "
              "\nAs soon as a player reaches a total score of 20 or 21, that player instantly wins! "
              "\nOnly you will be able to see your own cards, and therefore will not know which cards the dealer has. "
              "\nThe rules are pretty straightforward right? Alright. Let's play some blackjack! ")


# class of enums that return distinct values (still needs practice)
class Rank_enum(Enum):
    ACE = 1
    TWO = 2
    THREE = 3
    FOUR = 4
    FIVE = 5
    SIX = 6
    SEVEN = 7
    EIGHT = 8
    NINE = 9
    TEN = 10
    JACK = 11
    QUEEN = 12
    KING = 13

    def get_rank(self, rank):
        if rank == 1:
            return 'ACE'

        elif rank == 2:
            return 'TWO'

        elif rank == 3:
            return 'THREE'

        elif rank == 4:
            return 'FOUR'

        elif rank == 5:
            return 'FIVE'

        elif rank == 6:
            return 'SIX'

        elif rank == 7:
            return 'SEVEN'

        elif rank == 8:
            return 'EIGHT'

        elif rank == 9:
            return 'NINE'

        elif rank == 10:
            return 'TEN'

        elif rank == 11:
            return 'JACK'

        elif rank == 12:
            return 'QUEEN'

        elif rank == 13:
            return 'KING'


# card class that sets up the suits and ranks of each card
class Card:
    def __init__(self, rank, suit):
        self._rank = rank
        self._suit = suit

    def get_rank(self):
        return self._rank

    def get_suit(self):
        return self._suit

    def __str__(self):
        return str(self._rank) + " : " + self._suit


# initializes and shuffles the deck of cards
class Deck:
    def __init__(self, ranks, suits):
        self._cards = []

        for r in ranks:
            for s in suits:
                self._cards.append(Card(r, s))

    def get_deck(self):
        return self._cards

    def draw_card(self):
        return self._cards.pop()

    def shuffle(self):
        random.shuffle(self._cards)
        # random.shuffle(self._cards)

    def display_deck(self):
        for card in deck:
            print(card)


# initializes the user's card hand
class Card_hand:
    def __init__(self, cards):
        self._cards = []
        self._ranks = []
        self._suits = []

    def get_cards(self):
        card = deck.draw_card()
        self._cards.append(card)
        self._ranks.append(card.get_rank())
        self._suits.append(card.get_suit())
        return card

    def print_card(self):
        for card in self._cards:
            print(card)

    def print_ranks(self):
        for rank in self._ranks:
            print(rank)

    def print_suits(self):
        for suit in self._suits:
            print(suit)

    def get_hand_score(self, game_type):
        hand_score = 0
        r = Rank_values(hand_score)

        for rank in self._ranks:
            hand_score += r.return_rank_value(rank, game_type)
        return hand_score

    def get_suit_score(self, user):
        global user_score_clubs, user_score_hearts, user_score_diamonds, user_score_spades
        global dealer_score_clubs, dealer_score_hearts, dealer_score_diamonds, dealer_score_spades

        if user == 1:
            for suit in self._suits:
                if suit == 'SPADES':
                    user_score_spades += 1
                elif suit == 'HEARTS':
                    user_score_hearts += 1
                elif suit == 'DIAMONDS':
                    user_score_diamonds += 1
                elif suit == 'CLUBS':
                    user_score_clubs += 1
        else:
            for suit in self._suits:
                if suit == 'SPADES':
                    dealer_score_spades += 1
                elif suit == 'HEARTS':
                    dealer_score_hearts += 1
                elif suit == 'DIAMONDS':
                    dealer_score_diamonds += 1
                elif suit == 'CLUBS':
                    dealer_score_clubs += 1


# class of rank values that are needed to determine a score
class Rank_values:
    def __init__(self, hand_score):
        self._rank_value = Rank_enum
        self._hand_score = hand_score

    def return_rank_value(self, rank, game_type):
        if rank == self._rank_value.ACE.name:
            return self._rank_value.ACE.value

        elif rank == self._rank_value.TWO.name:
            return self._rank_value.TWO.value

        elif rank == self._rank_value.THREE.name:
            return self._rank_value.THREE.value

        elif rank == self._rank_value.FOUR.name:
            return self._rank_value.FOUR.value

        elif rank == self._rank_value.FIVE.name:
            return self._rank_value.FIVE.value

        elif rank == self._rank_value.SIX.name:
            return self._rank_value.SIX.value

        elif rank == self._rank_value.SEVEN.name:
            return self._rank_value.SEVEN.value

        elif rank == self._rank_value.EIGHT.name:
            return self._rank_value.EIGHT.value

        elif rank == self._rank_value.NINE.name:
            return self._rank_value.NINE.value

        elif rank == self._rank_value.TEN.name:
            return self._rank_value.TEN.value

        elif rank == self._rank_value.JACK.name:
            if game_type == 1:
                return self._rank_value.JACK.value
            elif game_type == 2:
                return 10

        elif rank == self._rank_value.QUEEN.name:
            if game_type == 1:
                return self._rank_value.QUEEN.value
            elif game_type == 2:
                return 10

        elif rank == self._rank_value.KING.name:
            if game_type == 1:
                return self._rank_value.KING.value
            elif game_type == 2:
                return 10

    def __lt__(self, other):
        return self._hand_score < other._hand_score

    def __eq__(self, other):
        return self._hand_score == other._hand_score


# since this never changes, I decided to make it an universal function
# simply takes in the user's int input for a bet amount
def get_bet():
    while True:
        try:
            bet = int(input("\nThink you're going to win? Enter a bet amount ($1, $5, $10): "))

            if bet <= 0:
                print("Bet amount must be greater than 0! ")

            elif bet != 1 and bet != 5 and bet != 10:
                print("Bet amount must be either $1, $5, or $10! ")

            elif bet > balance:
                print(f"Bet amount cannot exceed balance! Your balance is ${balance}. ")

            else:
                return bet

        except ValueError:
            print("You did not enter a numerical input. Enter again!")


if __name__ == '__main__':
    while balance > 0:
        if balance <= 0:
            print("\nYou have no more money! Kicked out! ")
            exit(0)

        random.seed(None)

        c = Casino(balance, total_losses, total_wins, total_gains)
        c.display()

        option = input("\n[1] Highest Sum (Rank)"
                       "\n[2] Highest Sum (Suit)"
                       "\n[3] Blackjack"
                       "\n[4] Quit"
                       "\nChoice: ")

        # deck initialization in main
        deck = Deck([Rank_enum.get_rank(Rank_enum.ACE, 1), Rank_enum.get_rank(Rank_enum.ACE, 2),
                     Rank_enum.get_rank(Rank_enum.ACE, 3), Rank_enum.get_rank(Rank_enum.ACE, 4),
                     Rank_enum.get_rank(Rank_enum.ACE, 5), Rank_enum.get_rank(Rank_enum.ACE, 6),
                     Rank_enum.get_rank(Rank_enum.ACE, 7), Rank_enum.get_rank(Rank_enum.ACE, 8),
                     Rank_enum.get_rank(Rank_enum.ACE, 9), Rank_enum.get_rank(Rank_enum.ACE, 10),
                     Rank_enum.get_rank(Rank_enum.ACE, 11), Rank_enum.get_rank(Rank_enum.ACE, 12),
                     Rank_enum.get_rank(Rank_enum.ACE, 13)], ["HEARTS", "SPADES", "CLUBS", "DIAMONDS"])

        deck.shuffle()

        # displays the deck of cards
        # print("")
        # print("*" * 15)
        # for card in deck.get_deck():
        #     print(card)
        # print("*" * 15)

        # displays final game stats
        t = Table(balance)
        if option == '4':
            print("\nCya next time!")
            print(f"\n\nSTATS"
                  f"\nSTARTING AMOUNT: $20"
                  f"\nENDING AMOUNT: ${balance}"
                  f"\nTOTAL GAINS: ${total_gains}"
                  f"\nTOTAL LOSSES: {total_losses}"
                  f"\nTOTAL WINS: {total_wins}")
            exit(0)

        # highest sum game
        elif option == '1':
            print(f"\nYou have a balance of ${t.get_balance()}.")
            t1 = TableHighestSum(balance)
            t1.display()
            bet = get_bet()

            confirm = input(f"\nYou are placing a bet of ${bet}! Enter [1] to continue: ")

            if confirm == '1':
                player_hand = Card_hand([])  # refers to the user's hand
                dealer_hand = Card_hand([])  # refers to the dealer's hand

                for i in range(5):
                    player_hand.get_cards()
                print("\nHere is your hand: ")
                player_hand.print_card()

                print("")

                time.sleep(5)
                for i in range(5):
                    dealer_hand.get_cards()
                print("This is your dealer's hand: ")
                dealer_hand.print_card()

                print("\n\nCalculating results...")
                time.sleep(5)
                print(f"YOUR SCORE    : {player_hand.get_hand_score(1)}"
                      f"\nDEALER'S SCORE: {dealer_hand.get_hand_score(1)}")

                first_score = Rank_values(player_hand.get_hand_score(1))
                second_score = Rank_values(dealer_hand.get_hand_score(1))

                if first_score.__lt__(second_score):
                    print("\nYou lose! ")
                    total_losses += 1
                    total_gains -= bet
                    balance -= bet

                elif first_score.__eq__(second_score):
                    print("\nNobody loses since both scores were equal! ")

                else:
                    print("\nYou win! ")
                    total_wins += 1
                    total_gains += bet
                    balance += bet

            else:
                print("Since you did not enter 1 to continue, we are going to assume you do not want to play. Later! ")
                pass

        # highest sum suits game
        elif option == '2':
            print(f"\nYou have a balance of ${t.get_balance()}.")
            t2 = TableHighestSumSuits(balance)
            t2.display()
            bet = get_bet()

            confirm = input(f"\nYou are placing a bet of ${bet}! Enter [1] to continue: ")

            if confirm == '1':
                player_hand = Card_hand([])  # refers to the user's hand
                dealer_hand = Card_hand([])  # refers to the dealer's hand

                for i in range(2):
                    player_hand.get_cards()
                print("\nHere is your hand: ")
                player_hand.print_card()

                print("")

                time.sleep(3)
                for i in range(2):
                    dealer_hand.get_cards()
                print("This is your dealer's hand: ")
                dealer_hand.print_card()

                print("\n\nCalculating results...")
                time.sleep(3)
                print(f"YOUR SCORE    : {player_hand.get_hand_score(1)}"
                      f"\nDEALER'S SCORE: {dealer_hand.get_hand_score(1)}")

                first_score = Rank_values(player_hand.get_hand_score(1))
                second_score = Rank_values(dealer_hand.get_hand_score(1))

                if first_score.__eq__(second_score):
                    player_hand.get_suit_score(1)
                    print("\nYOUR SUIT SCORE")
                    print(f"SPADES: {user_score_spades}"
                          f"\nHEARTS: {user_score_hearts}"
                          f"\nDIAMONDS: {user_score_diamonds}"
                          f"\nCLUBS: {user_score_clubs}")

                    time.sleep(3)
                    print("\n\nDEALER'S SUIT SCORE")
                    dealer_hand.get_suit_score(2)
                    print(f"SPADES: {dealer_score_spades}"
                          f"\nHEARTS: {dealer_score_hearts}"
                          f"\nDIAMONDS: {dealer_score_diamonds}"
                          f"\nCLUBS: {dealer_score_clubs}")

                    if user_score_spades > dealer_score_spades:
                        print("\nSince you have more spades than the dealer, you win! ")
                        total_wins += 1
                        total_gains += bet
                        balance += bet

                    elif user_score_spades < dealer_score_spades:
                        print("\nSince the dealer has more spades than you, the dealer wins. You lose! ")
                        total_losses += 1
                        total_gains -= bet
                        balance -= bet

                    elif user_score_hearts > dealer_score_hearts:
                        print("\nSince you have more hearts than the dealer, you win! ")
                        total_wins += 1
                        total_gains += bet
                        balance += bet

                    elif user_score_hearts < dealer_score_hearts:
                        print("\nSince the dealer has more hearts than you, the dealer wins. You lose! ")
                        total_losses += 1
                        total_gains -= bet
                        balance -= bet

                    elif user_score_diamonds > dealer_score_diamonds:
                        print("\nSince you have more diamonds than the dealer, you win! ")
                        total_wins += 1
                        total_gains += bet
                        balance += bet

                    elif user_score_diamonds < dealer_score_diamonds:
                        print("\nSince the dealer has more diamonds than you, the dealer wins. You lose! ")
                        total_losses += 1
                        total_gains -= bet
                        balance -= bet

                    elif user_score_clubs > dealer_score_clubs:
                        print("\nSince you have more clubs than the dealer, you win! ")
                        total_wins += 1
                        total_gains += bet
                        balance += bet

                    elif user_score_clubs < dealer_score_clubs:
                        print("\nSince the dealer has more clubs than you, the dealer wins. You lose! ")
                        total_losses += 1
                        total_gains -= bet
                        balance -= bet

                    elif user_score_spades == dealer_score_spades and user_score_clubs == dealer_score_clubs and \
                            user_score_diamonds == dealer_score_diamonds and user_score_hearts == dealer_score_hearts:
                        print("\nNobody loses since your rank and suit scores are all equal to the dealers'! ")

                elif first_score.__lt__(second_score):
                    print("\nYou lose! ")
                    total_losses += 1
                    total_gains -= bet
                    balance -= bet

                else:
                    print("\nYou win! ")
                    total_wins += 1
                    total_gains += bet
                    balance += bet

            else:
                print("Since you did not enter 1 to continue, we are going to assume you do not want to play. Later! ")
                pass

        # blackjack game
        elif option == '3':
            print(f"\nYou have a balance of ${t.get_balance()}.")
            t3 = TableBlackJack(balance)
            t3.display()

            bet = get_bet()

            confirm = input(f"\nYou are placing a bet of ${bet}! Enter [1] to continue: ")

            if confirm == '1':
                print("Alright! Let's play!\n")
                time.sleep(1)
                player_hand = Card_hand([])  # refers to the user's hand
                dealer_hand = Card_hand([])  # refers to the dealer's hand

                for i in range(2):
                    player_hand.get_cards()
                print("\nHere is your hand: ")
                player_hand.print_card()

                print("")

                time.sleep(3)
                for i in range(2):
                    dealer_hand.get_cards()
                print("Your dealer has received his/her hand. ")

                while True:
                    print("\n\nCalculating scores...")
                    time.sleep(3)
                    print(f"YOUR SCORE    : {player_hand.get_hand_score(2)}"
                          f"\nDEALER'S SCORE: {dealer_hand.get_hand_score(2)}")

                    user_score = player_hand.get_hand_score(2)
                    dealer_score = dealer_hand.get_hand_score(2)

                    if user_score == 20 or user_score == 21:
                        print("\nSince your cards sum up to either 20 or 21, you win! ")
                        total_wins += 1
                        total_gains += bet
                        balance += bet
                        break

                    elif dealer_score == 20 or dealer_score == 21:
                        print("\nSince the dealers' cards sum up to either 20 or 21, they win! You lose! ")
                        total_losses += 1
                        total_gains -= bet
                        balance -= bet
                        break

                    elif user_score > 21:
                        print("\nSince your score is over 21, the dealer automatically wins. You lose! ")
                        total_losses += 1
                        total_gains -= bet
                        balance -= bet
                        break

                    elif dealer_score > 21:
                        print("\nSince the dealer's score is over 21, the dealer automatically loses. You win! ")
                        total_wins += 1
                        total_gains += bet
                        balance += bet
                        break

                    elif user_score == 20 and user_score == dealer_score:
                        print("\nSince you and the dealer have the same score of 20, nobody loses! ")
                        break

                    elif user_score == 21 and user_score == dealer_score:
                        print("\nSince you and the dealer have the same score of 21, nobody loses! ")
                        break

                    while True:
                        try:
                            option = int(input("\n\nEnter [1] to hit: "
                                               "\nEnter [2] to pass: "
                                               "\n"))
                            if option == 1:
                                player_hand.get_cards()
                                break

                            elif option == 2:
                                dealer_hand.get_cards()
                                break

                            else:
                                print("Invalid choice. Enter again!")
                                continue
                        except ValueError:
                            print("You did not enter a numerical input. Enter again!")

                    print("\nHere is your hand: ")
                    player_hand.print_card()
                    time.sleep(3)

                    print("\nThe dealer hits! ")
                    dealer_hand.get_cards()
                    time.sleep(1)

            else:
                print("Since you did not enter 1 to continue, we are going to assume you do not want to play. Later! ")
                pass

        else:
            print("Invalid Choice!")

        print(f"\nYour balance is ${balance}. ")

        if balance <= 0:
            print("\nYou have no more money! Kicked out! ")
            print(f"\n\nSTATS"
                  f"\nSTARTING AMOUNT: $20"
                  f"\nENDING AMOUNT: ${balance}"
                  f"\nTOTAL GAINS: ${total_gains}"
                  f"\nTOTAL LOSSES: {total_losses}"
                  f"\nTOTAL WINS: {total_wins}")
            exit(0)

        print("\n\n")
