*/kyu 4 


def sum_for_list(lst):
    def simple_abs(num): 
        return -num if num < 0 else num 
    abs_value_lst = []
    for i in lst: 
        value =  simple_abs(i)
        abs_value_lst.append(value)
    
    largest = max(abs_value_lst)
    p = []
    count = 2
    
    while count < largest: 
        isprime = True
        
        for x in range (2, int((count / 2) + 1)): 
            if count % x == 0: 
                isprime = False
                break
        if isprime: 
            p.append(count)
        count += 1
    sum_list = []
    sum = 0 
    counter = 0 
    
    for j in p: 
        sum = 0 
        counter = 0 
        for i in lst: 
            if not i % j: 
                sum += i 
                counter += 1 
        if counter: 
            sum_list.append([j, sum])
    return sum_list