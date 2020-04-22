import numpy as np
import pylab
import numpy
import matplotlib.pyplot as plt
data = np.loadtxt("py.dat")
plt.plot(data[:, 0], data[:, 1])
plt.show()
def makeData():
    x = numpy.arange(-10, 20, 0.1)
    y = numpy.arange(-10, 10, 0.1)
    xgrid, ygrid = numpy.meshgrid(x, y)
    zgrid = (xgrid * xgrid + xgrid * ygrid - 10 * xgrid + ygrid * ygrid - 5 * ygrid + 4)
    return xgrid, ygrid, zgrid

if __name__ == '__main__':
    x, y, z = makeData()
    pylab.contour(x, y, z)
pylab.show()
