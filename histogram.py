import matplotlib.pyplot as plt
import matplotlib as mpl
mpl.rcParams['mathtext.fontset'] = 'cm'
def histogram(file, character=";"):
    with open(file, 'r') as f:
        line = f.readline()
        line = line.split(character)
        result = (map(float, line[:len(line)-2]))
        plt.hist(list(result), range=(37000, 43000), bins = 30, edgecolor = 'black', color = '#03749c')
        plt.xlabel(r'$Valeurs$')
        plt.ylabel(r"$Nombres$ $d'occurence$")
        plt.title(r'$Histogramme$ $de$ $loglog$', fontsize=16)
        plt.show()
histogram("test.txt")