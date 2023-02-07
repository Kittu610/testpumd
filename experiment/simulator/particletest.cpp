#include <iostream>
#include <cmath>
#include <fstream>

const double dt = 2;  // time step
const double kB = 1.0;     // Boltzmann constant
const int N = 10;        // number of particles
const double L = 3;    // size of the simulation box

double rx[N], ry[N], rz[N];   // position vectors of the particles
double vx[N], vy[N], vz[N];   // velocity vectors of the particles
double fx[N], fy[N], fz[N];   // force vectors on the particles
double T = 300.0;             // temperature of the system
double t = 0.0;               // current simulation time

// function to calculate the forces between particles i and j
void calc_forces(int i, int j)
{
    double dx = rx[j] - rx[i];
    double dy = ry[j] - ry[i];
    double dz = rz[j] - rz[i];
    double dr = sqrt(dx*dx + dy*dy + dz*dz);
    double f = 24.0 * (2.0 / pow(dr, 13) - 1.0 / pow(dr, 7));
    double fxi = f * dx / dr;
    double fyi = f * dy / dr;
    double fzi = f * dz / dr;
    fx[i] += fxi;
    fy[i] += fyi;
    fz[i] += fzi;
    fx[j] -= fxi;
    fy[j] -= fyi;
    fz[j] -= fzi;
}

// function to calculate the velocities and positions of the particles
void update_particles()
{
    // Verlet integration
    for (int i = 0; i < N; i++) {
        double rx_temp = rx[i] + vx[i] * dt + 0.5 * fx[i] * dt * dt;
        double ry_temp = ry[i] + vy[i] * dt + 0.5 * fy[i] * dt * dt;
        double rz_temp = rz[i] + vz[i] * dt + 0.5 * fz[i] * dt * dt;
        vx[i] += 0.5 * fx[i] * dt;
        vy[i] += 0.5 * fy[i] * dt;
        vz[i] += 0.5 * fz[i] * dt;
        rx[i] = rx_temp;
        ry[i] = ry_temp;
        rz[i] = rz_temp;
    }
    // calculate forces
    for (int i = 0; i < N; i++) {
        fx[i] = 0;
        fy[i] = 0;
        fz[i] = 0;
    for (int j = i+1; j < N; j++) {
        calc_forces(i, j);
    }
}
// update velocities
for (int i = 0; i < N; i++) {
    vx[i] += 0.5 * fx[i] * dt;
    vy[i] += 0.5 * fy[i] * dt;
    vz[i] += 0.5 * fz[i] * dt;
}
}

int main()
{
// initialize the position, velocity, and force vectors
for (int i = 0; i < N; i++) {
rx[i] = L * (rand() / double(RAND_MAX));
ry[i] = L * (rand() / double(RAND_MAX));
rz[i] = L * (rand() / double(RAND_MAX));
vx[i] = sqrt(kB * T / 1.0) * (2.0 * (rand() / double(RAND_MAX)) - 1.0);
vy[i] = sqrt(kB * T / 1.0) * (2.0 * (rand() / double(RAND_MAX)) - 1.0);
vz[i] = sqrt(kB * T / 1.0) * (2.0 * (rand() / double(RAND_MAX)) - 1.0);
}
// create an output file
std::ofstream output_file;
output_file.open("output.dat");
// simulate the system
while (t < 1000.0) {
update_particles();
// write the positions of the particles to the output file
for (int i = 0; i < N; i++) {
output_file << rx[i] << " " << ry[i] << " " << rz[i] << " " << vx[i] << " " << vy[i] << " " << vz[i] << " " << fx[i] << " " << fy[i] << " " << fz[i] << std::endl;
}
t += dt;
}
// close the output file
output_file.close();
return 0;
}
