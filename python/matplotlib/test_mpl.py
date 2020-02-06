from matplotlib import pyplot as plt
from random import randint

if __name__ == '__main__':
    dev_x = list(range(50))
    dev_y = [x + randint(20, 30) for x in dev_x]

    plt.plot(dev_x, dev_y)
    plt.xlabel("Height (inches)")
    plt.ylabel("Age (Years)")
    plt.title("Akash's Height")

    plt.show()