# Deschidem fisierul text si citim datele
file_path = 'intrare.txt'

with open(file_path, 'r') as file:
    # Citim prima linie pentru a prelua numele tarilor
    header = file.readline().strip().split()
    tara1, tara2 = header[0], header[1]

    # Citim coeficientii pentru fiecare tara
    date_coeficienti = []
    for linie in file:
        coef_tara1, coef_tara2 = map(float, linie.split())
        date_coeficienti.append((coef_tara1, coef_tara2))

# Afisam datele pentru verificare
print(f"Coeficientii pentru {tara1} si {tara2} sunt:")
for idx, (c1, c2) in enumerate(date_coeficienti, 1):
    print(f"Linia {idx}: {tara1} = {c1}, {tara2} = {c2}")
