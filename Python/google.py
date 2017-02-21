import math

def answer(area):
    # your code here
    result_list = []

    while(area > 0):
        rough_side = math.sqrt(area)
        floor_rough_side = int(rough_side)
        print(floor_rough_side)
        print(floor_rough_side ** 2)
        result_list.append(floor_rough_side ** 2)
        area -= floor_rough_side ** 2
        
    return result_list


printing = answer(12)
print(printing)