import numpy as np
import pandas as pd
import pylab as plt
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error


def show(n):
    x = data[n].reshape(-1, 1)
    y = target.reshape(-1, 1)
    lg.fit(x, y)
    y_predict = lg.predict(x)
    error = mean_squared_error(y, y_predict)
    print("误差为：", error)
    plt.scatter(x, y, color='red', label="sample data", linewidth=2)
    plt.plot(x, y_predict, color='green', label="fitting line", linewidth=2)
    plt.legend(loc='lower right')
    plt.show()


lg = LinearRegression()
data_url = "http://lib.stat.cmu.edu/datasets/boston"
raw_df = pd.read_csv(data_url, sep='\s+', skiprows=22, header=None)
data = np.hstack([raw_df.values[::2, :], raw_df.values[1::2, :2]])
target = raw_df.values[1::2, 2]
data = data.T
title = ['CRIM', 'ZN', 'INDUS', 'CHAS', 'NOX', 'RM', 'AGE', 'DIS', 'RAD', 'TAX', 'PTRATIO', 'B', 'LSTAT']
for i in range(13):
    plt.scatter(data[i], target)
    plt.title(title[i])
    plt.show()
show(0)
show(5)
show(12)
