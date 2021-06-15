import numpy as np

def check(line, model, index):
    tree_index = None
    for x in range(len(model[:,0])):
        if model[x][0] == index:
            tree_index = x
            break
    if tree_index != None:
        node = model[tree_index]
        index = int(node[0])
        avg = node[1]
        attr = int(node[2])
        if avg == -1:
            label = int(node[2])
            if label == line[len(line)-1]:
                #print("Its a match")
                #print(line)
                #print(node)
                #print()
                return 1
        elif line[attr] < avg:
            return check(line, model, index*2)
        elif line[attr] > avg:
            return check(line, model, (index*2)+1)
    return 0
    
    
def test(data, model):
    
    #Decision tree format                             #Data format
    #[0] = index in tree                              #[0] - [3] attributes
    #[1] = average or -1 if terminal                  #[4] class label
    #[2] = attr split on or class label if terminal

    num_correct = 0
    model = np.array(model)
    for line in data:
        num_correct += check(line, model, 1)
        
    print(num_correct)
        
            
def train(data, tree, tree_index):
    class_index = data.shape[1]-1
    if len(np.unique(data[:,class_index])) == 1:
        tree.append([tree_index, -1, np.unique(data[:,class_index])[0]])
        return
    else:
        indices = np.argsort(data,axis=0)
        potential_splits, gain, max_gain, prev_val =  0, 0, 0, None
        split_gain, split_index, split_average, split_attr, split_curr, split_prev = 0, 0, 0, 0, 0, 0

        #Loop to find the potential split points
        for attr in range(data.shape[1]):
            for index in indices[:,attr]:
                curr_val = val(index, data, attr)
                if prev_val == None:
                    prev_index = index
                    prev_val = curr_val

                #Signifies a split point
                if curr_val > prev_val: 
                    potential_splits += 1
                    average = (curr_val + prev_val) / 2
                    lr_set = [left_data(index, data, indices, attr),right_data(index, data, indices, attr)]
                    lr_prob = [set_prob(lr_set[0], data), set_prob(lr_set[1], data)]
                    for i in range(len(lr_set)):
                        for j in range(len(np.unique(lr_set[i][:,class_index]))):
                            if lr_set[i].shape[0] == 0:
                                gain = 0
                            elif prob_given(j,lr_set[i]) != 0:
                                prob = prob_given(j, lr_set[i])
                                ic = -np.log2(prob)
                                gain += prob * ic
                        gain = gain * lr_prob[i]
                        split_gain += gain
                    #Signifies new maximum information gain from current split
                    if split_gain > max_gain:
                        max_gain = split_gain
                        split_attr = attr
                        split_index = index
                        split_curr = curr_val
                        split_prev = prev_val
                        split_average = average

                #Reset for next potential split
                split_gain, gain = 0, 0
                prev_index = index
                prev_val = val(prev_index, data, attr)

        if potential_splits == 0:
            #Return most likely class label
            prob = [prob_given(0, data), prob_given(1, data), prob_given(2, data)]
            index_of_max = np.where(prob == np.max(prob))
            tree.append([tree_index, -1, prob[index_of_max]])
        else:
            tree.append([tree_index, split_average,split_attr])
            left = left_data(split_index, data, indices, split_attr)
            right = right_data(split_index, data, indices, split_attr)
            if left.shape[0] == 0:
                return
            if right.shape[0] == 0:
                return
            train(right, tree, (tree_index*2)+1)
            train(left, tree, tree_index*2)
        
val = lambda index, data, attr : data[index,:][attr]
left_data = lambda index, data, indices, attr : data[indices[:,attr][0:np.where(indices[:,attr] == index)[0][0]],:]
right_data = lambda index, data, indices, attr : data[indices[:,attr][np.where(indices[:,attr] == index)[0][0]:],:]
set_prob = lambda split_set, data: len(split_set[:,data.shape[1]-1])/len(data[:,data.shape[1]-1])
prob_given = lambda j, data: len(np.where(data[:,data.shape[1]-1] == j)[0])/(data.shape[0]) 
