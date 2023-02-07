import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('output.dat')
time = data[:,0]
rx = data[:,1]
ry = data[:,2]
rz = data[:,3]
vx = data[:,4]
vy = data[:,5]
vz = data[:,6]

plt.figure(figsize=(10, 6))
plt.plot(time, rx, label='rx')
plt.plot(time, ry, label='ry')
plt.plot(time, rz, label='rz')
plt.legend()
plt.xlabel('Time')
plt.ylabel('Position')
plt.title('Position of particles over time')
plt.show()

plt.figure(figsize=(10, 6))
plt.plot(time, vx, label='vx')
plt.plot(time, vy, label='vy')
plt.plot(time, vz, label='vz')
plt.legend()
plt.xlabel('Time')
plt.ylabel('Velocity')
plt.title('Velocity of particles over time')
plt.show()

