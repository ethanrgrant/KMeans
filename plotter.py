import matplotlib.pyplot as plt
import pylab

def plot_graph(fileName):
    with open(fileName) as infile:
        lines = infile.readlines()
    toPlot = [tuple(map(float, line.split(None))) for line in lines]
    xs, ys, colors = zip(*toPlot)

    # uncategorized
    plt.scatter(xs, ys)
    plt.savefig("output/uncategorized_plot.png")
    plt.show()

    # with labels
    plt.scatter(xs, ys, c=colors, cmap=pylab.cm.cool)
    plt.savefig("output/categorized_plot.png")
    plt.show()

def main():
    plot_graph("output/points.txt")

if __name__=="__main__":
    main()