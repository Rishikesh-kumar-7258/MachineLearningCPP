import numpy as np
import pandas as pd

# Load the data
data = pd.read_csv('house_data.csv')
print(data.head())

# Extract the target variable
y = data['median_house_value']

# Extract the features
X = data.drop('median_house_value', axis=1)

# Split the data into training and test sets
from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Train a linear regression model
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import StandardScaler

def process_data(X_train):
    # remove ocean proximity column
    X_train = X_train.drop('ocean_proximity', axis=1)

    # Fill missing values with the mean of the column
    X_train.fillna(X_train.mean(), inplace=True)

    # Standardize the data
    scaler = StandardScaler()
    X_train = scaler.fit_transform(X_train)

    return X_train

X_train = process_data(X_train)

model = LinearRegression()
model.fit(X_train, y_train)

# Evaluate the model
X_test = process_data(X_test)
predictions = model.predict(X_test)

from sklearn.metrics import mean_squared_error

mse = mean_squared_error(y_test, predictions)
print('Mean Squared Error:', mse)

for i in range(10):
    print(f'Prediction: {predictions[i]}, True Value: {y_test.iloc[i]}')

# print the model coefficients
print(model.coef_)

# [-85503.21815336 -90698.84880311  14905.90644754 -17805.41850057
#   48712.34334124 -43766.49115918  17654.50065911  77194.69946558]

# 202067
# -74473.3
# -82964.9 
# 15759.1
# -17286.4
# 31265.1
# -46654.8
# 38114.5
# 75520