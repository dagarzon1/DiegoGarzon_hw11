import numpy as np
import matplotlib.pyplot as plt

data=np.loadtxt("tray.txt")

plt.scatter(data[:,2],data[:,0], label="x vs t")
plt.xlabel("tiempo(s)")
plt.ylabel("posicion(m)")
plt.title("Posicion vs tiempo")
plt.legend()
plt.savefig("pos.png")
plt.clf()

plt.scatter(data[:,2],data[:,1], label="v vs t")
plt.xlabel("tiempo(s)")
plt.ylabel("velocidad(m/s)")
plt.title("Velocidad vs tiempo")
plt.legend()
plt.savefig("vel.png")
plt.clf()

plt.scatter(data[:,0],data[:,1], label="v vs x")
plt.xlabel("posicion(m)")
plt.ylabel("velocidad(m/s)")
plt.title("Velocidad vs posicion")
plt.legend()
plt.savefig("phase.png")
plt.clf()


