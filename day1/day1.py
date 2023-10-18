def sort_elfes(calories: dict) -> tuple:
    # sorts dictionary and returns elf with most calories and calorie count sum
    sorted_Elfes = dict(sorted(calories.items(), key=lambda x: sum(x[1]), reverse=True))
    return (next(iter(sorted_Elfes)), sum(next((iter(sorted_Elfes.values())))))


def calorie_sum(calories: dict) -> int:
    # overall sum of calories
    sum_calories = 0
    for index in calories.items():
        sum_calories = sum_calories + sum(index[1])
    return sum_calories


if __name__ == "__main__":
    with open("text.txt", "r") as f:
        elf_list = {}
        elves = f.read().split("\n\n")        
        for i, elf in enumerate(elves):
            elf_calories = elf.split("\n")
            elf_list[f"elf{i + 1}"] = (sorted([int(x) for x in elf_calories if x.strip()],  reverse=True))

        calorie_overelf = sort_elfes(elf_list)
        print(f"The elf with the highest calorie snack is {calorie_overelf}")
        print(f"The overall calories are {calorie_sum(elf_list)}")
