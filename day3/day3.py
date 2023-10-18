"""Day3 of Advent of Code 2022"""


class Rucksack():
    def __init__(self, content, ruck_number: str):
        self.content = content
        self.compart1 = {}
        self.compart2 = {}
        self.unique_char = ""
        self.ruck_number = f"Rucksack_{ruck_number}"


def sum_prio_calc(cur_rucksack: Rucksack) -> int:
    common_char = cur_rucksack.compart1.intersection(cur_rucksack.compart2).pop()
    if common_char.islower():
        value_char = ord(common_char) - ord("a") + 1
    else:
        value_char = ord(common_char) - ord("A") + 27
    return value_char


if __name__ == "__main__":
    elves_rucksack = []
    with open("day3.txt", "r", encoding="UTF-8") as f:
        index = 0
        cur_list = []
        for line in f:
            cur_rucksack = Rucksack(line.strip(), index)
            index += 1
            for char in cur_rucksack.content:
                cur_list.append(char)
            cur_list_len = int(len(cur_list)/2)
            cur_rucksack.compart1 = set(cur_list[:cur_list_len])
            cur_rucksack.compart2 = set(cur_list[cur_list_len:])
            cur_rucksack.unique_char = cur_rucksack.compart1.intersection(cur_rucksack.compart2)
            elves_rucksack.append(cur_rucksack)
            cur_list = []
    sum_chars = 0
    for elf_rucksack in elves_rucksack:
        sum_chars += sum_prio_calc(elf_rucksack)
    print(f"The overall sum is: {sum_chars}")
