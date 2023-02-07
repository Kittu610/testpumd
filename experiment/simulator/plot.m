import numpy as np
import matplotlib.pyplot as plt

# Load data from external file
data = np.loadtxt('output.dat')

# Split data into x, y, and z arrays
x = data[:,0]
y = data[:,1]
z = data[:,2]

# Plot data
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(x, y, z)
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('Coordinates Plot')
plt.show()

