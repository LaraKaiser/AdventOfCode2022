import re
"""Calculates best case szenario against test_elf"""

prb_hand = {"AA": 5,
            "AB": 1,
            "AC": 9,
            "BA": 8,
            "BB": 4,
            "BC": 3,
            "CA": 2,
            "CB": 7,
            "CC": 6}

def oponent_input(hand_sign: str) -> int:
    score = 0
    hand_sign = re.split(r",\s", hand_sign.lower().replace(" ", ""))
    
    for hand in hand_sign:
        score = score + [value for key, value in prb_hand.items() if hand.replace("\n", "") == key.lower()][0]
    return score


if __name__ == "__main__":
    test_elf = "C C,\nC C\n,\n A B,\n A A"
    my_score = oponent_input(test_elf)
    print(f"My total score against test_elf is: {my_score}")
