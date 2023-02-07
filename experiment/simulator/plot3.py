import numpy as np
import matplotlib.pyplot as plt

# Load the data from the output file
data = np.loadtxt("output.dat")

# Extract the velocity data from the columns
vx = data[:, 3]
vy = data[:, 4]
vz = data[:, 5]

# Plot the velocities
plt.figure(figsize=(10, 5))
plt.subplot(131)
plt.hist(vx, bins=50)
plt.xlabel("vx")

plt.subplot(132)
plt.hist(vy, bins=50)
plt.xlabel("vy")

plt.subplot(133)
plt.hist(vz, bins=50)
plt.xlabel("vz")

plt.tight_layout()
plt.show()

