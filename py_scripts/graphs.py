import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import curve_fit
import re

def model(x, b):
    return 4*((b / 2) * x**2 - (1 / 6) * x**3)/b**4 

def linear_regression(x, y):
    n = len(x)

    x_mean = np.mean(x)
    y_mean = np.mean(y)

    m = (np.sum(x * y) - n * x_mean * y_mean) / (np.sum(x ** 2) - n * x_mean ** 2)
    b = y_mean - m * x_mean


    residuals = y - (m * x + b)

    SE_m = np.sqrt(np.sum(residuals ** 2) / (n - 2)) / np.sqrt(np.sum((x - x_mean) ** 2))
    SE_b = SE_m * np.sqrt(np.mean(x ** 2))

    return m, b, SE_m, SE_b

def cut(n_arr,data_arr):
    for i in range(len(data_arr) - 1, -1, -1):
        if data_arr[i] != 0:
            return n_arr[:i + 1], data_arr[:i + 1]  
    return np.array([]),np.array([])

file_path = "data/tests/data2024-10-05_04-48-07.csv"
df = pd.read_csv(file_path)
print(df)

data = {}
for column in df.columns:
    data[column] = df[column].to_numpy()

plt.rcParams.update({'font.size': 11})

fig, axs = plt.subplots(2, 3, figsize=(20, 10))

titles = np.array([key for key in data.keys() if key != 'N'])
colors = ['blue', 'orange', 'green', 'red', 'cyan']
markers = ['o', '>', '<', '^', 's']

for i, title in enumerate(titles):

    num, data_cutted=cut(data['N'], data[title])

    num_to_center=num[:len(num)//2]
    data_to_center=data_cutted[:len(data_cutted)//2]
    if title=='DD':
        popt, pcov = curve_fit(model, num_to_center, data_to_center)
        b_optimal = popt[0]
        y_fit = model(num_to_center, b_optimal)
        axs[i // 3, i % 3].plot(num_to_center, y_fit, lw=2, 
                    label=r'Appox in $\frac{4}{b^4}\left( \frac{bx^2}{2} - \frac{x^3}{6} \right)$' + '\n' 
                    + f'b={b_optimal:.2f}', color=colors[(i+1)%len(colors)])

    if title in ['BD','PD', 'UD']:
        k,b,dk,db=linear_regression(num, data_cutted)
        axs[i // 3, i % 3].plot(num, [k * x + b for x in num], lw=2, label=f'slope = '
                                            f'{k:.5f}' + r'$\pm$' + f'{dk:.5f} \n'
                                            f'bias={b:.5f}' + r'$\pm$' +
                                            f'{db:.5f}', color=colors[(i+1)%len(colors)])

    axs[i // 3, i % 3].scatter(num, data_cutted, marker=markers[i], color=colors[i])
    axs[i // 3, i % 3].set_title(title + '(N)')
    axs[i // 3, i % 3].grid(True)
    axs[i // 3, i % 3].legend()

# долбанем еще логарифм
num, data_cutted=cut(data['N'], data['DD'])
num_to_center=num[:len(num)//2]
data_to_center=data_cutted[:len(data_cutted)//2]
if title=='DD':
    popt, pcov = curve_fit(model, num_to_center, data_to_center)
    b_optimal = popt[0]
    y_fit = model(num_to_center, b_optimal)
    axs[1, 2].plot(num_to_center, y_fit, lw=2, 
                   label=r'Appox in $\frac{4}{b^4}\left( \frac{bx^2}{2} - \frac{x^3}{6} \right)$'+ '\n' 
                   + f'b={b_optimal:.2f}', color=colors[(i+1)%len(colors)])

axs[1, 2].scatter(num, data_cutted, marker=markers[i], color=colors[i])
axs[1, 2].set_title('DD in logs' + '(N)')
axs[1, 2].set_xscale('log')
axs[1, 2].set_yscale('log')
axs[1, 2].grid(True)
axs[1, 2].legend()

match = re.search(r'data(\d{4}-\d{2}-\d{2}_\d{2}-\d{2}-\d{2})\.csv', file_path)
plt.savefig("data/charts/graph" + match.group(1) + ".png", format='png', dpi=300)
plt.tight_layout()
plt.show()
