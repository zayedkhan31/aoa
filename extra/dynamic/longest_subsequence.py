def lcs_dynamic(X, Y):
    C = [[0 for i in xrange(len(Y))] for j in xrange(len(X))]
    for i in xrange(len(X)):
        C[i][0] = 0
    for j in xrange(len(Y)):
        C[0][j] = 0
    for i in xrange(0, len(X)):
        for j in xrange(0, len(Y)):
            if X[i] == Y[j]:
                C[i][j] = (0 if i - 1 < 0 or j - 1 < 0 
                        else C[i - 1][j - 1]) + 1
            elif C[i - 1][j] >= C[i][j - 1]:
                C[i][j] = C[i - 1][j] if i - 1 > 0 else 0
            else:
                C[i][j] = C[i][j - 1] if j - 1 > 0 else 0
    return C

def lcs_recurse(X, Y, i, j, lst, count):
    count += 1
    new_list = [x for x in lst]
    #print new_list
    if i == -1 or j == -1:
        return new_list, count
    elif X[i] == Y[j]:
        new_list.append(X[i])
        return lcs_recurse(X, Y, i - 1, j - 1, new_list, count)
    else:
        lst1, count1 = lcs_recurse(X, Y, i - 1, j, new_list, count)
        lst2, count2 = lcs_recurse(X, Y, i, j - 1, new_list, count)
        if len(lst1) > len(lst2):
            return lst1, count1 + count2 
        else:
            return lst2, count2 + count1

if __name__ == '__main__':
    #X = ['A', 'B', 'C', 'B', 'D', 'A', 'B']
    #Y = ['B', 'D', 'C', 'A', 'B', 'A']
    X = ['A', 'B', 'C', 'B', 'D', 'A', 'B', 'C', 'D']
    Y = ['B', 'D', 'C', 'A', 'B', 'A', 'C', 'D', 'C']
    D, C = lcs_recurse(X, Y, len(X) - 1, len(Y) - 1, [], 0)
    print "\n".join([str(v) for v in lcs_dynamic(X, Y)])
    #print D[::-1], C
