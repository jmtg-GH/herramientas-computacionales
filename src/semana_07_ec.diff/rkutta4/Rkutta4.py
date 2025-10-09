import numpy as np
import matplotlib.pyplot as plt
# from mpl_toolkits.mplot3d import Axes3D

def graficar_atractor_lorenz(nombre_archivo, nombre_pdf="Atractor_Lorenz.pdf"):
    
    
    data = np.loadtxt(nombre_archivo)
        
    t = data[:, 0]
    x = data[:, 1]
    y = data[:, 2]
    z = data[:, 3]

    fig = plt.figure(figsize=(10, 8))
    
    ax = fig.add_subplot(111, projection='3d') 

    ax.plot(x, y, z, lw=0.5, color='darkblue')

    ax.set_xlabel("Componente X")
    ax.set_ylabel("Componente Y")
    ax.set_zlabel("Componente Z")
    ax.set_title(f"Atractor de Lorenz (Runge-Kutta 4)\nTotal de puntos: {len(x)}", fontsize=14)
    
    ax.set_xlim([-25, 25])
    ax.set_ylim([-35, 35])
    ax.set_zlim([0, 50])
    
    ax.view_init(elev=20, azim=120)

    plt.savefig(nombre_pdf, format='pdf')

    plt.show()

graficar_atractor_lorenz("datos_lorenz.txt")