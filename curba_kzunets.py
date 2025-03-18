import csv
import numpy as np
import matplotlib.pyplot as plt
import os

# Funcție pentru citirea datelor dintr-un fișier CSV
def read_kuznets_data_no_pandas(file_path):
    with open(file_path, 'r') as file:
        reader = csv.reader(file)
        data = list(reader)  # Convertește cititorul într-o listă de liste
    x_values = [float(value) for value in data[0]]  # Prima linie: valori X (venituri)
    y_values = [float(value) for value in data[1]]  # A doua linie: valori Y (inegalitate)
    return x_values, y_values

# Citirea țării selectate din fișierul "select.txt"
def read_country_from_file(file_path="select.txt"):
    with open(file_path, 'r') as file:
        country = file.readline().strip()  # Citirea primului nume de țară
    return country

# Obține directorul scriptului
script_dir = os.path.dirname(os.path.realpath(__file__))

# Fișierele CSV și țările asociate
files_and_countries = {
    "Romania": os.path.join(script_dir, "Kuznets_Romania.csv"),
    "Spania": os.path.join(script_dir, "Kuzents_Spain.csv"),
    "Portugalia": os.path.join(script_dir, "Kuznets_Portugal.csv")
}

script_dir = os.path.dirname(os.path.realpath(__file__))

# Calea completă către fișierul select.txt
select_file = os.path.join(script_dir, "select.txt")

country = read_country_from_file(select_file)

# Verificăm dacă țara citită este validă
if country in files_and_countries:
    # Selectăm fișierul corespunzător
    file_path = files_and_countries[country]
    print(f"Datele vor fi citite din fișierul: {file_path}")
    
    # Citește datele din fișierul CSV asociat țării
    x_values, y_values = read_kuznets_data_no_pandas(file_path)
    
    # Aplică transformările logaritmice
    log_x = np.log(x_values)  # log(x)
    log_x_squared = log_x**2  # log^2(x)

    # Calcularea coeficientilor pentru regresie polinomială de gradul 2
    X = np.column_stack((log_x_squared, log_x, np.ones_like(log_x)))
    y = np.array(y_values)

    # Calcularea coeficientilor folosind formula celor mai mici pătrate
    coefficients = np.linalg.inv(X.T @ X) @ X.T @ y
    a, b, c = coefficients  # Extrage coeficientii

    # Afișează coeficientii
    print(f"Coeficientii calculati sunt:")
    print(f"a = {a}, b = {b}, c = {c}")

    # Generare predicții pe baza modelului (pentru grafic)
    y_pred = a * log_x_squared + b * log_x + c

# Generarea parabolei perfecte pentru comparație
    d, e, f = -0.32, 6, -18  # Coeficienți pentru parabola perfectă
    y_parabola = d * log_x_squared + e * log_x + f

# Calcularea erorii medii pătratice (MSE) pentru comparație
    mse_kuznets = np.mean((y_values - y_pred)**2)
    mse_parabola = np.mean((y_values - y_parabola)**2)
    
# Calcularea diferențelor între parabola perfectă și curba Kuznets
    mse_kuznets_vs_parabola = np.mean((y_pred - y_parabola)**2)

# Calcularea procentului de apropiere
    procent_apropiere = (1 - mse_kuznets_vs_parabola / mse_parabola) * 100

# Plotarea datelor originale, curbei Kuznets și parabolei perfecte pe același grafic
    plt.figure(figsize=(10, 6))
    #plt.scatter(x_values, y_values, color='blue', label='Date originale', alpha=0.7)
    plt.plot(x_values, y_pred, color='red', label=f'Curba Kuznets: y = {a:.2f} log^2(x) + {b:.2f} log(x) + {c:.2f}', linewidth=2)
    plt.plot(x_values, y_parabola, color='green', linestyle='--', label='Parabolă perfectă: y = log^2(x)', linewidth=2)

# Adăugarea detaliilor graficului
    plt.xlabel('Venituri (X)')
    plt.ylabel('Inegalitate (Y)')
    plt.title('Comparație Curba Kuznets vs Parabolă Perfectă')
    plt.text(0.05, 0.95, f'Procentul de apropiere: {procent_apropiere:.2f}%', transform=plt.gca().transAxes, fontsize=12, verticalalignment='top', bbox=dict(facecolor='white', alpha=0.5))
    plt.legend()
    plt.grid(True)
    plt.show()

# Afișarea erorilor



# Afișarea rezultatelor
    print(f"Eroarea medie pătratică între curba Kuznets și parabola perfectă: {mse_kuznets_vs_parabola:.4f}")
    print(f"Procentul de apropiere între parabola perfectă și curba Kuznets: {procent_apropiere:.2f}%")



    print("Țara selectată nu este validă sau nu se află în fișierul select.txt.")
