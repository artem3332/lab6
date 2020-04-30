import numpy as np
# import pylab
import numpy
import matplotlib.pyplot as plt
data = np.loadtxt("a.doc)
plt.plot(data[:, 0], data[:, 1])
# plt.show()
def makeData():
    x = numpy.arange(-3, 7, 0.1)
    y = numpy.arange(-3, 7, 0.1)
    xgrid, ygrid = numpy.meshgrid(x, y)
    zgrid = (xgrid * xgrid + xgrid * ygrid - 10 * xgrid + ygrid * ygrid - 5 * ygrid + 4)
    return xgrid, ygrid, zgrid

# if __name__ == '__main__':
x, y, z = makeData()
    # pylab.contour(x, y, z)
plt.contour(x, y, z, 50)
# pylab.show()
plt.show()