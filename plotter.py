import matplotlib.pyplot as plt


def plot_graph(fileName):
    with open(fileName) as infile:
        lines = infile.readlines()
    toPlot = []
    for line in lines:
        toPlot.append(tuple(map(float, line.split(None))))
    plt.scatter([point[0] for point in toPlot], [point[1] for point in toPlot])
    plt.show()
    plt.savefig("uncategorized_plot.png")


def main():
    plot_graph("cmake-build-debug/points.txt")

if __name__=="__main__":
    main()