import sys
import random


def findMedian1(v1, v2):
    v = []
    i = 0
    j = 0
    vlen = len(v1)+len(v2)
    while i < len(v1) and j < len(v2):
        if v1[i] < v2[j]:
            v.append(v1[i])
            i += 1
        else:
            v.append(v2[j])
            j += 1
    v += v1[i:]
    v += v2[j:]
    if vlen % 2 == 1 or vlen == 1:
        return v[vlen//2]
    else:
        return (v[vlen//2]+v[vlen//2 -1])/2


def findKth(v1, v2, k):
    len1, len2 = len(v1), len(v2)
    if len1 == 0:
        return v2[k-1]
    if len2 == 0:
        return v1[k-1]
    if k == 1:
        return min(v1[0], v2[0])

    key1, key2 = sys.maxsize, sys.maxsize
    if k//2 - 1 < len1:
        key1 = v1[k//2 - 1]
    if k//2 - 1 < len2:
        key2 = v2[k//2 - 1]
    if key1 < key2:
        return findKth(v1[k//2:], v2, k - k//2)
    else:
        return findKth(v1, v2[k//2:], k - k//2)

def findMedian2(v1, v2):
    len1, len2 = len(v1), len(v2)
    if (len1+len2)% 2 == 1:
        return findKth(v1, v2, (len1+len2)//2+1)
    else:
        return (findKth(v1, v2, (len1+len2)//2) + findKth(v1, v2, (len1+len2)//2+1))/2

def stressTesting():
    while True:
        a = random.randint(50, 100)
        b = random.randint(2, 50)
        L1, L2 = [], []
        for i in range(a):
            L1.append(random.randrange(1, a))
        for i in range(b):
            L2.append(random.randrange(1, b))
        L1.sort()
        L2.sort()
        print(L1)
        print(L2)
        print(findMedian1(L1, L2))
        print(findMedian2(L1, L2))
        if findMedian1(L1, L2) != findMedian2(L1, L2):
            break

stressTesting()
