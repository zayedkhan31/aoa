import sys

def calculate(vertexes, edges, stages, i, j):
    if stages[i] == stages[j]:
        return 0, ''
    stage_i_vertexes = [k for k, v in stages.iteritems() if v == (stages[i] + 1)]
    min_u = []
    for v in stage_i_vertexes:
        if v not in edges[i]:
            continue
        next_min, nodes = calculate(vertexes, edges, stages, v, j)
        min_u.append((edges[i][v] + next_min, nodes + v,))
    return min(min_u)


def calculate_dynamic(vertexes, edges, stages, S, T):
    all_stages = sorted(set([v for k, v in stages.iteritems()]), reverse=True)
    cost = {}
    for i in all_stages:
        cost[i] = dict((E, sys.maxint) for E, v in stages.iteritems() if v is i)
    start_stage = stages[T]
    end_stage = stages[S]
    cost[start_stage][T] = 0
    print "\n".join(["%s: %s" % (str(k), str(v)) for k, v in cost.iteritems()])
    for i in xrange(start_stage - 1 , end_stage - 1, -1):
        prev_stage = i + 1
        for j in cost[i].keys():
            for k in cost[prev_stage].keys():
                if k not in edges[j].keys():
                    continue
                cost[i][j] = min(cost[i][j], edges[j][k] + cost[prev_stage][k])
    print "\n".join(["%s: %s" % (str(k), str(v)) for k, v in cost.iteritems()])

if __name__ == '__main__':
    vertexes = {'A', 'B', 'C', 'D', 'E', 'F'}
    edges = {
                'A': {'B': 1, 'C': 2}, 
                'B': {'D': 2, 'E': 3}, 
                'C': {'E': 5}, 
                'D': {'F': 4}, 
                'E': {'F': 2}, 
                'F': {}
            }
    stages = {'A': 1, 'B': 2, 'C': 2, 'D': 3, 'E': 3, 'F': 4}

    stage_size = 4
    print calculate(vertexes, edges, stages, 'A', 'F')
    calculate_dynamic(vertexes, edges, stages, 'A', 'F')
