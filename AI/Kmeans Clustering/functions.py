import numpy as np
import statistics

def assignments (data, centroids, k):
    #List to store the closest centroid to each line
    nearest_centroid_list = []
    #Rows in data
    for j in range(data.shape[0]):
        distances = []                    #Check how close each centroid is
        line = data[j,0:data.shape[1]-1]  #Pull current line
        #Number of clusters
        for i in range(k):              
            centroid = centroids[i]
            sumOfSquares = 0
            #Check how close the current centroid is to the point of interest
            for x in range(data.shape[1]-1):
                sumOfSquares += (centroid[x] - line[x])**2
            distances.append(sumOfSquares**.5)
        nearest_centroid_list.append(distances.index(min(distances)))
    return np.asarray(nearest_centroid_list)

def test (data, centroids, k):
    correct = 0
    cluster_assignments = assignments(data, centroids, k)
    for j in range(k):
        cluster_group = np.where(cluster_assignments == j)[0]
        for x in cluster_group:
            if data[x][data.shape[1]-1] == round(centroids[j][data.shape[1]-1]):
                correct += 1
    print(correct)
        
def train(data, centroids, k):
    old_centroids = None
    while np.array_equal(centroids, old_centroids, equal_nan=True) == False:
        #Copies for checking later
        old_centroids = centroids.copy()
        #Calculates distances from each vector to each point and returns a list with the assignments
        cluster_assignments = assignments(data, centroids, k)
        #Loop updates the vector's values
        for j in range(k):
            grouping = np.where(cluster_assignments == j)[0]
            if grouping.size == 0:
                continue
            else:
                updated_vals = []
                #Feature column
                for i in range(data.shape[1]):
                    column_sum = 0
                    for x in grouping:
                        #Sum the data for that column
                        column_sum += data[x][i]
                    #Add the average for the current feature to the update vector
                    if i == data.shape[1]-1:
                        updated_vals.append(statistics.mode(data[grouping,i]))
                    else:
                        updated_vals.append(column_sum / len(grouping))
                centroids[j] = updated_vals
        
    return centroids
