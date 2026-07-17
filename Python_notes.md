# Python Notes

## 1. List
- list = [1, 2, 3, 4, 5]
- length:
    - len(list)
- get:
    - list[0] == first element
    - list[len(list) - 1] == last element
    - list[0:3] == sublist from 0 to (3 - 1) = 2
    - list[:3] == list[0:3]
    - list[0:] == list[0:(len(list) - 1)]
- append:
    - list.append(x) == add x at the end of the list
- insert:
    - list.insert(index, x) == insert x at the given index
- delete:
    - delete by value: list.remove(x)
    - delete by index: list.pop(index)

## 2. For loop
- for **i** in **range()**:
    - traverse the list, and i is the value of current element in the given range
    - range(x) == int list from 0 to x-1
    - range(a, b) = int list from a to b-1, default difference is 1
    - range(a, b, c) == int list from a to b-1, and the difference between adjacent element is c

- for **i** in **list**: 
    - traverse the list, and i is the value of current element in the given list

## 3. While loop
- while ___:
    - keep cycling until the condition is false

## 4. Tuple
- **immutable** sequence of **ordered** elements
- cannot change/add/delete elements once created
- tuple = (1, 2, 3, 4, 5)
- operations:
    - tuple3 = tuple1 + tuple2
- delete
    - del tuple1

## 5. Dict
- __mutable__ sequence of __unordered__ elements
- key and value
    - key is unique
    - value can be any data type
- dict = {1:"a" , 2:"b", 3:"c"}
- operations
    - find:
    abc
