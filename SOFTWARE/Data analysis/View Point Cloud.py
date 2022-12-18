# This is a sample Python script.
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import csv
# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
from mpl_toolkits.mplot3d import axes3d



# Press the green button in the gutter to run the script.

colums = ["X","Y","Z"]
df = pd.read_csv("data.csv",names=colums,sep = ',')

ax = plt.axes(projection="3d")
x_data = np.random.randint(0, 50, (500,))
y_data = np.random.randint(0, 50, (500,))
z_data = np.random.randint(0, 50, (500,))
ax.scatter(df.X,df.Y,df.Z)
plt.show()
print("Test")
print("Test")
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
