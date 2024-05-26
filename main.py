from sklearn.linear_model import LinearRegression
import numpy as np

# Create some data
X = np.array([[1, 1], [1, 2], [2, 2], [2, 3]])
X = np.linalg.inv(X.T.dot(X)).dot(X.T)