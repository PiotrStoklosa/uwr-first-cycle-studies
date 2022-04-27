from random import shuffle


def rank(card):
    return (card - 1) // 4


def suit(card):
    return (card - 1) % 4


def randomise_figurant():
    deck = [i for i in range(37, 52 + 1)]
    shuffle(deck)
    figurant_deck = deck[:5]
    figurant_deck.sort()
    figurant_deck.reverse()
    return figurant_deck


def randomise_blotkarz(range_start, range_closed_end):
    deck = [i for i in range(range_start, range_closed_end + 1)]
    shuffle(deck)
    blotkarz_deck = deck[:5]
    blotkarz_deck.sort()
    blotkarz_deck.reverse()
    return blotkarz_deck


def randomise_own_deck_blotkarz(own_deck):
    shuffle(own_deck)
    blotkarz_deck = own_deck[:5]
    blotkarz_deck.sort()
    blotkarz_deck.reverse()
    return blotkarz_deck


def is_straight_flush(deck):
    return is_straight(deck) and is_flush(deck)


def is_four_of_a_kind(deck):
    return rank(deck[0]) == rank(deck[3]) or rank(deck[1]) == rank(deck[4])


def is_full_house(deck):
    return rank(deck[0]) == rank(deck[2]) and rank(deck[3]) == rank(deck[4]) or rank(
        deck[0]) == rank(deck[1]) and rank(deck[2]) == rank(deck[4])


def is_flush(deck):
    for i in range(4):
        if suit(deck[i]) != suit(deck[i + 1]):
            return False
    return True


def is_straight(deck):
    for i in range(4):
        if rank(deck[i]) != rank(deck[i + 1]) + 1:
            return False
    return True


def is_three_of_a_kind(deck):
    for i in range(3):
        if rank(deck[i]) == rank(deck[i + 2]):
            return True
    return False


def is_two_pair(deck):
    return rank(deck[0]) == rank(deck[1]) and rank(deck[2]) == rank(deck[3]) or \
           rank(deck[0]) == rank(deck[1]) and rank(deck[3]) == rank(deck[4]) or \
           rank(deck[1]) == rank(deck[2]) and rank(deck[3]) == rank(deck[4])


def is_one_pair(deck):
    for i in range(4):
        if deck[i] == deck[i + 1]:
            return True
    return False


def hand_rank(deck):
    if is_straight_flush(deck):
        return 9
    if is_four_of_a_kind(deck):
        return 8
    if is_full_house(deck):
        return 7
    if is_flush(deck):
        return 6
    if is_straight(deck):
        return 5
    if is_three_of_a_kind(deck):
        return 4
    if is_two_pair(deck):
        return 3
    if is_one_pair(deck):
        return 2
    return 1


def compare_decks(figurant_deck, blotkarz_deck):
    if hand_rank(figurant_deck) >= hand_rank(blotkarz_deck):
        return "figurant"
    return "blotkarz"


def test(test_cases):
    hands_won_by_blotkarz = 0
    for i in range(test_cases):
        figurant_deck = randomise_figurant()
        blotkarz_deck = randomise_blotkarz(25, 36)
        if compare_decks(figurant_deck, blotkarz_deck) == "blotkarz":
            hands_won_by_blotkarz += 1
    return hands_won_by_blotkarz * 100 // test_cases


print(str(test(1000)) + "%")
