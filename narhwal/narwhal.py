import math
import random

datapoints = [ # features, output, reward
    [1, 2, 7, 13, 18],
    [2, 5, 11, 17, 19],
    [7, 6, 12, 14, 21]
]

input_features = [8, 9, 14] # features

def narwhal(input_features, datapoints_old): 
    datapoints = datapoints_old
    combined = []
    for th in datapoints:
        combined += th
    combined += input_features
    maxc = max(th)
    minc = min(th)

    for j in range(len(datapoints)):
        for i in range(len(datapoints[j])):
            datapoints[j][i] = (datapoints[j][i] - minc) / (maxc - minc)
    
