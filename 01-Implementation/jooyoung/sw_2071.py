import sys

sys.stdin = open("../../../../sds sw/sw samsung/input_2071.txt", "r")

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    arr = list(map(int, input().split()))
    result = sum(i for i in arr)
    answer = int(round(result / len(arr), 0))
    print("#{} {}".format(test_case, answer))
