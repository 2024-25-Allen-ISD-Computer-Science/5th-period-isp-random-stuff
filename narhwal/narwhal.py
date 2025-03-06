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

    closest_points = []

    for point in datapoints:
        to_sqrt = 0

        for i in range(len(input_features)):
            to_sqrt += pow((input_features[i] - point[i]), 2)
        
        distance = math.sqrt(to_sqrt)
        closest_points.append([point, distance])
    
    def by_distance(x):
        return x[1]

    closest_points.sort(key=by_distance)
    first_closest = closest_points[0][0]
    second_closest = closest_points[1][0]    
