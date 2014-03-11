"""
Python script to show job scheduling using greedy method
"""


import random

JOB_SIZE = 10

def printJ(jobs):
    print "\n---\t--------\t------"
    print "Job\tDeadline\tProfit"
    print "---\t--------\t------"
    print "\n".join(["%d\t%d\t\t%d" % (k[0], k[1], k[2]) for k in jobs])


def schedule(jobs):
    jobs = sorted(jobs, key=lambda k: k[2], reverse=True)
    printJ(jobs)
    max_deadline_time = max(jobs, key=lambda k: k[1])[1]
    job_schedule = dict((i, 0) for i in range(1, max_deadline_time+1))

    profit = 0
    skipped = []

    for i, j, k in jobs:
        h = j
        while h > 0 and job_schedule[h] is not 0:
            h -= 1
        if h < 1:
            skipped.append(i)
            continue
        job_schedule[h] = i
        profit += k
    return job_schedule, profit, skipped


if __name__ == '__main__':
    jobs = [(k + 1, random.randint(1, 8), random.randint(5, 50)) for k in range(JOB_SIZE)]
    printJ(jobs)
    sched, profit, skip = schedule(jobs)

    print "\n---------\t------"
    print "Time Unit\tJob Id"
    print "---------\t------"
    for k, v in sched.iteritems():
        print k, "\t\t", v
    print "Total profit : ", profit
    print "Job Skipped : ", skip
