>[!note]
>먼저, 빅오는 점근적 실행 시간을 표기할 때 가장 많이 사용되는 수학적 표기법 중 하나입니다.
>
>점근적 실행 시간이란 입력값 n이 커질 때, 즉 입력값이 무한대를 향할 때 `lim` 함수의 실행 시간의 추이를 의미합니다. 
>
>점근적 실행 시간은 달리 말하면 시간 복잡도라고 하는데, 이의 사전적 정의는 어떤 알고리즘을 수행하는 데 걸리는시간을 설명하는 계산 복잡도를 의미합니다.
> 
>여기서 빅오 표기법은 시간 복잡도의 표기법 중 하나인데, 입력값 `n`에 대해서 실행시간이 `n`에 대한 `다항식`으로 표기 되었을 때 최고차항만을 나타내는데, 계수를 빼고 나타내야 합니다. `4n^2 + 3n + 4`의 시간 복잡도는 `O(n^2)` 가 되는 것이지요.
>
>그럼 빅오의 의미는 즉, `worst case`에 대해서 얼마만큼의 시간이 나오느냐를 `n`에 대한  `다항식(polynomial)`로 나타낸 것입니다.

---

## 시간 복잡도 유형 with Big-Oh

#### 1. **O(1)** - **상수 시간**

- **설명**: 입력 크기(n)에 상관없이 항상 일정한 시간이 걸리는 경우.
- **예시**: 배열에서 특정 인덱스의 요소를 조회하거나 스택의 `push`, `pop` 연산.
- **성능**: 입력 크기가 증가해도 수행 시간이 변하지 않음.
```python
# O(1) 예시: 배열의 첫 번째 요소 접근
arr = [1, 2, 3, 4]
print(arr[0])  # 상수 시간 O(1)
```

#### 2. **O(log n)** - **로그 시간**

- **설명**: 입력 크기가 커질수록 실행 시간이 느리게 증가하는 경우. 주로 입력 크기를 절반씩 줄이는 알고리즘에서 발생.
- **예시**: 이진 탐색, 균형 이진 트리에서 삽입/삭제.
- **성능**: 입력 크기가 커질수록 시간 증가가 느리게 증가함.
```python
# O(log n) 예시: 이진 탐색
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1
```

#### 3. **O(n)** - **선형 시간**

- **설명**: 입력 크기에 비례하여 실행 시간이 증가하는 경우.
- **예시**: 배열에서 모든 요소를 한 번씩 탐색하는 알고리즘 (예: 반복문).
- **성능**: 입력 크기가 커질수록 실행 시간이 동일한 비율로 증가.
```python
# O(n) 예시: 배열 요소의 합 계산
def sum_array(arr):
    total = 0
    for num in arr:
        total += num
    return total
```

#### 4. **O(n log n)** - **선형 로그 시간**

- **설명**: `n`과 `log n`의 곱으로 시간 복잡도가 증가하는 경우. 주로 분할 정복 알고리즘에서 발생.
- **예시**: 합병 정렬(Merge Sort), 퀵 정렬(Quick Sort) (평균 시간 복잡도), 힙 정렬.
- **성능**: 입력 크기가 커질수록 시간이 비교적 빠르게 증가.
```python
# O(n log n) 예시: 병합 정렬
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]
        merge_sort(left)
        merge_sort(right)
        i = j = k = 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1
        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1
        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1
```

#### 5. **O(n^2)** - **이차 시간**

- **설명**: 이중 루프와 같은 구조에서 입력 크기에 대해 제곱으로 시간이 증가하는 경우.
- **예시**: 버블 정렬(Bubble Sort), 삽입 정렬(Insertion Sort), 선택 정렬(Selection Sort).
- **성능**: 입력 크기가 커질수록 시간이 매우 빠르게 증가.
```python
# O(n^2) 예시: 버블 정렬
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
```

### 6. **O(2^n)** - **지수 시간**

- **설명**: 입력 크기가 증가할 때, 실행 시간이 2의 지수 형태로 증가하는 경우. 주로 모든 경우의 수를 탐색하는 알고리즘에서 발생.
- **예시**: 피보나치 수열의 재귀적 구현, 부분 집합 문제.
- **성능**: 입력 크기가 조금만 증가해도 실행 시간이 매우 급격히 증가.
```python
# O(2^n) 예시: 재귀적으로 피보나치 수 계산
def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n-1) + fibonacci(n-2)
```

### 7. **O(n!)** - **팩토리얼 시간**

- **설명**: 입력 크기 n이 증가할 때, 실행 시간이 n!로 증가하는 경우. 주로 순열, 조합과 관련된 문제에서 발생.
- **예시**: 모든 가능한 순열을 생성하는 알고리즘.
- **성능**: 입력 크기가 조금만 커져도 거의 실용적으로 사용하기 어려운 복잡도.
```python
# O(n!) 예시: 모든 순열을 구하는 함수
import itertools

def generate_permutations(arr):
    return list(itertools.permutations(arr))
```

---

>[!important]
>마냥 시간 복잡도가 낮다고 해서 좋은 건 아닙니다. 왜냐하면 알고리즘 세계에서 시간과 공간 측면은 서로 트레이드 오프(trade-off)가 존재하기 때문에, 시간 복잡도가 낮을 때, 공간 복잡도 측면이 너무 높아버리면 이또한 좋지 않은 알고리즘으로 평가 됩니다. 