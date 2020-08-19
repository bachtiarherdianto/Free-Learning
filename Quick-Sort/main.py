'''QUICK SHORT ALGORITHM'''

# def sort(array=[12, 4, 5, 6, 7, 3, 1, 15]):
#     less = []
#     equal = []
#     greater = []
#     if len(array) > 1:
#         pivot = array[0]
#         for i in array:
#             if i < pivot:
#                 less.append(i)
#             elif i == pivot:
#                 equal.append(i)
#             elif i > pivot:
#                 greater.append(i)
#         return sort(less) + equal + sort(greater)
#     else:
#         return array
#
# print(sort([12, 4, 5, 6, 7, 3, 1, 15]))