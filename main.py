import numpy as np

# Create some data
X = np.array([[1, 5, 6], [1, 11, 13]])
y = np.array([5, 6])

theta = np.linalg.inv(X.T.dot(X)).dot(X.T).dot(y)

print(theta)