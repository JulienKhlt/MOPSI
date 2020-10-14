from random import random, randint

def create_file(number_file, number_point, number_repetition, name_file = "Data"):
    for j in range(number_file):
        numbers_list = [random() for i in range(number_point)]
        for i in range(number_repetition):
            numbers_list.append(numbers_list[randint(0,len(numbers_list)-1)])
        with open("Base_Donnees/" + name_file + f"{j}.csv", "w") as f:
            for number in numbers_list:
                f.write(f"{number};")


if __name__ == '__main__':
    create_file(5, 10000, 50)
